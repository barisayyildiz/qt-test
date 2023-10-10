#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "uicontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<UIController>("Monty", 1, 0, "UIController");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qt-test/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
