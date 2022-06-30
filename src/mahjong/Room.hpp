
#pragma once

#include <QObject>
#include <memory>

#include "mahjong/Game.hpp"
#include "mahjong/Player.hpp"

class Room
{
  public:
    Room(nlohmann::json members);
    Room(const Room& room);
    ~Room() = default;

    // Manage Members
    void addNewMember(Player member);
    std::vector<Player>::iterator searchMemberFromId(int id);
    void removeMemberFromId(int id);
    void removeMemberFromIndex(int id);

    // Manage Games
    void setUpGame();

    // Display
    void displayPlayers() const;
    void displayTablesFromGame(int numGame) const;
    void displayMembers() const;

    // Getters
    nlohmann::json getMembersJson() const;
    int getNbOfMembers() const
    {
        return m_nbOfMembers;
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
    void createMembersFromJson(nlohmann::json members);

    // Manage Games
    void collectPlayers();
    void generateRandomTables();
    void determineNumberTables(int nbPlayers);
    void fillTablesWithPlayers(std::vector<std::shared_ptr<Player>> beginner,
                               std::vector<std::shared_ptr<Player>> leisure,
                               std::vector<std::shared_ptr<Player>> competitive);

    // Member attributes
    int m_nbOfMembers;
    int m_nbTableOf4;
    int m_nbTableOf3;

    std::vector<Player> m_members;
    std::vector<std::shared_ptr<Player>> m_players;

    int m_numGame;
    std::vector<Game> m_games;
};
