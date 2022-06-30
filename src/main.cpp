
#include <iostream>
#include <string>

#include <mahjong/json.hpp>

#include "mahjong/PlayerParser.hpp"
#include "mahjong/MahjongApp.hpp"

int main(int argc, char* argv[])
{
    nlohmann::json members = {{{"name", "un"}, {"surname", "un"}, {"level", "Beginner"}},
                              {{"name", "deux"}, {"surname", "deux"}, {"level", "Leisure"}},
                              {{"name", "trois"}, {"surname", "trois"}, {"level", "Competitive"}},
                              {{"name", "quatre"}, {"surname", "quatre"}, {"level", "Competitive"}}};

    MahjongApp mahjongApp(argc, argv);

    return 0;
}
