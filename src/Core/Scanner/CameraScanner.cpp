#include <pybind11/embed.h>

#include "CameraScanner.h"
#include <string>

namespace py = pybind11;

CameraScanner::CameraScanner()
    : m_interpreter(std::make_unique<py::scoped_interpreter>()),
      m_release(std::make_unique<py::gil_scoped_release>()),
      m_thread(&CameraScanner::runScannerScript, this) {
}

void CameraScanner::scan() {
    m_paused = false;
    m_pauseCV.notify_one();
}

void CameraScanner::stop() {
    if (!m_paused.load()) {
        emit _signals.scannerStopped();
    }
    m_paused = true;
}

void CameraScanner::runScannerScript() {
    py::gil_scoped_acquire acquire;
    auto module = py::module_::import("scanner");

    while (m_running) {
        auto result = module.attr("captureBarcode")().cast<std::string>();
        QString scannedCode = QString::fromStdString(result);

        if (scannedCode != "0") {
            emit _signals.codeScanned(scannedCode);

            std::unique_lock<std::mutex> lock(m_mutex);
            m_pauseCV.wait(lock);
        }
        else if (m_paused.load()) {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_pauseCV.wait(lock);
        }
    }
}

CameraScanner::~CameraScanner() {
    m_pauseCV.notify_one();
    m_running = false;
    m_thread.join();
}
