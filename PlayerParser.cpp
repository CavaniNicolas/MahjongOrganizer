
#include <sstream>
#include <fstream>
#include <iostream>

#include "json.hpp"
#include "PlayerParser.hpp"

PlayerParser::PlayerParser(std::string const filename):
	m_filename(filename)
{
}


void PlayerParser::writePlayerInFile()
{
    std::ifstream file(m_filename);

    std::stringstream strstream;

    std::cout << "methode2" << std::endl;

    file >> strstream.rdbuf();
    std::cout << strstream.str();

}

void PlayerParser::readPlayerFromFile()
{
}