#ifndef BILLINGFORM_H
#define BILLINGFORM_H

#include <QWidget>
#include <Models/BillModel.h>

class Scanner;

namespace Ui {
class BillingForm;
}

class BillingForm : public QWidget {
    Q_OBJECT
public:
    BillingForm(Scanner* scanner, QWidget *parent = nullptr);
    ~BillingForm();
private:
    void showEvent(QShowEvent*) override;
    void hideEvent(QHideEvent*) override;
private slots:
    void onScanClicked();
    void onDeleteClicked();
    void onCodeScanned(QString code);
    void onBillChanged();
private:
    Ui::BillingForm *ui;
    BillModel* m_model;
    Scanner* m_scanner;
};

#endif // BILLINGFORM_H
