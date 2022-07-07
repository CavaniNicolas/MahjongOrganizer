
#pragma once

#include "mahjong/Player.hpp"
#include <iostream>

class PlayerParser
{
  public:
    PlayerParser(std::string const filename);
    ~PlayerParser() = default;

    nlohmann::json readPlayersFromFile();
    void writePlayersInFile(nlohmann::json players);

    void setFilename(std::string filename)
    {
        m_filename = filename;
    }

  private:
    std::string m_filename;
};
