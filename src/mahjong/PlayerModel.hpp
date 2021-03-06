
#pragma once

#include <QAbstractListModel>
#include <QList>
#include <QStringList>

class QPlayer
{
  public:
    QPlayer(const QString& name,
            const QString& surname,
            const QString& level,
            const bool& isPlaying = true,
            const int& table = 1);
    QPlayer(const QPlayer& player);

    // Getters
    QString getName() const;
    QString getSurname() const;
    QString getLevel() const;
    bool getIsPlaying() const;
    int getTable() const;

    // Setters
    void setName(QString name);
    void setSurname(QString surname);
    void setLevel(QString level);
    void setIsPlaying(bool isplaying);
    void setTable(int table);

  private:
    QString m_name;
    QString m_surname;
    QString m_level;
    bool m_isPlaying;
    int m_table;
};

class PlayerModel : public QAbstractListModel
{
    Q_OBJECT

  public:
    enum PlayerRoles
    {
        NameRole = Qt::UserRole + 1,
        SurnameRole,
        LevelRole,
        IsPlayingRole,
        TableRole
    };

    enum OrderPlayersBy
    {
        None = 0,
        Level,
        Name,
        Surname,
        IsPlaying,
        Table
    };

    // class
    PlayerModel(QObject* parent = 0);

    // manage QPlayers
    QList<QPlayer>::iterator searchLastPlayerSameLevelIndex(const QPlayer& player);
    QList<QPlayer>::iterator searchPlayerTableOrder(const QPlayer& player);
    void addPlayer(const QPlayer& player);
    void removeNonPlayingMembers();
    void setPlayerIsPlaying(int playerIndex, bool state);

  public:
    // Getters and Setters
    QList<QPlayer> getPlayers() const
    {
        return m_players;
    }
    void setTableToQPlayerAtID(int table, int id);
    void setOrderPlayersBy(OrderPlayersBy orderPlayersBy);

    // QT override
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    // Qt::ItemFlags flags(const QModelIndex& index) const override;
    void sort(int column = 0, Qt::SortOrder order = Qt::AscendingOrder) override;

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    QList<QPlayer> m_players;
    OrderPlayersBy m_orderPlayersBy;
};
