//
// Created by poovarasan on 01/09/20.
//

#ifndef OFFICEAPP_CHATDIALOG_H
#define OFFICEAPP_CHATDIALOG_H

#include <QDialog>
#include "ui_chatdialog.h"
#include <QNetworkReply>
#include <QSortFilterProxyModel>
#include "../../hpp/ParseRequest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChatDialog; }
QT_END_NAMESPACE


class ChatDialog   : public QDialog{
Q_OBJECT

public:
    ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

public slots:
    void initParticipants(QNetworkReply* reply);

private:
    Ui::ChatDialog *ui;

    ParseRequest *parseRequest;
    QSortFilterProxyModel *proxyModel;
};


#endif //OFFICEAPP_CHATDIALOG_H
