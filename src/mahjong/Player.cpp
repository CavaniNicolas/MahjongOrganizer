
#include <sstream>

#include "mahjong/Player.hpp"

int Player::m_playerNum = 0;

std::string getStringFromLevel(Level level)
{
    if(level == Level::Beginner)
        return "Beginner";
    if(level == Level::Leisure)
        return "Leisure";
    if(level == Level::Competitive)
        return "Competitive";
    return "Competitive";
}

Level getLevelFromStr(std::string level)
{
    if(!level.compare("Beginner"))
    {
        return Level::Beginner;
    }
    else if(!level.compare("Leisure"))
    {
        return Level::Leisure;
    }
    else
    {
        return Level::Competitive;
    }
    return Level::Competitive;
}

Player::Player(std::string name, std::string surname, Level level): m_name(name), m_surname(surname), m_level(level)
{
    m_playerNum++;
    m_playerID = m_playerNum;
}

Player::Player(std::string name, std::string surname, std::string level):
  Player::Player(name, surname, getLevelFromStr(level))
{
}

Player::Player(): Player::Player("Toto", "Toto", Level::Beginner) {}

Player::Player(nlohmann::json playerJson):
  Player::Player(playerJson["name"].get<std::string>(),
                 playerJson["surname"].get<std::string>(),
                 getLevelFromStr(playerJson["level"].get<std::string>()))
{
}

Player::Player(Player const& player): Player::Player(player.getName(), player.getSurname(), player.getLevel()) {}

Player& Player::operator=(Player const& player)
{
    // Si on est pas en train de copier un player avec lui meme
    if(this != &player)
    {
        m_name = player.m_name;
        m_surname = player.m_surname;
        m_level = player.m_level;
        m_playerID = player.m_playerID;
    }
    return *this;
}

std::string Player::getPlayerName() const
{
    std::stringstream flux;
    flux << m_name << " " << m_surname;
    return flux.str();
}

std::string Player::getName() const
{
    return m_name;
}

std::string Player::getSurname() const
{
    return m_surname;
}

Level Player::getLevel() const
{
    return m_level;
}

std::string Player::getLevel_str() const
{
    return getStringFromLevel(m_level);
}

int Player::getID() const
{
    return m_playerID;
}

nlohmann::json Player::toJson() const
{
    return nlohmann::json{
      {"name", m_name},
      {"surname", m_surname},
      {"level", getStringFromLevel(m_level)},
    };
}

nlohmann::json Player::toJsonFull() const
{
    nlohmann::json playerJson = toJson();
    playerJson["id"] = m_playerID;
    return playerJson;
}
