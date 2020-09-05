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
    QUrl url(this->baseUrl() + "/classes/" + className);
    QUrlQuery query;
    query.addQueryItem("where", QJsonDocument(whereCondition).toJson(QJsonDocument::Compact));
    url.setQuery(query);
    auto request = this->baseRequest(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    return this->baseManager()->get(request);
}

ParseRequest::ParseRequest() : networkManager(this) {

}

ParseRequest::~ParseRequest() {

}

QNetworkReply *ParseRequest::save(QString className, QJsonObject obj) {
    QUrl url(this->baseUrl() + "/classes/" + className);
    auto request = this->baseRequest(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return this->baseManager()->post(request, QJsonDocument(obj).toJson());
}

QNetworkReply *ParseRequest::signIn(QString username, QString password) {

    QUrl url(this->baseUrl() + "/login");


    QUrlQuery query;
    query.addQueryItem("username", username);
    query.addQueryItem("password", password);
    url.setQuery(query);

    auto request = this->baseRequest(url);
    request.setRawHeader("X-Parse-Revocable-Session", "1");

    return this->baseManager()->get(request);
}

QString ParseRequest::baseUrl() {
    return "http://localhost:2016/parse";
}
//creatept to createinc
