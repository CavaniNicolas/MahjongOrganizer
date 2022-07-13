import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

Item {
    width: parent.width
    height: 50

    property int fontSize: 16

    Rectangle {
        y: 5
        width: parent.width
        height: 30

        color: "orange"
    }

    RowLayout {
        id: listRow
        spacing: 10

        Item {
//            id: spacer
            width: 10
        }

        Text {
            id: playerLastNameText

            Layout.preferredWidth: parent.width / 6
            Layout.fillWidth: true

            font.pixelSize: fontSize
            text: name
        }

        Item {
//            id: spacer
            width: 20
        }

        Text {
            id: playerFirstNameText

            Layout.preferredWidth: parent.width / 6
            Layout.fillWidth: true

            font.pixelSize: fontSize
            text: surname
        }

        Item {
//            id: spacer
            width: 50
        }

        Text {
            id: playerLevelText

            Layout.preferredWidth: parent.width / 6
            Layout.fillWidth: true

            font.pixelSize: fontSize
            text: level
            font.bold: true
        }

        Item {
//            id: spacer
            width: 10
        }

        CheckBox {
            id: isPlayerHereCheckBox

            Layout.fillWidth: true

            checked: isPlaying
            onCheckStateChanged: mahjongApp.checkPlayer(index, checkState)
            //text: qsTr("Is Playing")
        }

        Item {
//            id: spacer
            width: 3
        }

        Button {
            id: editPlayerButton

            Layout.preferredWidth: 28
            Layout.preferredHeight: 28
            Layout.fillWidth: true

            text: "edit"
        }
    }
}
