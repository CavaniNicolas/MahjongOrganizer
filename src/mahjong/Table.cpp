
#include "mahjong/Table.hpp"

Table::Table(std::array<Player, 4> players):
	m_players(players)
{
}

Table::~Table()
{
}

std::array<Player, 4> Table::getPlayers() const
{
	return m_players;
}