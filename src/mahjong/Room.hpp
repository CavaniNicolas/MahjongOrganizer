
#pragma once

#include <memory>
#include <QObject>
#include "mahjong/Table.hpp"

class Room : public QObject
{
    Q_OBJECT

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

    void addNewPlayer(Player player);
    std::vector<Player>::iterator searchPlayerFromId(int id);
    void removePlayerFromId(int id);
    void removePlayerFromIndex(int id);

    void displayAllPlayers() const;

    nlohmann::json getPlayersJson() const;
    int getNbOfPlayers() const {return m_nbOfPlayers;}
    int getNbTableOf4() const {return m_nbTableOf4;};
	int getNbTableOf3() const {return m_nbTableOf3;};

    void addTable(Table table);
    void displayTables() const;

public slots:
    void newPlayerFormSaved();

};
