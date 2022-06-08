
#include <iostream>
#include <vector>

#include "mahjong/Room.hpp"

Room::Room(nlohmann::json players): m_nbOfPlayers(players.size())
{
    createPlayersFromJson(players);
    determineNumberTables();
}

// ### Manage Players ###

void Room::createPlayersFromJson(nlohmann::json players)
{
    for(auto& player: players)
    {
        m_players.push_back(Player(player));
    }
}

void Room::determineNumberTables()
{
    int playersLeft = m_nbOfPlayers % 4;
    m_nbTableOf4 = m_nbOfPlayers / 4;

    switch(playersLeft)
    {
        case 0:
        {
            m_nbTableOf3 = 0;
            break;
        }
        case 3:
        {
            m_nbTableOf3 = 1;
            break;
        }
        case 2:
        {
            m_nbTableOf4 -= 1;
            m_nbTableOf3 = 2;
            break;
        }
        case 1:
        {
            m_nbTableOf4 -= 2;
            m_nbTableOf3 = 3;
            break;
        }
    }
}

void Room::addNewPlayer(Player player)
{
    m_players.push_back(player);
    m_nbOfPlayers++;
    determineNumberTables();
}

std::vector<Player>::iterator Room::searchPlayerFromId(int id) // const
{
    std::vector<Player>::iterator iterator = m_players.begin();
    bool isFound = false;

    while(!isFound && iterator != m_players.end())
    {
        if(iterator->getID() == id)
        {
            isFound = true;
        }
        else
        {
            iterator++;
        }
    }
    return iterator;
}

void Room::removePlayerFromId(int id)
{
    std::vector<Player>::iterator iterator = searchPlayerFromId(id);

    if(iterator != m_players.end())
    {
        std::cout << "iterator : " << iterator->toJsonFull() << std::endl;
        m_players.erase(iterator);
        m_nbOfPlayers--;
        determineNumberTables();
    }
}

void Room::removePlayerFromIndex(int id)
{
    if(id >= m_players.size())
    {
        std::cout << "throw out of bound exception" << std::endl;
    }
    else
    {
        m_players.erase(m_players.begin() + id);
        m_nbOfPlayers--;
        determineNumberTables();
    }
}

// ### Manage Games ###

void Room::generateRandomTables()
{
    collectPlayingPlayers();
}

void Room::collectPlayingPlayers()
{
    foreach(Player player, m_players)
    {
        if(player.getIsPlaying())
        {
            m_playingPlayers.push_back(std::make_shared<Player>(player));
        }
    }
}

// ### Display ###

void Room::displayPlayingPlayers() const
{
    foreach(auto player, m_playingPlayers)
    {
        std::cout << *player << std::endl;
    }
}

void Room::displayTables() const {}

void Room::displayAllPlayers() const
{
    std::cout << getPlayersJson().dump(4) << std::endl;
}

// ### Getters ###

nlohmann::json Room::getPlayersJson() const
{
    nlohmann::json players;
    for(auto& player: m_players)
    {
        players.push_back(player.toJson());
    }
    return players;
}
