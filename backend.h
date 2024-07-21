#ifndef BACKEND_H
#define BACKEND_H
#include <QNetworkReply>
#include <QObject>
#include <QNetworkAccessManager>
#include <QEventLoop>

class Backend : public QObject
{
    Q_OBJECT
public:
    Backend();
    Q_INVOKABLE void getJson();
    static QString getHtml(QString url)
    {
        QNetworkAccessManager *manager = new QNetworkAccessManager();
        QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(url)));
        QByteArray responseData;
        QEventLoop eventLoop;
        connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        eventLoop.exec();       //block until finish
        responseData = reply->readAll();
        return QString(responseData);
    }
};

#endif // BACKEND_H
