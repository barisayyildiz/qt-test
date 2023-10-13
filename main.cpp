// Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <Qt3DQuickExtras/qt3dquickwindow.h>
#include <Qt3DQuick/QQmlAspectEngine>

#include <QGuiApplication>
#include <QtQml>

#include <QQuickView>

int main(int argc, char* argv[])
{
    // Force Qt3D OpenGL renderer
    qputenv("QT3D_RENDERER", "opengl");

    QGuiApplication app(argc, argv);

    // NEW CODE
    QQuickView view;

    view.rootContext()->setContextProperty("_window", &view);
    view.setSource(QUrl("qrc:/main.qml"));
    view.setWidth(1600);
    view.setHeight(900);
    view.show();

    // OLDCODE
    /*
    Qt3DExtras::Quick::Qt3DQuickWindow view;

    // Expose the window as a context property so we can set the aspect ratio
    view.engine()->qmlEngine()->rootContext()->setContextProperty("_window", &view);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
    */

    return app.exec();
}
