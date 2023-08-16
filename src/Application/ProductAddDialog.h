#ifndef PRODUCTADDDIALOG_H
#define PRODUCTADDDIALOG_H

#include <QDialog>
#include <Database/ProductDatabase.h>

class Scanner;

namespace Ui {
class ProductAddDialog;
}

class ProductAddDialog : public QDialog {
    Q_OBJECT
public:
    ProductAddDialog(Scanner* scanner, QWidget *parent = nullptr);
    ~ProductAddDialog();
private:
    void showEvent(QShowEvent*) override;
    void hideEvent(QHideEvent*) override;
    void closeEvent(QCloseEvent* event) override;
    void clear();
signals:
    void productAdded();
private slots:
    void onOkClicked();
    void onCancelClicked();
    void onCodeScanned(QString code);
private:
    Ui::ProductAddDialog *ui;

    ProductDatabase m_database;
    Scanner* m_scanner;
};

#endif // PRODUCTADDDIALOG_H
