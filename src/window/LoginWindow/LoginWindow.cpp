//
// Created by poovarasan on 03/09/20.
//

#include "LoginWindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::LoginWindow) {
    ui->setupUi(this);

    this->setFixedSize(QSize(350, 400));
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    this->statusBar()->setSizeGripEnabled(false);

    QPixmap bkgnd(":/assets/icons/bgimage.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

LoginWindow::~LoginWindow() {
    delete ui;
}
