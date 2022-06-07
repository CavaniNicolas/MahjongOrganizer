
#include <iostream>
#include <string>

#include <mahjong/json.hpp>

#include "mahjong/Player.hpp"
#include "mahjong/PlayerParser.hpp"
#include "mahjong/Room.hpp"

int main(int argc, char* argv[])
{
    using json = nlohmann::json;

    PlayerParser pp(std::string(RESOURCE_PATH) + "mahjong.json");

    Room room(pp.readPlayersFromFile());
    // room.displayAllPlayers();

    //    room.addNewPlayer(Player("un", "un", Level::Beginner));
    //    room.addNewPlayer(Player("deux", "deux", Level::Leisure));
    //    room.addNewPlayer(Player("trois", "trois", Level::Competitive));
    //    room.addNewPlayer(Player("quatre", "quatre", Level::Beginner));
    //    room.addNewPlayer(Player("cinq", "cinq", Level::Leisure));
    //    room.addNewPlayer(Player("six", "six", Level::Competitive));
    //    room.addNewPlayer(Player("sept", "sept", Level::Beginner));
    //    room.addNewPlayer(Player("huit", "huit", Level::Leisure));
    //    room.addNewPlayer(Player("neuf", "neuf", Level::Competitive));

    // room.removePlayerFromIndex(room.getNbOfPlayers() - 1);

    std::cout << room.getNbOfPlayers() << std::endl;

    pp.writePlayersInFile(room.getPlayersJson());
    // room.removePlayerFromId(32);

    return 0;
}
