#include "ProductManagementForm.h"
#include "ui_ProductManagementForm.h"

#include <Scanner/Scanner.h>

ProductManagementForm::ProductManagementForm(Scanner* scanner, QWidget *parent)
    : QWidget(parent),
      ui(new Ui::ProductManagementForm),
      m_scanner(scanner) {
    ui->setupUi(this);
    m_model = new ProductsTableModel(this);
    ui->tableView->setModel(m_model);

    m_addDialog = new ProductAddDialog(scanner, this);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->addButton, &QAbstractButton::released, this, &ProductManagementForm::onAddClicked);
    connect(ui->deleteButton, &QAbstractButton::released, this, &ProductManagementForm::onDeleteClicked);
    connect(m_addDialog, &ProductAddDialog::productAdded, this, &ProductManagementForm::onProductAdd);
}

void ProductManagementForm::onAddClicked() {
    m_scanner->scan();
    m_addDialog->show();
}

void ProductManagementForm::onDeleteClicked() {
    auto selectedRows = ui->tableView->selectionModel()->selection();
    m_model->removeRecords(selectedRows.indexes());
}

void ProductManagementForm::onProductAdd() {
    m_model->update();
}

ProductManagementForm::~ProductManagementForm() {
    delete ui;
}
