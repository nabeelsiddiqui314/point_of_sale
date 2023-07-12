#ifndef DUMMYSCANNER_H
#define DUMMYSCANNER_H

#include <QDialog>
#include <Scanner/Scanner.h>

namespace Ui {
class DummyScanner;
}

class DummyScanner : public QDialog, public Scanner {
    Q_OBJECT

public:
    explicit DummyScanner(QWidget *parent = nullptr);
    ~DummyScanner();
public:
    void scan() override;
    void stop() override;
private:
    void closeEvent(QCloseEvent* event) override;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    Ui::DummyScanner *ui;
};

#endif // DUMMYSCANNER_H
