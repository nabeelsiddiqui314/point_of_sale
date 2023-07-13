#ifndef PRODUCTMANAGEMENTFORM_H
#define PRODUCTMANAGEMENTFORM_H

#include <QWidget>
#include <Models/ProductsTableModel.h>

#include "ProductAddDialog.h"


namespace Ui {
class ProductManagementForm;
}

class ProductManagementForm : public QWidget {
    Q_OBJECT
public:
    ProductManagementForm(Scanner* scanner, QWidget *parent = nullptr);
    ~ProductManagementForm();
private slots:
    void onAddClicked();
    void onDeleteClicked();
    void onProductAdd();
private:
    Ui::ProductManagementForm *ui;
    ProductsTableModel* m_model;
    ProductAddDialog* m_addDialog;
    Scanner* m_scanner;
};

#endif // PRODUCTMANAGEMENTFORM_H
