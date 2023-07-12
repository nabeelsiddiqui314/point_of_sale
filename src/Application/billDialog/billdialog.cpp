#include "billdialog.h"
#include "ui_billdialog.h"

billDialog::billDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::billDialog)
{
    ui->setupUi(this);
}

billDialog::~billDialog()
{
    delete ui;
}
