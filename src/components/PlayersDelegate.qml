import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1


Item {
    width: parent.width
    height: 50

    Rectangle {
        y: 5
        width: parent.width
        height: 30

        color: "orange"
    }

    RowLayout {
        id: listRow
        spacing: 10

        Rectangle {
            width: 40
            height: 40
            radius: width * 0.25

            color: "red"
        }

        Text {
            id: playerLastNameText

            Layout.preferredWidth: parent.width / 6
            Layout.fillWidth: true

            text: name
        }

        Text {
            id: playerFirstNameText

            Layout.preferredWidth: parent.width / 6
            Layout.fillWidth: true

            text: surname
        }

        Text {
            id: playerLevelText

            Layout.preferredWidth: parent.width / 6
            Layout.fillWidth: true

            text: level
            font.bold: true
        }

        CheckBox {
            id: isPlayerHereCheckBox

            x: parent.parent.width / 2
            Layout.fillWidth: true

//            text: qsTr("Check Box")
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
