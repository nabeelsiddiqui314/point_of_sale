#ifndef PRODUCTADDDIALOG_H
#define PRODUCTADDDIALOG_H

#include <QDialog>
#include <Database/ProductDatabase.h>

namespace Ui {
class ProductAddDialog;
}

class ProductAddDialog : public QDialog {
    Q_OBJECT
public:
    ProductAddDialog(QWidget *parent = nullptr);
    ~ProductAddDialog();
private:
    void clear();
signals:
    void productAdded();
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    Ui::ProductAddDialog *ui;

    ProductDatabase m_database;
};

#endif // PRODUCTADDDIALOG_H
