
#include <memory>
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

void Room::createPlayersFromJson(nlohmann::json players)
{
    for (auto& player : players) {
      m_players.push_back(Player(player));
    }
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

