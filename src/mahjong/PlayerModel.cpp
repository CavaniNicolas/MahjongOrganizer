
#include <iostream>

#include "mahjong/PlayerModel.hpp"

QPlayer::QPlayer(const QString& name, const QString& surname, const QString& level):
  m_name(name), m_surname(surname), m_level(level)
{
}

QString QPlayer::getName() const
{
    return m_name;
}

QString QPlayer::getSurname() const
{
    return m_surname;
}

QString QPlayer::getLevel() const
{
    return m_level;
}

void QPlayer::setName(QString name)
{
    m_name = name;
}

void QPlayer::setSurname(QString surname)
{
    m_surname = surname;
}

void QPlayer::setLevel(QString level)
{
    m_level = level;
}

PlayerModel::PlayerModel(QObject* parent): QAbstractListModel(parent), m_orderPlayersBy(OrderPlayersBy::Level) {}

QList<QPlayer>::iterator PlayerModel::searchLastPlayerSameLevelIndex(const QPlayer& player)
{
    QList<QPlayer>::iterator iterator = m_players.begin();
    bool isFound = false;

    while(!isFound && iterator != m_players.end())
    {
        if(iterator->getLevel() == player.getLevel())
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

void PlayerModel::addPlayer(const QPlayer& player)
{
    beginResetModel();
    //    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    if(m_orderPlayersBy == OrderPlayersBy::Level)
    {
        QList<QPlayer>::iterator iteratorBefore = searchLastPlayerSameLevelIndex(player);

        if(iteratorBefore != m_players.end())
        {
            std::cout << "player BEFORE : " << iteratorBefore->getName().toStdString()
                      << iteratorBefore->getSurname().toStdString() << std::endl;
        }

        m_players.insert(iteratorBefore, player);

        std::cout << "player ADDED : " << player.getName().toStdString() << player.getSurname().toStdString()
                  << std::endl;
    }
    else
    {
        std::cout << "LAAAAAAAAAAA FRERE" << std::endl;
        m_players << player;
    }

    //    endInsertRows();
    endResetModel();
}

int PlayerModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_players.count();
}

QVariant PlayerModel::data(const QModelIndex& index, int role) const
{
    // std::cout << index.flags() << std::endl;

    if(index.row() < 0 || index.row() >= m_players.count())
        return QVariant();

    const QPlayer& player = m_players[index.row()];
    if(role == NameRole)
        return player.getName();
    else if(role == SurnameRole)
        return player.getSurname();
    else if(role == LevelRole)
        return player.getLevel();
    return QVariant();
}

// playerModel.setData(playerModel.index(0), "yo", PlayerModel::PlayerRoles::NameRole);
bool PlayerModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(data(index, role) != value)
    {
        QPlayer& player = m_players[index.row()];

        switch(role)
        {
            case NameRole: player.setName(value.toString()); break;
            case SurnameRole: player.setSurname(value.toString()); break;
            case LevelRole: player.setLevel(value.toString()); break;
            default: return false;
        }

        m_players.replace(index.row(), player);

        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

// Qt::ItemFlags PlayerModel::flags(const QModelIndex& index) const
//{
//     return Qt::ItemIsSelectable + Qt::ItemIsEnabled + Qt::ItemNeverHasChildren;
// }

QHash<int, QByteArray> PlayerModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[SurnameRole] = "surname";
    roles[LevelRole] = "level";
    return roles;
}

void PlayerModel::newPlayerFormSaved(QString name, QString surname, QString level)
{
    if(name.isEmpty() || surname.isEmpty())
    {
        emit newPlayerFormError();
    }
    else
    {
        addPlayer(QPlayer(name, surname, level));
        emit newPlayerFormAdded();
    }
    std::cout << "newPlayer : " << name.toStdString() << " " << surname.toStdString() << " " << level.toStdString()
              << std::endl;
}
