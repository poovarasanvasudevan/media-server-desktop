//
// Created by poovarasan on 02/09/20.
//

#ifndef OFFICEAPP_PARSEREQUEST_H
#define OFFICEAPP_PARSEREQUEST_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>

class ParseRequest : QObject {

public:
    ParseRequest();
    ~ParseRequest();

public:
    QNetworkAccessManager* baseManager();

    QNetworkRequest baseRequest(QUrl url);

    QNetworkReply* fetch(QString className, QJsonObject whereCondition);
    QNetworkReply* save(QString className, QJsonObject obj);

private :
    QNetworkAccessManager networkManager;
};

#endif //OFFICEAPP_PARSEREQUEST_H
