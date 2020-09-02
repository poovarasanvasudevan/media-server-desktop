#include <QApplication>
#include "../window/MainWindow/MainWindow.h"
#include <QDir>


void applicationInit() {
    QDir dir(QDir::cleanPath(QDir::homePath()) + QDir::separator() + "OfficeApp");
    if (!dir.exists()) {
        dir.mkpath(".");
    }
}

int main(int argc, char **argv) {

    QApplication a(argc, argv);

    applicationInit();

    MainWindow w;
    w.setWindowIcon(QIcon(":/assets/icons/logo.png"));
    w.show();
    return a.exec();
}