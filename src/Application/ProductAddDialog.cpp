#include "ProductAddDialog.h"
#include "ui_ProductAddDialog.h"

#include <QMessageBox>
#include <QCloseEvent>

#include <Scanner/Scanner.h>

ProductAddDialog::ProductAddDialog(Scanner* scanner, QWidget *parent)
    : QDialog(parent),
      ui(new Ui::ProductAddDialog),
      m_scanner(scanner) {
    ui->setupUi(this);

    connect(ui->okButton, &QAbstractButton::released, this, &ProductAddDialog::onOkClicked);
    connect(ui->cancelButton, &QAbstractButton::released, this, &ProductAddDialog::onCancelClicked);
    connect(ui->scanButton, &QAbstractButton::released, this, [&](){
        m_scanner->scan();
    });
}

void ProductAddDialog::showEvent(QShowEvent*) {
    m_scanner->scan();
    connect(&m_scanner->_signals, &ScannerSignals::codeScanned, this, &ProductAddDialog::onCodeScanned);
}

void ProductAddDialog::hideEvent(QHideEvent*) {
    m_scanner->stop();
    disconnect(&m_scanner->_signals, &ScannerSignals::codeScanned, this, &ProductAddDialog::onCodeScanned);
}

void ProductAddDialog::closeEvent(QCloseEvent* event) {
    m_scanner->stop();
    clear();

    event->accept();
}

void ProductAddDialog::clear() {
    auto lineEdits = findChildren<QLineEdit*>();
    for (auto& lineEdit : lineEdits) {
        lineEdit->clear();
    }
}

void ProductAddDialog::onOkClicked() {
    auto lineEdits = findChildren<QLineEdit*>();
    for (auto& lineEdit : lineEdits) {
        if (lineEdit->text().isEmpty()) {
            QMessageBox messageBox;
            messageBox.critical(0, "Error", "Field(s) are empty");
            messageBox.setFixedSize(500,200);
            return;
        }
    }

    QString priceText = ui->priceEdit->text();
    bool isNumber;
    int price = priceText.toInt(&isNumber);

    if (!isNumber) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Invalid value for price");
        messageBox.setFixedSize(500,200);
        return;
    }

    ID id = ui->idEdit->text();

    if (m_database.doesProductExist(id)) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "ID already in use");
        messageBox.setFixedSize(500,200);
        return;
    }

    QString name = ui->nameEdit->text();

    m_database.insertProduct(id, {name, price});

    emit productAdded();
    hide();
    clear();
}

void ProductAddDialog::onCancelClicked() {
    m_scanner->stop();
    hide();
    clear();
}

void ProductAddDialog::onCodeScanned(QString code) {
    ui->idEdit->setText(code);
}

ProductAddDialog::~ProductAddDialog() {
    delete ui;
}
