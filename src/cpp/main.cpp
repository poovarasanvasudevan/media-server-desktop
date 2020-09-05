#include <QApplication>
#include "../window/MainWindow/MainWindow.h"
#include <QDir>
#include <QSystemTrayIcon>


void applicationInit() {
    QDir dir(QDir::cleanPath(QDir::homePath()) + QDir::separator() + "OfficeApp");
    if (!dir.exists()) {
        dir.mkpath(".");
    }

}

int main(int argc, char **argv) {

    QApplication a(argc, argv);



    MainWindow w;
    w.setWindowIcon(QIcon(":/assets/icons/logo.png"));
    applicationInit();
    w.show();
    return a.exec();
}