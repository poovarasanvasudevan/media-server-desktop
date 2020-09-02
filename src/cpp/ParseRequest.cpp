//
// Created by poovarasan on 02/09/20.
//

#include "../hpp/ParseRequest.h"
#include <QJsonDocument>
#include <QtCore/QUrlQuery>
#include <QtCore/QUrlQuery>

QNetworkAccessManager *ParseRequest::baseManager() {
    auto nam = new QNetworkAccessManager(this);
    return nam;
}

QNetworkRequest ParseRequest::baseRequest(QUrl url) {
    QNetworkRequest request(url);
    request.setRawHeader("X-Parse-Application-Id", "myAppId");
    request.setRawHeader("X-Parse-REST-API-Key", "restKey");
    request.setRawHeader("X-Parse-Master-Key", "myMasterKey");
    return request;
}

QNetworkReply *ParseRequest::fetch(QString className, QJsonObject whereCondition) {
    QUrl url("http://localhost:1337/parse/classes/" + className);
    QUrlQuery query;
    query.addQueryItem("where", QJsonDocument(whereCondition).toJson(QJsonDocument::Compact));
    url.setQuery(query);
    auto request = this->baseRequest(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    return this->baseManager()->get(request);
}

ParseRequest::ParseRequest() : networkManager(this) {

}

ParseRequest::~ParseRequest() {

}

QNetworkReply *ParseRequest::save(QString className, QJsonObject obj) {
    QUrl url("http://localhost:1337/parse/classes/" + className);
    auto request = this->baseRequest(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return this->baseManager()->post(request, QJsonDocument(obj).toJson());
}
//creatept to createinc
