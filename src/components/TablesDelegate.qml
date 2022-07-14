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

        color: "yellow"
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
            width: 30
        }

        Text {
            id: playerTableText

            Layout.preferredWidth: parent.width / 6
            Layout.fillWidth: true

            font.pixelSize: fontSize
            text: table
            font.bold: true
        }
    }
}
