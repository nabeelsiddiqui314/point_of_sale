#ifndef CAMERASCANNER_H
#define CAMERASCANNER_H

#include <QObject>
#include "Scanner.h"

#include <thread>
#include <mutex>
#include <condition_variable>

namespace pybind11 {
    class scoped_interpreter;
    class gil_scoped_release;
}

class CameraScanner : public QObject, public Scanner {
    Q_OBJECT
public:
    CameraScanner();
    ~CameraScanner();
public:
    void scan() override;
    void stop() override;
private:
    void runScannerScript();
private:
    std::unique_ptr<pybind11::scoped_interpreter> m_interpreter;
    std::unique_ptr<pybind11::gil_scoped_release> m_release;
    std::thread m_thread;

    bool m_running = true;
    std::atomic<bool> m_paused {false};

    std::mutex m_mutex;
    std::condition_variable m_pauseCV;

};

#endif // CAMERASCANNER_H
