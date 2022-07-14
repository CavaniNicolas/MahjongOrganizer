
#include <fstream>
#include <iostream>

#include "mahjong/Player.hpp"
#include "mahjong/PlayerParser.hpp"
#include "mahjong/json.hpp"

PlayerParser::PlayerParser(std::string const filename): m_filename(filename) {}

nlohmann::json PlayerParser::readPlayersFromFile() const
{
    using json = nlohmann::json;
    json players;

    std::ifstream file(m_filename);

    if(file.is_open())
    {
        file >> players;
        std::cout << "Using file : '" << m_filename << "' to load players" << std::endl;
    }
    else
    {
        std::cout << "The file : '" << m_filename << "' does not exist" << std::endl;
    }

    return players;
}

void PlayerParser::writePlayersInFile(nlohmann::json players) const
{
    std::ofstream file(m_filename);

    if(file.is_open())
    {
        file << players.dump(4) << std::endl;
    }
}
