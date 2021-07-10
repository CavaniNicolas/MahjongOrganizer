
#pragma once

#include <memory>
#include "Table.hpp"

class Room
{
private:
	std::vector<std::unique_ptr<Table>> m_tables;

public:
	Room(std::unique_ptr<Table> tables=nullptr);
	~Room();

	void determineNumberTables(int& nbTableOf4, int& nbTableOf3, int nbOfPlayers);
};
