
#include <memory>
#include <vector>
#include <iostream>

#include "Room.hpp"
#include "Player.hpp"

Room::Room(Table tables)
{
}

Room::~Room()
{
}

void Room::determineNumberTables(int& nbTableOf4, int& nbTableOf3, int nbOfPlayers)
{
	int playersLeft = nbOfPlayers % 4;
	nbTableOf4 = nbOfPlayers / 4;
	
	if (playersLeft == 0) {
		nbTableOf3 = 0;	
	} else if (playersLeft == 3)	{
		nbTableOf3 = 1;
	} else if (playersLeft == 2) {
		nbTableOf4 -= 1;
		nbTableOf3 = 2;
	} else { // if (playersLeft == 1)
		nbTableOf4 -= 2;
		nbTableOf3 = 3;
	}	

}


void Room::createTables()
{
	std::array<Player, 4> players = {Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("un", "un", Level::competitive), Player("un", "un", Level::competitive)};

	Table table(players);
	m_tables.push_back(table);

	for (int i=0; i<4; i++)
	{
		std::cout << m_tables.at(0).getPlayers().at(i).getName() << std::endl;
	}
}