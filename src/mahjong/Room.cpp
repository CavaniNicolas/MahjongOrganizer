
#include <iostream>
#include <random>
#include <vector>

#include "mahjong/Room.hpp"

Room::Room(nlohmann::json members): m_nbOfMembers(members.size()), m_numGame(1)
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

void Room::setUpGame()
{
    collectPlayers();
    determineNumberTables(m_players.size());

    Game game(m_nbTableOf4 + m_nbTableOf3);
    m_games.push_back(game);

    generateRandomTables();
}

void Room::generateRandomTables()
{
    // get a time based random seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(m_players.begin(), m_players.end(), std::default_random_engine(seed));

    std::vector<std::shared_ptr<Player>> beginner;
    std::vector<std::shared_ptr<Player>> leisure;
    std::vector<std::shared_ptr<Player>> competitive;
    foreach(auto player, m_players)
    {
        switch(player->getLevel())
        {
            case Level::Beginner: beginner.push_back(player); break;
            case Level::Leisure: leisure.push_back(player); break;
            case Level::Competitive: competitive.push_back(player); break;
            default: break;
        }
    }

    fillTablesWithPlayers(beginner, leisure, competitive);
}

void Room::fillTablesWithPlayers(std::vector<std::shared_ptr<Player>> beginner,
                                 std::vector<std::shared_ptr<Player>> leisure,
                                 std::vector<std::shared_ptr<Player>> competitive)
{
    m_games[m_numGame - 1].fillTablesWithPlayers(beginner);
    m_games[m_numGame - 1].fillTablesWithPlayers(leisure);
    m_games[m_numGame - 1].fillTablesWithPlayers(competitive);
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
