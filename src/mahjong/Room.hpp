
#pragma once

#include <memory>
#include "mahjong/Table.hpp"

class Room
{
private:
	int m_nbOfPlayers;

	int m_nbTableOf4;
	int m_nbTableOf3;

	std::vector<Table> m_tables;

public:
	Room(int nbOfPlayers);
	~Room()=default;

	void determineNumberTables();
	void addTable(Table table);

	int getNbTableOf4() const {return m_nbTableOf4;};
	int getNbTableOf3() const {return m_nbTableOf3;};

	void displayTables() const;
};
