//
// Created by poovarasan on 02/09/20.
//

#ifndef OFFICEAPP_MESSAGEDIALOG_H
#define OFFICEAPP_MESSAGEDIALOG_H

#include <QDialog>
#include "ui_messagedialog.h"
#include "../../hpp/ParseRequest.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MessageDialog; }
QT_END_NAMESPACE

class MessageDialog : public QDialog {
Q_OBJECT

public:
    static QMap<QString, MessageDialog*> chatUsers;

    MessageDialog(QWidget *parent = nullptr);

    ~MessageDialog();

    void setUser(QJsonObject jsonObject);
    QJsonObject getUser();
    void showUserChat();
    void getMessages();

    void closeEvent(QCloseEvent *event);

private:
    Ui::MessageDialog *ui;
    QJsonObject userObj;
    ParseRequest *parseRequest;


};


#endif //OFFICEAPP_MESSAGEDIALOG_H
