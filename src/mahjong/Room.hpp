
#pragma once

#include <QObject>
#include <memory>

#include "mahjong/Player.hpp"

class Room
{
  public:
    Room(nlohmann::json players);
    ~Room() = default;

    // Manage Players
    void addNewPlayer(Player player);
    std::vector<Player>::iterator searchPlayerFromId(int id);
    void removePlayerFromId(int id);
    void removePlayerFromIndex(int id);

    // Manage Games
    void generateRandomTables();

    // Display
    void displayPlayingPlayers() const;
    void displayTables() const;
    void displayAllPlayers() const;

    // Getters
    nlohmann::json getPlayersJson() const;
    int getNbOfPlayers() const
    {
        return m_nbOfPlayers;
    }
    int getNbTableOf4() const
    {
        return m_nbTableOf4;
    }
    int getNbTableOf3() const
    {
        return m_nbTableOf3;
    }

  private:
    // Manage Players
    void createPlayersFromJson(nlohmann::json players);

    // Manage Games
    void determineNumberTables();
    void collectPlayingPlayers();

    // Member attributes
    int m_nbOfPlayers;
    int m_nbTableOf4;
    int m_nbTableOf3;

    std::vector<Player> m_players;
    std::vector<std::shared_ptr<Player>> m_playingPlayers;
    std::vector<std::array<std::shared_ptr<Player>, 4>> m_games;
};
