
#pragma once

#include <string>
#include <json.hpp>
using json = nlohmann::json;

typedef enum Level {
	beginner, leisure, competitive
} Level;

static const char *level_str[] = {"beginner", "leisure", "competitive"};

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
	Player(json playerJson);
	Player(Player const & player);
	~Player();

	std::string getPlayerName() const;
	std::string getName() const;
	std::string getSurname() const;
	Level getLevel() const;
	std::string getLevel_str() const;
	int getID() const;

	json toJson() const;

	Player & operator=(Player const & player);
};
