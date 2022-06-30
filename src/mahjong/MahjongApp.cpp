
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mahjong/MahjongApp.hpp"

MahjongApp::MahjongApp(int& argc, char** argv):
  m_playerParser(PlayerParser(std::string(RESOURCE_PATH) + "mahjong.json")),
  m_room(Room(m_playerParser.readPlayersFromFile()))
{
    using json = nlohmann::json;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/components/main.qml")));

    if(!engine.rootObjects().isEmpty())
    {
        m_playerModel = std::make_shared<PlayerModel>();
        addDefaultPlayers();

        //          on expose l'object playerModel au qml, pour pouvoir connect le signal qml au
        //          slot cpp dans le qml
        //          (onNewPlayerFormSaved.connect(playerModel.newPlayerFormSaved); dans
        //          NewPlayerForm.qml)
        engine.rootContext()->setContextProperty("playerModel", &(*m_playerModel));

        app.exec();
    }
}

void MahjongApp::addDefaultPlayers()
{
    m_playerModel->addPlayer(QPlayer("jean", "dupont", QString::fromStdString(getStringFromLevel(Level::Beginner))));
    m_playerModel->addPlayer(QPlayer("will", "smith", QString::fromStdString(getStringFromLevel(Level::Leisure))));
    m_playerModel->addPlayer(
      QPlayer("el boban", "novic", QString::fromStdString(getStringFromLevel(Level::Competitive))));
    m_playerModel->addPlayer(
      QPlayer("dernier", "dernier", QString::fromStdString(getStringFromLevel(Level::Competitive))));
}
