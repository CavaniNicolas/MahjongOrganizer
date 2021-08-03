
#include <iostream>
#include <string>

#include <json.hpp>

#include "Player.hpp"
#include "Room.hpp"
#include "PlayerParser.hpp"

int main(int argc, char const *argv[])
{
    using json = nlohmann::json;

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

	return 0;
}
