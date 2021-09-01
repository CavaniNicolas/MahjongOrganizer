
#pragma once

#include <memory>
#include "mahjong/Table.hpp"

class Room
{
private:
	int m_nbOfPlayers;
	int m_nbTableOf4;
	int m_nbTableOf3;

    std::vector<Player> m_players;

	std::vector<Table> m_tables;

public:
    Room(nlohmann::json players);
	~Room()=default;

    void createPlayersFromJson(nlohmann::json players);

	void determineNumberTables();
	void addTable(Table table);

    int getNbOfPlayers() const {return m_nbOfPlayers;}
    int getNbTableOf4() const {return m_nbTableOf4;};
	int getNbTableOf3() const {return m_nbTableOf3;};

    void displayAllPlayers() const;
	void displayTables() const;

    nlohmann::json getPlayersJson() const;

    void addNewPlayer(Player player);
    void removePlayerFromId(int id);
};
