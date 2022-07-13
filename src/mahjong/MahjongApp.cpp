
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include "mahjong/MahjongApp.hpp"

MahjongApp::MahjongApp(int& argc, char** argv):
  m_fileURL(QString::fromStdString(std::string(RESOURCE_PATH) + "mahjong.json")),
  m_playerParser(PlayerParser(std::string(RESOURCE_PATH) + "mahjong.json")),
  m_room(Room())
{
    useDefaultFile();

    using json = nlohmann::json;

    QGuiApplication app(argc, argv);
    app.setOrganizationName("somename");
    app.setOrganizationDomain("somename");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/components/main.qml")));

    if(!engine.rootObjects().isEmpty())
    {
        m_playerModel = std::make_shared<PlayerModel>();

        //          on expose l'object playerModel au qml, pour pouvoir connect le signal qml au
        //          slot cpp dans le qml
        //          (onNewPlayerFormSaved.connect(playerModel.newPlayerFormSaved); dans
        //          NewPlayerForm.qml)
        engine.rootContext()->setContextProperty("playerModel", &(*m_playerModel));

        engine.rootContext()->setContextProperty("mahjongApp", this);

        app.exec();
    }
}

void MahjongApp::setFileURL(const QString& fileURL)
{
    if(fileURL != m_fileURL)
    {
        QUrl url(fileURL);

        std::cout << "new file selected : " << url.toLocalFile().toStdString() << std::endl;

        m_fileURL = url.toLocalFile();
        m_playerParser.setFilename(url.toLocalFile().toStdString());
        emit fileURLChanged();
    }
}

// ****** slots ****** //

void MahjongApp::useDefaultFile()
{
    setFileURL(QString::fromStdString("file:///" + std::string(RESOURCE_PATH) + "mahjong.json"));
}

void MahjongApp::loadFile()
{
    // read members from file
    nlohmann::json members = m_playerParser.readPlayersFromFile();
    // fill room with json
    m_room.createMembersFromJson(members);
    // fill model with members from room
    fillModel();
}

void MahjongApp::newPlayerFormSaved(QString name, QString surname, QString level)
{
    if(name.isEmpty() || surname.isEmpty())
    {
        emit newPlayerFormError();
    }
    else
    {
        m_playerModel->addPlayer(QPlayer(name, surname, level));
        emit newPlayerFormAdded();
    }
    std::cout << "newPlayer : " << name.toStdString() << " " << surname.toStdString() << " " << level.toStdString()
              << std::endl;
}

void MahjongApp::checkPlayer(int playerIndex, int state)
{
    // set isPlaying to state for the qPlayer (PlayerModel)
    m_playerModel->setPlayerIsPlaying(playerIndex, state);

    // set isPlaying to state for the player (Room)
    std::string name = m_playerModel->getPlayers()[playerIndex].getName().toStdString();
    std::string surname = m_playerModel->getPlayers()[playerIndex].getSurname().toStdString();
    // later on, change this search using the playerID
    std::shared_ptr<Player> member = m_room.searchMemberByName(name, surname);
    if(member != nullptr)
        member->setIsPlaying(state);
}

// update model when we come back to MahjongApp page
void MahjongApp::setUpMahjongAppPage()
{
    // empty m_players
    m_room.resetPlayers();

    // add non playing members back to qPlayers
    foreach(auto const& member, m_room.getMembers())
    {
        if(member->getIsPlaying() == false)
        {
            m_playerModel->addPlayer(QPlayer(QString::fromStdString(member->getName()),
                                             QString::fromStdString(member->getSurname()),
                                             QString::fromStdString(getStringFromLevel(member->getLevel())),
                                             member->getIsPlaying()));
        }
    }
}

// set up players from room and qPlayers from model when starting a game
void MahjongApp::setUpGame()
{
    updatePlayers();
    m_room.setUpGame();
    updateQPlayers();
}

void MahjongApp::updatePlayers()
{
    // update players isPlaying
    // should remove this later on as isPlaying variable is supposed to be already updated on the spot
    updatePlayersIsPlaying();
}

void MahjongApp::updatePlayersIsPlaying()
{
    std::vector<std::shared_ptr<Player>> players = m_room.getMembers();
    QList<QPlayer> qPlayers = m_playerModel->getPlayers();

    int j;
    bool isFound;

    for(int i = 0; i < qPlayers.count(); ++i)
    {
        // update IsPlaying on every player using info from associated qPlayer
        if(qPlayers[i].getIsPlaying() == false)
        {
            j = 0;
            isFound = false;
            while(j < players.size() && !isFound)
            {
                if(players[j]->getName() == qPlayers[i].getName().toStdString() &&
                   players[j]->getSurname() == qPlayers[i].getSurname().toStdString())
                {
                    players[j]->setIsPlaying(false);
                    isFound = true;
                }
                j++;
            }
        }
    }
}

void MahjongApp::updateQPlayers()
{
    m_playerModel->removeNonPlayingMembers();
    updateQPlayersTable();
}

void MahjongApp::updateQPlayersTable()
{
    bool playerFound = false;
    int playerId;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Player>> players = m_room.getPlayers();

    QList<QPlayer> qPlayers = m_playerModel->getPlayers();

    for(int i = 0; i < qPlayers.size(); ++i)
    {
        QPlayer qPlayer(qPlayers[i]);

        playerId = 0;
        while(!playerFound && playerId < players.size())
        {
            player = players[playerId];
            if(qPlayer.getName().toStdString() == player->getName() &&
               qPlayer.getSurname().toStdString() == player->getSurname())
            {
                // cannot do this as qPlayer and qPlayers are copied objects
                // qPlayer.setTable(player->getTable()); // qPlayers[i].setTable(player->getTable());
                m_playerModel->setTableToQPlayerAtID(player->getTable(), i);

                playerFound = true;
            }
            else
            {
                playerId++;
            }
        }
        playerFound = false;
    }

    m_playerModel->setOrderPlayersBy(PlayerModel::OrderPlayersBy::Table);
    m_playerModel->sort(0);
}

void MahjongApp::fillModel()
{
    foreach(auto const& member, m_room.getMembers())
    {
        m_playerModel->addPlayer(QPlayer(QString::fromStdString(member->getName()),
                                         QString::fromStdString(member->getSurname()),
                                         QString::fromStdString(getStringFromLevel(member->getLevel()))));
    }
}

void MahjongApp::addDefaultPlayersToModel()
{
    m_playerModel->addPlayer(QPlayer("jean", "dupont", QString::fromStdString(getStringFromLevel(Level::Beginner))));
    m_playerModel->addPlayer(QPlayer("will", "smith", QString::fromStdString(getStringFromLevel(Level::Leisure))));
    m_playerModel->addPlayer(
      QPlayer("el boban", "novic", QString::fromStdString(getStringFromLevel(Level::Competitive))));
    m_playerModel->addPlayer(
      QPlayer("dernier", "dernier", QString::fromStdString(getStringFromLevel(Level::Competitive))));
}
