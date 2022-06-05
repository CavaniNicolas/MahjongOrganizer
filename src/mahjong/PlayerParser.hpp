
#pragma once

#include "mahjong/Player.hpp"
#include <iostream>

class PlayerParser
{
  private:
    std::string m_filename;

  public:
    PlayerParser(std::string const filename);
    ~PlayerParser() = default;

    nlohmann::json readPlayersFromFile();
    void writePlayersInFile(nlohmann::json players);
};
