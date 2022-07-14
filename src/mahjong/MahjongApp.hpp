
#pragma once

#include <QObject>

#include "mahjong/PlayerParser.hpp"
#include "mahjong/PlayerModel.hpp"
#include "mahjong/Room.hpp"

class MahjongApp : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileURL READ fileURL WRITE setFileURL NOTIFY fileURLChanged)

  public:
    MahjongApp(int& argc, char** argv);
    ~MahjongApp() = default;

    // getters setters
    void getPlayersFromFile();
    void setFileURL(const QString& fileURL);
    QString fileURL() const
    {
        return m_fileURL;
    }

  signals:
    void fileURLChanged();

  public slots:
    void useDefaultFile();
    void loadFile();

  private:
    void fillModel();
    void addDefaultPlayersToModel();

    PlayerParser m_playerParser;
    Room m_room;
    std::shared_ptr<PlayerModel> m_playerModel;

    QString m_fileURL;
};
