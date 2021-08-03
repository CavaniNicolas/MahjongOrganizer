
#include <fstream>
#include <iostream>

#include "json.hpp"
#include "PlayerParser.hpp"
#include "Player.hpp"

PlayerParser::PlayerParser(std::string const filename):
	m_filename(filename)
{
}


Player PlayerParser::readPlayerFromFile()
{
    using json = nlohmann::json;
    json playerJson;

    std::ifstream file(m_filename);
    file >> playerJson;

    return Player(playerJson);
}

void PlayerParser::writePlayerInFile(Player player)
{
    using json = nlohmann::json;
    std::ofstream file(m_filename);

    file << player.toJson().dump(4) << std::endl;
}