#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Qt_GUI/headers/backend.h"

DropRateB *drp;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    qmlRegisterType<Text1>("toy.qt", 1, 0, "Text1");
    qmlRegisterType<Text1>("toy.qt", 1, 0, "DropRateB");

    drp = new DropRateB();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("drp", drp);
    engine.load(QUrl(QStringLiteral("qrc:/Qt_GUI/resources/main.qml")));

    return QApplication::exec();
}

