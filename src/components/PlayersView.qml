import QtQuick 2.0

ListView {
    width: 200; height: 250

    model: playerModel
    delegate: PlayersDelegate {}
}
