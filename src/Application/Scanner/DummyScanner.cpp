#include "DummyScanner.h"
#include "./ui_DummyScanner.h"

#include <QMessageBox>
#include <QCloseEvent>

DummyScanner::DummyScanner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DummyScanner) {
    ui->setupUi(this);

    connect(ui->okButton, &QAbstractButton::released, this, &DummyScanner::onOkClicked);
    connect(ui->cancelButton, &QAbstractButton::released, this, &DummyScanner::onCancelClicked);
}

void DummyScanner::scan() {
    show();
}

void DummyScanner::stop() {
    emit _signals.scannerStopped();
    hide();
}

void DummyScanner::closeEvent(QCloseEvent* event) {
    emit _signals.scannerStopped();
    event->accept();
}

void DummyScanner::onOkClicked() {
    QString input = ui->codeEdit->text();

    if (!input.isEmpty()) {
        emit _signals.codeScanned(input);
    }
}

void DummyScanner::onCancelClicked() {
    emit _signals.scannerStopped();
    hide();
}

DummyScanner::~DummyScanner() {
    delete ui;
}
