
#pragma once

#include "Player.hpp"

class Table
{
private:
	std::array<Player, 4> m_players;

public:
	Table(std::array<Player, 4>);
	~Table();

	std::array<Player, 4> getPlayers() const;
};
