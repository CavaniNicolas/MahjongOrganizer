
#include <iostream>
#include <string>

#include <json.hpp>

#include "Player.hpp"
#include "Room.hpp"
#include "PlayerParser.hpp"

int main(int argc, char const *argv[])
{
    using json = nlohmann::json;

	// Player jojo("jojo", "dubois", Level::competitive);

	// json jjj = jojo.toJson();

	// Player jaja(jjj["name"].get<std::string>(), jjj["surname"].get<std::string>(), getLevelFromStr(jjj["level"].get<std::string>()));

	// Player juju(jjj);

	// std::cout << jjj.dump(2) << std::endl;
	// std::cout << getLevelFromStr(jjj["level"].get<std::string>()) << std::endl;
	// std::cout << jaja.toJson().dump(2) << std::endl;
	// std::cout << juju.toJson().dump(2) << std::endl;

    // // Here is a JSON text
    // std::string text = R"(
    // {
    //     "Book": {
    //         "Width":  450,
    //         "Height": 30,
    //         "Title":  "Hello World",
    //         "isBiography": false,
    //         "NumOfCopies": 4,
    //         "LibraryIDs": [2319, 1406, 3854, 987]
    //     }
    // }
    // )";

    // // Let's parse and serialize JSON
    // json j_complete = json::parse(text);
    // std::cout  << j_complete.dump(4) << std::endl;

    std::array<Player, 8> players;

    players.at(0) = Player("un", "un", Level::competitive);
	players.at(1) = Player("deux", "deux", Level::competitive);
	players.at(2) = Player("trois", "trois", Level::competitive);
	players.at(3) = Player("quatre", "quatre", Level::competitive);
	players.at(4) = Player("cinq", "cinq", Level::competitive);
	players.at(5) = Player("six", "six", Level::competitive);
	players.at(6) = Player("sept", "sept", Level::competitive);
	players.at(7) = Player("huit", "huit", Level::competitive);
	// players.at(8) = Player("neuf", "neuf", Level::competitive);
	// players.at(9) = Player("dix", "dix", Level::competitive);
	// players.at(10) = Player("toto1", "toto1", Level::competitive);
	// players.at(11) = Player("toto2", "toto2", Level::competitive);


    Room room(4);

    std::cout << room.getNbTableOf4() << " " << room.getNbTableOf3() << " " << std::endl;
    std::cout << getStringFromLevel(Level::beginner) << getStringFromLevel(Level::leisure) << getStringFromLevel(Level::competitive) << std::endl;
    

    std::array<Player, 4> table = {Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("trois", "un", Level::competitive), Player("un", "un", Level::competitive)};
    // Table table1 = Table(Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("un", "un", Level::competitive));
    Table table1 = Table(table);

    room.addTable(table1);

    room.displayTables();

    PlayerParser pp("mahjong.txt");
    pp.readPlayerFromFile();
    pp.writePlayerInFile(players.at(0));
    pp.writePlayerInFile(players.at(6));


	return 0;
}
