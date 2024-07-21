#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "backend.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // QString data = Backend::getHtml(QString( "http://www.oschina.net" ) );

    QString data = Backend::getHtml(QString( "https://www.bing.com/HPImageArchive.aspx?format=js&idx=0&n=1" ) );
    qDebug() << data.toStdString();

    qmlRegisterType<Backend>("Backend",1,0,"Backend");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/DailyWallpaper/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
