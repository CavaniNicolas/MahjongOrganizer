
#pragma once

#include <iostream>

class PlayerParser
{
private:
	std::string m_filename;

public:
	PlayerParser(std::string const filename);
	~PlayerParser()=default;

	void writePlayerInFile();
	void readPlayerFromFile();
};
