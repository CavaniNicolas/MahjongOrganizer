
#pragma once

#include "Player.hpp"

class Table
{
private:
	std::array<std::unique_ptr<Player>, 4> m_players;

public:
	Table(Player[4]);
	~Table();
};
