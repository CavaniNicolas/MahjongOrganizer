
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>
#include <string>

#include <json.hpp>
using json = nlohmann::json;

#include "Player.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
