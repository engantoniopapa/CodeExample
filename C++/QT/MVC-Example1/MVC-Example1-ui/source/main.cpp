#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <controllers/master-controller.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //add the type’s metadata into a module called CM with a version number 1.0,
    //and we want to refer to this type as MasterController in QML markup
    qmlRegisterType<MVC_Example1::controllers::MasterController>("MVC_EXAMPLE1", 1, 0, "MasterController");
    MVC_Example1::controllers::MasterController masterController;

    QQmlApplicationEngine engine;
    //inject MasterController into the root QML context
    engine.rootContext()->setContextProperty("masterController",&masterController);

    engine.load(QUrl(QStringLiteral("qrc:/views/MasterView.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
