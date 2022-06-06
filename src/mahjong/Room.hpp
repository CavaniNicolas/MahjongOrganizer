
#pragma once

#include <QObject>
#include <memory>

#include "mahjong/Player.hpp"

class Room
{
  public:
    Room(nlohmann::json players);
    ~Room() = default;

    void addNewPlayer(Player player);
    std::vector<Player>::iterator searchPlayerFromId(int id);
    void removePlayerFromId(int id);
    void removePlayerFromIndex(int id);

    void displayAllPlayers() const;

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
    void createPlayersFromJson(nlohmann::json players);
    void determineNumberTables();

    int m_nbOfPlayers;
    int m_nbTableOf4;
    int m_nbTableOf3;

    std::vector<Player> m_players;
};
