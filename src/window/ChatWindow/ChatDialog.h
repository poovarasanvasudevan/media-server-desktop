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
#include "../MessageWindow/MessageDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChatDialog; }
QT_END_NAMESPACE


class ChatDialog : public QDialog {
Q_OBJECT

public:
    ChatDialog(QWidget *parent = nullptr);

    ~ChatDialog();

public slots:
    void initParticipants(QNetworkReply *reply);
    void participantClick(QModelIndex index);

private:
    Ui::ChatDialog *ui;

    ParseRequest *parseRequest;
    QSortFilterProxyModel *proxyModel;
    MessageDialog *msgDialog;
};
Q_DECLARE_METATYPE(ChatDialog *)

#endif //OFFICEAPP_CHATDIALOG_H
