
#pragma once

#include <memory>
#include "Table.hpp"

class Room
{
private:
	std::vector<Table> m_tables;

public:
	Room() = default;
	Room(Table tables); // =nullptr
	~Room();

	void determineNumberTables(int& nbTableOf4, int& nbTableOf3, int nbOfPlayers);
	void createTables();
};
