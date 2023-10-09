#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QMesh>

#include <QQmlContext>

#include "someclass.h"

// Add your custom 3D-related code here

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //SomeClass testClass;
    qmlRegisterType<SomeClass>("Monty", 1, 0, "SomeClass");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    // Expose the C++ functions to QML
    QObject *rootObject = engine.rootObjects().first();
    // Add necessary connections and signals between QML and C++

    return app.exec();
}
