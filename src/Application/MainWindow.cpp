#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ProductManagementForm.h"
#include <Scanner/CameraScanner.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    m_scanner = new CameraScanner();
    m_scanner->stop();
    ui->tabWidget->addTab(new ProductManagementForm(m_scanner), "Products");
}

MainWindow::~MainWindow() {
    delete m_scanner;
    delete ui;
}
