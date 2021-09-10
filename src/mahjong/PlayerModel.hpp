
#include <QAbstractListModel>
#include <QStringList>
#include <QList>

class QPlayer
{
public:
    QPlayer(const QString &name, const QString &surname, const QString &level);

    QString getName() const;
    QString getSurname() const;
    QString getLevel() const;

private:
    QString m_name;
    QString m_surname;
    QString m_level;
};



class PlayerModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum PlayerRoles {
        NameRole = Qt::UserRole + 1,
        SurnameRole,
        LevelRole
    };

    enum OrderPlayersBy {
        None = 0,
        Level,
        Name,
        Surname,
        Presence
    };

    PlayerModel(QObject *parent = 0);

    QList<QPlayer>::iterator searchLastPlayerSameLevelIndex(const QPlayer &player);

    void addPlayer(const QPlayer &player);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<QPlayer> m_players;
    OrderPlayersBy m_orderPlayersBy;

signals:
    void newPlayerFormError();
    void newPlayerFormAdded();

public slots:
    void newPlayerFormSaved(QString firstName, QString lastName, QString level);

};
