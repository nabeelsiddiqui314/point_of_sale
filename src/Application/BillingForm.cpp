#include "BillingForm.h"
#include "ui_BillingForm.h"

#include <QMessageBox>
#include <Scanner/Scanner.h>

BillingForm::BillingForm(Scanner* scanner, QWidget *parent)
    : QWidget(parent),
      m_scanner(scanner),
      ui(new Ui::BillingForm) {
    ui->setupUi(this);
    m_model = new BillModel(this);
    ui->tableView->setModel(m_model);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(ui->scanButton, &QAbstractButton::released, this, &BillingForm::onScanClicked);
    connect(ui->deleteButton, &QAbstractButton::released, this, &BillingForm::onDeleteClicked);
    connect(m_model, &BillModel::billChanged, this, &BillingForm::onBillChanged);
}

void BillingForm::showEvent(QShowEvent*) {
    m_scanner->scan();
    connect(&m_scanner->_signals, &ScannerSignals::codeScanned, this, &BillingForm::onCodeScanned);
}

void BillingForm::hideEvent(QHideEvent*) {
    m_scanner->stop();
    disconnect(&m_scanner->_signals, &ScannerSignals::codeScanned, this, &BillingForm::onCodeScanned);
}

void BillingForm::onScanClicked() {
    m_scanner->scan();
}

void BillingForm::onDeleteClicked() {
    auto selectedRows = ui->tableView->selectionModel()->selection();
    m_model->removeItems(selectedRows.indexes());
}

void BillingForm::onCodeScanned(QString code) {
    if (!m_model->addItem(code)) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Product doesn't exist");
        messageBox.setFixedSize(500,200);
        return;
    }
}

void BillingForm::onBillChanged() {
    int total = m_model->getTotal();
    ui->totalLabel->setText(QString::number(total));
}

BillingForm::~BillingForm() {
    delete ui;
}
