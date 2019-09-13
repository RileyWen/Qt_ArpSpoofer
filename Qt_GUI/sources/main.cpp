#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringListModel>

#include "Qt_GUI/headers/DropRateSlider.h"

DropRateSlider *drp;
QStringListModel *slmodel;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    qmlRegisterType<Text1>("toy.qt", 1, 0, "Text1");
    qmlRegisterType<Text1>("toy.qt", 1, 0, "DropRateSlider");

    drp = new DropRateSlider();
    slmodel = new QStringListModel();

    QStringList list;
    for (int i = 0; i <= 100; i++)
        list << QString::number(i);

    slmodel->setStringList(list);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("drp", drp);
    engine.rootContext()->setContextProperty("LogDataQStringListViewModel", slmodel);
    engine.load(QUrl(QStringLiteral("qrc:/Qt_GUI/resources/main.qml")));

    return QApplication::exec();
}

