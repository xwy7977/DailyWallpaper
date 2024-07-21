#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include "backend.h"

Backend::Backend() {}

void Backend::getJson()
{
    QNetworkAccessManager* manger = new QNetworkAccessManager(this);
    QUrl url("https://www.bing.com/HPImageArchive.aspx?format=js&idx=0&n=1");
    QNetworkRequest request(url);
    QNetworkReply* reply = manger->get(request);
    QByteArray data = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data);
    qDebug() << QString(jsonResponse.toJson());
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << "Title:" << jsonObject.value("images").isString();
}
