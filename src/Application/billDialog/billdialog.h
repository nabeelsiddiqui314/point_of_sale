#ifndef BILLDIALOG_H
#define BILLDIALOG_H

#include <QDialog>

namespace Ui {
class billDialog;
}

class billDialog : public QDialog
{
    Q_OBJECT

public:
    explicit billDialog(QWidget *parent = nullptr);
    ~billDialog();

private:
    Ui::billDialog *ui;
};

#endif // BILLDIALOG_H
