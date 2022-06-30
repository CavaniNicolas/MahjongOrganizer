
#pragma once

#include "mahjong/PlayerParser.hpp"
#include "mahjong/PlayerModel.hpp"
#include "mahjong/Room.hpp"

class MahjongApp
{
  public:
    MahjongApp(int& argc, char** argv);
    ~MahjongApp() = default;

    void loadFile();
    void getPlayersFromFile();

    void addDefaultPlayers();

  private:
    PlayerParser m_playerParser;
    Room m_room;
    std::shared_ptr<PlayerModel> m_playerModel;
};
