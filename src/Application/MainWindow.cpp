#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "ScannerDialog/scandialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_proceedButton_clicked()
{
    scanDialog scan;
    scan.setModal(true);
    scan.exec();
}

