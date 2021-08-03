
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>
#include <string>

#include <mahjong/json.hpp>

#include "mahjong/Player.hpp"
#include "mahjong/PlayerParser.hpp"
#include "mahjong/Room.hpp"

int main(int argc, char *argv[])
{
    using json = nlohmann::json;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }


    std::array<Player, 8> players;

    players.at(0) = Player("un", "un", Level::competitive);
	players.at(1) = Player("deux", "deux", Level::competitive);
	players.at(2) = Player("trois", "trois", Level::competitive);
	players.at(3) = Player("quatre", "quatre", Level::competitive);
	players.at(4) = Player("cinq", "cinq", Level::competitive);
	players.at(5) = Player("six", "six", Level::competitive);
	players.at(6) = Player("sept", "sept", Level::competitive);
	players.at(7) = Player("huit", "huit", Level::competitive);

    Room room(4);

    std::cout << room.getNbTableOf4() << " " << room.getNbTableOf3() << " " << std::endl;
    std::cout << getStringFromLevel(Level::beginner) << getStringFromLevel(Level::leisure) << getStringFromLevel(Level::competitive) << std::endl;
    

    std::array<Player, 4> table = {Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("trois", "un", Level::competitive), Player("un", "un", Level::competitive)};
    // Table table1 = Table(Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("un", "un", Level::competitive));
    Table table1 = Table(table);

    room.addTable(table1);

    room.displayTables();

    PlayerParser pp("mahjong.txt");
    pp.readPlayersFromFile();
    pp.writePlayersInFile(players.at(0).toJson());

    return app.exec();
}
