
#include <QAbstractListModel>
#include <QList>
#include <QStringList>

class QPlayer
{
  public:
    QPlayer(const QString& name, const QString& surname, const QString& level);

    QString getName() const;
    QString getSurname() const;
    QString getLevel() const;
    bool getIsPlaying() const;

    void setName(QString name);
    void setSurname(QString surname);
    void setLevel(QString level);
    void setIsPlaying(bool isplaying);

  private:
    QString m_name;
    QString m_surname;
    QString m_level;
    bool m_isPlaying;
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
        IsPlayingRole
    };

    enum OrderPlayersBy
    {
        None = 0,
        Level,
        Name,
        Surname,
        IsPlaying
    };

    PlayerModel(QObject* parent = 0);

    QList<QPlayer>::iterator searchLastPlayerSameLevelIndex(const QPlayer& player);

    void addPlayer(const QPlayer& player);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    // Qt::ItemFlags flags(const QModelIndex& index) const override;

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    QList<QPlayer> m_players;
    OrderPlayersBy m_orderPlayersBy;

  signals:
    void newPlayerFormError();
    void newPlayerFormAdded();

  public slots:
    void newPlayerFormSaved(QString firstName, QString lastName, QString level);

    void checkPlayer(int playerIndex, int state);
};
