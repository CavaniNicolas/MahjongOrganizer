
#include <vector>
#include <iostream>

#include "mahjong/Room.hpp"
#include "mahjong/Player.hpp"


Room::Room(nlohmann::json players):
    m_nbOfPlayers(players.size())
{
    createPlayersFromJson(players);
	determineNumberTables();
}


void Room::createPlayersFromJson(nlohmann::json players)
{
    for (auto& player : players) {
      m_players.push_back(Player(player));
    }
}


void Room::determineNumberTables()
{
	int playersLeft = m_nbOfPlayers % 4;
	m_nbTableOf4 = m_nbOfPlayers / 4;
	
	if (playersLeft == 0) {
		m_nbTableOf3 = 0;	
	} else if (playersLeft == 3)	{
		m_nbTableOf3 = 1;
	} else if (playersLeft == 2) {
		m_nbTableOf4 -= 1;
		m_nbTableOf3 = 2;
	} else { // if (playersLeft == 1)
		m_nbTableOf4 -= 2;
		m_nbTableOf3 = 3;
	}	

}


void Room::addNewPlayer(Player player)
{
    m_players.push_back(player);
    m_nbOfPlayers++;
    determineNumberTables();
}


std::vector<Player>::iterator Room::searchPlayerFromId(int id) // const
{
    std::vector<Player>::iterator iterator = m_players.begin();
    bool isFound = false;

    while (!isFound && iterator != m_players.end()) {
        if (iterator->getID() == id) {
            isFound = true;
        } else {
            iterator++;
        }
    }
    return iterator;
}


void Room::removePlayerFromId(int id)
{
    std::vector<Player>::iterator iterator = searchPlayerFromId(id);

    std::cout << "iterator : " << iterator->toJsonFull() << std::endl;
    if (iterator != m_players.end()) {
        m_players.erase(iterator);
        m_nbOfPlayers--;
        determineNumberTables();
    }
}


void Room::removePlayerFromIndex(int id)
{
    if (id >= m_players.size()) {
        std::cout << "throw out of bound exception" << std::endl;
    }
    else {
        m_players.erase(m_players.begin() + id);
        m_nbOfPlayers--;
        determineNumberTables();
    }
}


void Room::displayAllPlayers() const
{
    std::cout << getPlayersJson().dump(4) << std::endl;
}


nlohmann::json Room::getPlayersJson() const
{
    nlohmann::json players;
    for (auto& player : m_players)
    {
        players.push_back(player.toJson());
    }
    return players;
}


void Room::addTable(Table table)
{
    m_tables.push_back(table);
}

void Room::displayTables() const
{
    for (int i=0; i<(m_nbTableOf4 + m_nbTableOf3); i++)
    {
        for (int j=0; j<4; j++)
        {
            std::cout << m_tables.at(i).getPlayers().at(j).getName();
            if (j < 3) {
                std::cout << " -- ";
            }
        }
        std::cout << std::endl;
    }
}
