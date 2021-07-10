
#include <memory>
#include "Room.hpp"

Room::Room(std::unique_ptr<Table> tables)
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


