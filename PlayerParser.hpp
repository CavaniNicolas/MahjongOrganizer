
#pragma once

#include <iostream>
#include "Player.hpp"

class PlayerParser
{
private:
	std::string m_filename;

public:
	PlayerParser(std::string const filename);
	~PlayerParser()=default;

	Player readPlayerFromFile();
	void writePlayerInFile(Player player);
};
