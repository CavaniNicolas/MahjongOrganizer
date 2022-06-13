
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <iostream>
#include <string>

#include <mahjong/json.hpp>

#include "mahjong/Player.hpp"
#include "mahjong/PlayerModel.hpp"
#include "mahjong/PlayerParser.hpp"
#include "mahjong/Room.hpp"

int main(int argc, char* argv[])
{
    using json = nlohmann::json;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/components/main.qml")));
    if(engine.rootObjects().isEmpty())
    {
        return -1;
    }

    PlayerParser pp(std::string(RESOURCE_PATH) + "mahjong.json");

    PlayerModel playerModel;
    playerModel.addPlayer(QPlayer("jean", "dupont", QString::fromStdString(getStringFromLevel(Level::Beginner))));
    playerModel.addPlayer(QPlayer("will", "smith", QString::fromStdString(getStringFromLevel(Level::Leisure))));
    playerModel.addPlayer(QPlayer("el boban", "novic", QString::fromStdString(getStringFromLevel(Level::Competitive))));
    playerModel.addPlayer(
      QPlayer("dernier", "dernier", QString::fromStdString(getStringFromLevel(Level::Competitive))));

    //      on expose l'object playerModel au qml, pour pouvoir connect le signal qml au
    //      slot cpp dans le qml
    //      (onNewPlayerFormSaved.connect(playerModel.newPlayerFormSaved); dans
    //      NewPlayerForm.qml)
    engine.rootContext()->setContextProperty("playerModel", &playerModel);

    return app.exec();
}
