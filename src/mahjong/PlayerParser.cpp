
#include <fstream>
#include <iostream>

#include "mahjong/json.hpp"
#include "mahjong/PlayerParser.hpp"
#include "mahjong/Player.hpp"

PlayerParser::PlayerParser(std::string const filename):
	m_filename(filename)
{
}


nlohmann::json PlayerParser::readPlayersFromFile()
{
    using json = nlohmann::json;
    json players;

    std::ifstream file(m_filename);
    file >> players;

    return players;
}

void PlayerParser::writePlayersInFile(nlohmann::json players)
{
    std::ofstream file(m_filename);

    file << players.dump(4) << std::endl;
}