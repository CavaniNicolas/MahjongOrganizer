
#pragma once

#include <mahjong/json.hpp>
#include <iostream>
#include <sstream>
#include <string>

enum class Level
{
    Beginner,
    Leisure,
    Competitive
};

std::string getStringFromLevel(Level level);
Level getLevelFromStr(std::string level);

class Player
{
  public:
    Player(std::string name, std::string surname, Level level = Level::Beginner);
    Player(std::string name, std::string surname, std::string level);
    Player();
    Player(nlohmann::json playerJson);
    Player(Player const& player);
    ~Player() = default;

    std::string getPlayerName() const;
    std::string getName() const;
    std::string getSurname() const;
    Level getLevel() const;
    std::string getLevel_str() const;
    int getID() const;
    bool getIsPlaying() const;
    void setIsPlaying(bool value);

    nlohmann::json toJson() const;
    nlohmann::json toJsonFull() const;

    Player& operator=(Player const& player);
    friend std::ostream& operator<<(std::ostream& os, Player const& player);

  private:
    static int m_playerNum;

    std::string m_name;
    std::string m_surname;
    Level m_level;
    int m_playerID;
    bool m_isPlaying;
};
