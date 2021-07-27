
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

Player::Player(nlohmann::json playerJson):
	Player::Player(playerJson["name"].get<std::string>(),
				   playerJson["surname"].get<std::string>(),
				   getLevelFromStr(playerJson["level"].get<std::string>()))
{
}

Player::Player(Player const & player):
	Player::Player(player.getName(),
				   player.getSurname(),
				   player.getLevel())
{
}

Player::~Player()
{
}

Player & Player::operator=(Player const & player)
{
	// Si on est pas en train de copier un player avec lui meme
	if (this != &player) {
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
	return level_str[m_level];
}

int Player::getID() const
{
	return m_playerID;
}

nlohmann::json Player::toJson() const
{
	nlohmann::json playerJson = {
		{"name", m_name},
		{"surname", m_surname},
		{"level", level_str[m_level]},
		{"id", m_playerID}
	};
	return playerJson;
}