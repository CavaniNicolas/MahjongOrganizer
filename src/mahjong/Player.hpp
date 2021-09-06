
#pragma once

#include <string>
#include <mahjong/json.hpp>

enum class Level {
	beginner, leisure, competitive
};

std::string getStringFromLevel(Level level);
Level getLevelFromStr(std::string level);

class Player
{
private:
	static int m_playerNum;

	std::string m_name;
	std::string m_surname;
	Level m_level;
	int m_playerID;

public:
    Player(std::string name, std::string surname, Level level=Level::beginner);
    Player(std::string name, std::string surname, std::string level);
    Player();
	Player(nlohmann::json playerJson);
	Player(Player const & player);
    ~Player()=default;

	std::string getPlayerName() const;
	std::string getName() const;
	std::string getSurname() const;
	Level getLevel() const;
	std::string getLevel_str() const;
	int getID() const;

    nlohmann::json toJson() const;
    nlohmann::json toJsonFull() const;

	Player & operator=(Player const & player);
};
