
#include <iostream>

#include "mahjong/Game.hpp"

Game::Game(int nbTables): m_fillPlayerAtId(0)
{
    m_tables.reserve(nbTables * 4 * sizeof(std::shared_ptr<Player>));
    for(int i = 0; i < nbTables; ++i)
    {
        std::array<std::shared_ptr<Player>, 4> newTable;
        m_tables.emplace_back(newTable);
    }
}

void Game::fillTables(std::vector<std::shared_ptr<Player>> beginner,
                      std::vector<std::shared_ptr<Player>> leisure,
                      std::vector<std::shared_ptr<Player>> competitive)
{
    // fill tables with players
    fillTablesWithPlayers(beginner);
    fillTablesWithPlayers(leisure);
    fillTablesWithPlayers(competitive);

    // fill tables with totos
    int nbTotos = (m_tables.size() * 4) - beginner.size() - leisure.size() - competitive.size();
    std::vector<std::shared_ptr<Player>> toto;
    toto.reserve(nbTotos * sizeof(std::shared_ptr<Player>));
    for(int i = 0; i < nbTotos; ++i)
    {
        toto.emplace_back(std::make_shared<Player>());
    }
    fillTablesWithPlayers(toto);
}

void Game::fillTablesWithPlayers(std::vector<std::shared_ptr<Player>> players)
{
    int numTables = m_tables.size();

    for(int i = 0; i < players.size(); ++i)
    {
        std::cout << m_fillPlayerAtId << " " << m_fillPlayerAtId % numTables << " " << m_fillPlayerAtId / numTables
                  << " " << *players[i] << std::endl;

        m_tables[m_fillPlayerAtId % numTables][m_fillPlayerAtId / numTables] = players[i];
        m_fillPlayerAtId++;
    }
}

void Game::displayTables() const
{
    for(int i = 0; i < m_tables.size(); ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(m_tables[i][j] != nullptr)
            {
                std::cout << i << " " << j << " " << *m_tables[i][j] << std::endl;
            }
            else
            {
                std::cout << i << " " << j << std::endl;
            }
        }
    }
}
