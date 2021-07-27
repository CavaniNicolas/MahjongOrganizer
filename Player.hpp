
#pragma once

#include <string>
#include <json.hpp>

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

	std::array<std::unique_ptr<Player>, 3> m_havePlayedWithPlayers;


public:
	Player() = default;
	Player(std::string name, std::string surname, Level level=Level::beginner);
	Player(nlohmann::json playerJson);
	Player(Player const & player);
	~Player();

	std::string getPlayerName() const;
	std::string getName() const;
	std::string getSurname() const;
	Level getLevel() const;
	std::string getLevel_str() const;
	int getID() const;

	nlohmann::json toJson() const;

	Player & operator=(Player const & player);
};
