
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

	nlohmann::json readPlayersFromFile();
	void writePlayersInFile(nlohmann::json players);
};
