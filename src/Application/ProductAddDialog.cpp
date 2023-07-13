#include "ProductAddDialog.h"
#include "ui_ProductAddDialog.h"

#include <QMessageBox>

ProductAddDialog::ProductAddDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::ProductAddDialog) {
    ui->setupUi(this);

    connect(ui->okButton, &QAbstractButton::released, this, &ProductAddDialog::onOkClicked);
    connect(ui->cancelButton, &QAbstractButton::released, this, &ProductAddDialog::onCancelClicked);
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
    hide();
    clear();
}

ProductAddDialog::~ProductAddDialog() {
    delete ui;
}
