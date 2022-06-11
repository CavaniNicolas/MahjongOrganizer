
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
    //    room.displayMembers();

    //    room.addNewMember(Player("un", "un", Level::Beginner));
    //    room.addNewMember(Player("deux", "deux", Level::Leisure));
    //    room.addNewMember(Player("trois", "trois", Level::Competitive));
    //    room.addNewMember(Player("quatre", "quatre", Level::Beginner));
    //    room.addNewMember(Player("cinq", "cinq", Level::Leisure));
    //    room.addNewMember(Player("six", "six", Level::Competitive));
    //    room.addNewMember(Player("sept", "sept", Level::Beginner));
    //    room.addNewMember(Player("huit", "huit", Level::Leisure));
    //    room.addNewMember(Player("neuf", "neuf", Level::Competitive));

    //    room.removeMemberFromIndex(room.getNbOfMembers() - 1);

    std::cout << room.getNbOfMembers() << std::endl;

    room.setUpGame();
    // room.displayPlayers();
    std::cout << std::endl;
    room.displayTablesFromGame(0);

    pp.writePlayersInFile(room.getMembersJson());
    //    room.removeMemberFromId(32);

    return 0;
}
