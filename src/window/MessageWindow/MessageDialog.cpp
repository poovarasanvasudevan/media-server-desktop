//
// Created by poovarasan on 02/09/20.
//

#include <QJsonObject>
#include <QDebug>
#include "MessageDialog.h"
#include "ui_messagedialog.h"


MessageDialog::~MessageDialog() {
    delete ui;
}

QJsonObject MessageDialog::getUser() {
    return this->userObj;
}

void MessageDialog::setUser(QJsonObject jsonObject) {
    this->userObj = jsonObject;
}

MessageDialog::MessageDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::MessageDialog) {
    ui->setupUi(this);
    this->setFixedSize(QSize(280, 370));
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
   // qDebug() << this->userObj;
}

void MessageDialog::showUserChat() {
    this->setModal(false);
    this->show();
    this->setWindowTitle(this->userObj["first_name"].toString() +" " + this->userObj["last_name"].toString());
}