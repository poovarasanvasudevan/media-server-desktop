//
// Created by poovarasan on 01/09/20.
//

#include "ChatDialog.h"
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonArray>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QtCore/QJsonObject>
#include "ui_chatdialog.h"


void ChatDialog::initParticipants(QNetworkReply *reply) {

}

// 🔍 is working
ChatDialog::ChatDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::ChatDialog),parseRequest(),proxyModel()  {

    ui->setupUi(this);
    this->setFixedSize(QSize(280, 500));
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    proxyModel = new QSortFilterProxyModel(this);

    auto jsonDoc = new QJsonObject();
    auto parseReply = this->parseRequest->fetch("_User", *jsonDoc);

    parseReply->connect(parseReply, &QNetworkReply::finished, [=]() {
        if (parseReply->error() == QNetworkReply::NoError) {
            QString strReply = (QString) parseReply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
            QJsonArray jsonArray = jsonResponse.object()["results"].toArray();


            auto *model = new QStandardItemModel(ui->participantList);



            Q_FOREACH (const QJsonValue &value, jsonArray) {
                    QJsonObject obj = value.toObject();
                    auto item = new QStandardItem(
                            QIcon(":/assets/icons/user.png"),
                            obj["first_name"].toString() + " " + obj["last_name"].toString());

                    item->setToolTip(obj["first_name"].toString() + " " + obj["last_name"].toString());
                    model->appendRow(item);

                }
            this->proxyModel->setSourceModel(model);
            proxyModel->setFilterKeyColumn(0);
            proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
            proxyModel->sort(0, Qt::AscendingOrder);

            ui->participantList->setModel(proxyModel);

            connect(ui->participantSearch, &QLineEdit::textChanged, [=](QString search_str) {
                QRegExp regExp("*" + search_str + "*", Qt::CaseInsensitive, QRegExp::Wildcard);
                this->proxyModel->setFilterRegExp(regExp);
            });

        }
    });


    auto roomsReply = this->parseRequest->fetch("Rooms", *jsonDoc);
    roomsReply->connect(roomsReply, &QNetworkReply::finished, [=]() {
        QString strReply = (QString) roomsReply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonArray jsonArray = jsonResponse.object()["results"].toArray();


        auto *model = new QStandardItemModel(ui->roomsList);
        auto proxy = new QSortFilterProxyModel();

        Q_FOREACH (const QJsonValue &value, jsonArray) {
                QJsonObject obj = value.toObject();
                auto item = new QStandardItem(
                        QIcon(":/assets/icons/room.png"),
                        obj["name"].toString());

                item->setToolTip(obj["name"].toString());
                model->appendRow(item);

            }

        proxy->setSourceModel(model);
        proxy->setFilterKeyColumn(0);
        proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxy->sort(0, Qt::AscendingOrder);

        ui->roomsList->setModel(proxy);

        connect(ui->roomsSearch, &QLineEdit::textChanged, [=](QString search_str) {
            QRegExp regExp("*" + search_str + "*", Qt::CaseInsensitive, QRegExp::Wildcard);
            proxy->setFilterRegExp(regExp);
        });

    });

}


ChatDialog::~ChatDialog() {
    delete ui;
}