
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mahjong/MahjongApp.hpp"

MahjongApp::MahjongApp(int& argc, char** argv):
  m_fileURL(QString::fromStdString(std::string(RESOURCE_PATH) + "mahjong.json")),
  m_playerParser(PlayerParser(std::string(RESOURCE_PATH) + "mahjong.json")),
  m_room(Room())
{
    useDefaultFile();

    using json = nlohmann::json;

    QGuiApplication app(argc, argv);

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

void MahjongApp::fillModel()
{
    foreach(auto const& member, m_room.getMembers())
    {
        m_playerModel->addPlayer(QPlayer(QString::fromStdString(member.getName()),
                                         QString::fromStdString(member.getSurname()),
                                         QString::fromStdString(getStringFromLevel(member.getLevel()))));
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
