#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ProductManagementForm.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->tabWidget->addTab(new ProductManagementForm(), "Products");
}

MainWindow::~MainWindow() {
    delete ui;
}
