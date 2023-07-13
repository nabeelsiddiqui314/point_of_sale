#include "MainWindow.h"

#include <QApplication>
#include <Database/ProductDatabase.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ProductDatabase::create(a.applicationDirPath());

    MainWindow w;

    w.show();
    return a.exec();
}
