#ifndef SCANDIALOG_H
#define SCANDIALOG_H

#include <QDialog>

namespace Ui {
class scanDialog;
}

class scanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit scanDialog(QWidget *parent = nullptr);
    ~scanDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::scanDialog *ui;
};

#endif // SCANDIALOG_H
