
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

int main(int argc, char *argv[])
{
    using json = nlohmann::json;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/components/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }


    PlayerParser pp("mahjong.json");


    Room room(pp.readPlayersFromFile());
//    room.displayAllPlayers();

    PlayerModel playerModel;
    playerModel.addPlayer(QPlayer("jean", "dupont", QString::fromStdString(getStringFromLevel(Level::beginner))));
    playerModel.addPlayer(QPlayer("will", "smith", QString::fromStdString(getStringFromLevel(Level::leisure))));
    playerModel.addPlayer(QPlayer("el boban", "novic", QString::fromStdString(getStringFromLevel(Level::competitive))));


    engine.rootContext()->setContextProperty("playerModel", &playerModel);


//      on expose l'object Room au qml, pour pouvoir connect le signal qml au slot cpp dans le qml (onNewPlayerFormSaved.connect(room.newPlayerFormSaved); dans NewPlayerForm.qml)
    engine.rootContext()->setContextProperty("room", &room);



//    std::array<Player, 4> table = {Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("trois", "un", Level::competitive), Player("un", "un", Level::competitive)};
//    // Table table1 = Table(Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("un", "un", Level::competitive));
//    Table table1 = Table(table);

//    room.addTable(table1);

//    room.displayTables();


    room.addNewPlayer(Player("neuf", "neuf", Level::competitive));

    room.removePlayerFromIndex(room.getNbOfPlayers()-1);

//    room.displayAllPlayers();
    std::cout << room.getNbOfPlayers() << std::endl;

    pp.writePlayersInFile(room.getPlayersJson());


    room.removePlayerFromId(32);


    return app.exec();
}
