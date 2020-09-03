//
// Created by poovarasan on 02/09/20.
//

#include <QJsonObject>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QCloseEvent>
#include "MessageDialog.h"
#include "ui_messagedialog.h"


QMap<QString, MessageDialog *> MessageDialog::chatUsers = {};


void MessageDialog::closeEvent(QCloseEvent *event) {
    MessageDialog::chatUsers
            .remove(this->userObj["objectId"].toString());
}


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
        : QDialog(parent), ui(new Ui::MessageDialog), parseRequest() {
    ui->setupUi(this);
    this->setFixedSize(QSize(280, 370));
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    // qDebug() << this->userObj;



   // this->getMessages();
}


void MessageDialog::getMessages() {
    auto whereCondition = new QJsonObject();
    auto messageReply = this->parseRequest->fetch("ChatMessages", *whereCondition);

    messageReply->connect(messageReply, &QNetworkReply::finished, [=]() {
        QString strReply = (QString) messageReply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonArray jsonArray = jsonResponse.object()["results"].toArray();

        qDebug() << jsonArray;

    });
}


void MessageDialog::showUserChat() {

    if (MessageDialog::chatUsers.contains(this->userObj["objectId"].toString())) {
        MessageDialog::chatUsers.value(this->userObj["objectId"].toString())->activateWindow();
    } else {
        MessageDialog::chatUsers.insert(this->userObj["objectId"].toString(), this);
        this->setModal(false);
        this->show();
        this->setWindowTitle(this->userObj["first_name"].toString() + " " + this->userObj["last_name"].toString());
    }
}