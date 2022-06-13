import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: window
    width: 1200
    height: 900
    visible: true
    title: "Mahjong Table Arranger"

    // Non resizable
    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height

    property bool canClose: true
    onClosing: {
        close.accepted = canClose
        if (canClose == false) {
            dialogItems.unsavedChangesDialog.open()
        }
    }

    DialogItems {
        anchors.centerIn: parent
        id: dialogItems
    }

    Connections {
        target: playerModel
        function onNewPlayerFormError() {
            dialogItems.formErrorDialog.open()
        }
        function onNewPlayerFormAdded() {
            window.canClose = false
        }
    }

    Loader {
        id: mainLoader
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
        source: "MahjongApp.qml"
    }
}
