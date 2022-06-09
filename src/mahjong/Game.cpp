
#include "mahjong/Game.hpp"

Game::Game(int nbTables)
{
    m_tables.reserve(nbTables * 4 * sizeof(std::shared_ptr<Player>));
}

void Game::fillTablesWithPlayers(std::vector<std::shared_ptr<Player>> players) {}
