
#include <sstream>

#include "Player.hpp"

int Player::m_playerNum = 0;


Level getLevelFromStr(std::string level)
{
	if (!level.compare("beginner")) {
		return Level::beginner;
	} else if (!level.compare("leisure")) {
		return Level::leisure;
	} else {
		return Level::competitive;
	}
	return Level::competitive;
}



Player::Player(std::string name, std::string surname, Level level):
	m_name(name),
	m_surname(surname),
	m_level(level)
{
	m_playerNum++;
	m_playerID = m_playerNum;
}

Player::Player(json playerJson):
	Player::Player(playerJson["name"].get<std::string>(), playerJson["surname"].get<std::string>(), getLevelFromStr(playerJson["level"].get<std::string>()))
{
}

Player::~Player()
{
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
	return level_str[m_level];
}

int Player::getID() const
{
	return m_playerID;
}

json Player::toJson() const
{
	json playerJson = {
		{"name", m_name},
		{"surname", m_surname},
		{"level", level_str[m_level]},
		{"id", m_playerID}
	};
	return playerJson;
}