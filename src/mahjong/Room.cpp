
#include <iostream>
#include <vector>

#include "mahjong/Room.hpp"

Room::Room(nlohmann::json members): m_nbOfMembers(members.size())
{
    createMembersFromJson(members);
}

// ### Manage Players ###

void Room::createMembersFromJson(nlohmann::json members)
{
    for(auto& member: members)
    {
        m_members.push_back(Player(member));
    }
}

void Room::determineNumberTables(int nbPlayers)
{
    int playersLeft = nbPlayers % 4;
    m_nbTableOf4 = nbPlayers / 4;

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

void Room::addNewMember(Player member)
{
    m_members.push_back(member);
    m_nbOfMembers++;
}

std::vector<Player>::iterator Room::searchMemberFromId(int id) // const
{
    std::vector<Player>::iterator iterator = m_members.begin();
    bool isFound = false;

    while(!isFound && iterator != m_members.end())
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

void Room::removeMemberFromId(int id)
{
    std::vector<Player>::iterator iterator = searchMemberFromId(id);

    if(iterator != m_members.end())
    {
        std::cout << "iterator : " << iterator->toJsonFull() << std::endl;
        m_members.erase(iterator);
        m_nbOfMembers--;
    }
}

void Room::removeMemberFromIndex(int id)
{
    if(id >= m_members.size())
    {
        std::cout << "throw out of bound exception" << std::endl;
    }
    else
    {
        m_members.erase(m_members.begin() + id);
        m_nbOfMembers--;
    }
}

// ### Manage Games ###

void Room::generateRandomTables()
{
    collectPlayers();
    determineNumberTables(m_players.size());
}

void Room::collectPlayers()
{
    foreach(Player player, m_members)
    {
        if(player.getIsPlaying())
        {
            m_players.push_back(std::make_shared<Player>(player));
        }
    }
}

// ### Display ###

void Room::displayPlayers() const
{
    foreach(auto player, m_players)
    {
        std::cout << *player << std::endl;
    }
}

void Room::displayTables() const {}

void Room::displayMembers() const
{
    std::cout << getMembersJson().dump(4) << std::endl;
}

// ### Getters ###

nlohmann::json Room::getMembersJson() const
{
    nlohmann::json members;
    for(auto& member: m_members)
    {
        members.push_back(member.toJson());
    }
    return members;
}
