
#include <memory>
#include <vector>

#include "mahjong/Player.hpp"

class Game
{
  public:
    Game(int nbTables);
    ~Game() = default;

    void fillTablesWithPlayers(std::vector<std::shared_ptr<Player>> players);

  private:
    std::vector<std::array<std::shared_ptr<Player>, 4>> m_tables;
};
