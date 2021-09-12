
#include <iostream>

#include "mahjong/PlayerModel.hpp"

QPlayer::QPlayer(const QString &name, const QString &surname, const QString &level)
    : m_name(name), m_surname(surname), m_level(level)
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



PlayerModel::PlayerModel(QObject *parent):
    QAbstractListModel(parent),
    m_orderPlayersBy(OrderPlayersBy::Level)
{
}

QList<QPlayer>::iterator PlayerModel::searchLastPlayerSameLevelIndex(const QPlayer &player)
{
    QList<QPlayer>::iterator iterator = m_players.begin();
    bool isFound = false;

    while (!isFound && iterator != m_players.end()) {
        if (iterator->getLevel() == player.getLevel()) {
            isFound = true;
        } else {
            iterator++;
        }
    }
    return iterator;

}

void PlayerModel::addPlayer(const QPlayer &player)
{
    beginResetModel();
//    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    if (m_orderPlayersBy == OrderPlayersBy::Level) {
        QList<QPlayer>::iterator iteratorBefore = searchLastPlayerSameLevelIndex(player);

        if (iteratorBefore != m_players.end()) {
            std::cout << "player BEFORE : " << iteratorBefore->getName().toStdString() << iteratorBefore->getSurname().toStdString() << std::endl;
        }

        m_players.insert(iteratorBefore, player);

        std::cout << "player ADDED : " << player.getName().toStdString() << player.getSurname().toStdString() << std::endl;

    } else {
        std::cout << "LAAAAAAAAAAA FRERE" << std::endl;
        m_players << player;
    }

//    endInsertRows();
    endResetModel();
}

int PlayerModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_players.count();
}

QVariant PlayerModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_players.count())
        return QVariant();

    const QPlayer &player = m_players[index.row()];
    if (role == NameRole)
        return player.getName();
    else if (role == SurnameRole)
        return player.getSurname();
    else if (role == LevelRole)
        return player.getLevel();
    return QVariant();
}

QHash<int, QByteArray> PlayerModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[SurnameRole] = "surname";
    roles[LevelRole] = "level";
    return roles;
}


void PlayerModel::newPlayerFormSaved(QString name, QString surname, QString level)
{
    if (name.isEmpty() || surname.isEmpty()) {
        emit newPlayerFormError();

    } else {
        addPlayer(QPlayer(name, surname, level));
        emit newPlayerFormAdded();
    }
    std::cout << "newPlayer : " << name.toStdString() << " " << surname.toStdString() << " " << level.toStdString() << std::endl;
}
