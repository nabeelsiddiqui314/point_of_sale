#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "ScannerDialog/scandialog.h"
#include "billDialog/billdialog.h"
#include "addItems/additem.h"


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
    billDialog bill;
    bill.setModal(true);
    bill.exec();

}


void MainWindow::on_scanButton_clicked()
{
    scanDialog scan;
    scan.setModal(true);
    scan.exec();
}


void MainWindow::on_pushButton_clicked()
{
    addItem itemDialog;
    itemDialog.setModal(true);
    itemDialog.exec();

}

