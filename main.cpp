#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "userlist.h"
#include "ellipseitem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<UserList>("UserList", 1, 0, "UserList");
    qmlRegisterType<EllipseItem>("Shapes", 1, 0, "EllipseItem");

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("qt-test", "Main");

    return app.exec();

}
