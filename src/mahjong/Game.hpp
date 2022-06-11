
#pragma once

#include <memory>
#include <vector>

#include "mahjong/Player.hpp"

class Game
{
  public:
    Game(int nbTables);
    ~Game() = default;

    void fillTables(std::vector<std::shared_ptr<Player>> beginner,
                    std::vector<std::shared_ptr<Player>> leisure,
                    std::vector<std::shared_ptr<Player>> competitive);
    void displayTables() const;

  private:
    void fillTablesWithPlayers(std::vector<std::shared_ptr<Player>> players);

    std::vector<std::array<std::shared_ptr<Player>, 4>> m_tables;
    int m_fillPlayerAtId;
};
