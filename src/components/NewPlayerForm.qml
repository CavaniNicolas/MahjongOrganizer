import QtQuick 2.12
import QtQml 2.15
import QtQuick.Controls 2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: windowNewPlayerForm
    title: "New Player Form"
    width: 520; height: 520
    font.pixelSize: 16

    // Non resizable
    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height

    Item {
        id: content

        width: parent.width
        height: parent.height

        property alias gridLayout: gridLayout
        property alias cancel: cancel
        property alias save: save

        property alias firstName: firstName
        property alias lastName: lastName
        property alias level: level
        property alias phoneNumber: phoneNumber
        property alias email: email
        property alias address: address
        property alias city: city


        GridLayout {
            id: gridLayout

            anchors.right: parent.right
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.rightMargin: 12
            anchors.leftMargin: 12
            anchors.topMargin: 12
            columnSpacing: 8
            rowSpacing: 8
            rows: 12
            columns: 6
            enabled: true


            Label {
                id: label1
                text: qsTr("First Name")
                Layout.columnSpan: 3
            }

            Label {
                id: label2
                text: qsTr("Last Name")
                Layout.columnSpan: 3
            }

//            Item {
//                id: spacer10
//                Layout.preferredHeight: 14
//                Layout.preferredWidth: 14
//            }

            TextField {
                id: firstName
                Layout.minimumWidth: 140
                Layout.fillWidth: true
                Layout.columnSpan: 3
                placeholderText: qsTr("first name")
            }

            TextField {
                id: lastName
                Layout.minimumWidth: 140
                Layout.fillWidth: true
                Layout.columnSpan: 3
                placeholderText: qsTr("last name")
            }

            Label {
                id: label3
                text: qsTr("Level")
                Layout.columnSpan: 6
            }

            ComboBox {
                id: level
                Layout.columnSpan: 6
                Layout.fillWidth: true
                model: ["Beginner", "Leisure", "Competitive"]
            }

            Label {
                id: label4
                text: qsTr("Phone Number")
                Layout.columnSpan: 6
            }

            TextField {
                id: phoneNumber
                Layout.fillWidth: true
                Layout.columnSpan: 6
                placeholderText: qsTr("phone number")
                enabled: false
            }

            Label {
                id: label5
                text: qsTr("Email")
                Layout.columnSpan: 6
            }

            TextField {
                id: email
                Layout.fillWidth: true
                Layout.columnSpan: 6
                placeholderText: qsTr("email")
                enabled: false
            }

            Label {
                id: label6
                text: qsTr("Address")
                Layout.columnSpan: 6
            }

            TextField {
                id: address
                Layout.fillWidth: true
                Layout.columnSpan: 6
                placeholderText: qsTr("address")
                enabled: false
            }

            Label {
                id: label7
                text: qsTr("City")
                Layout.columnSpan: 6
            }

            TextField {
                id: city
                Layout.fillWidth: true
                Layout.columnSpan: 6
                placeholderText: qsTr("city")
                enabled: false
            }

        }

        RowLayout {
            anchors.topMargin: 12
            anchors.right: parent.right
            anchors.rightMargin: 12
            anchors.top: gridLayout.bottom

            Button {
                id: cancel
                text: qsTr("Cancel")
                onClicked: {
                    windowNewPlayerForm.visible = false
                }
            }

            Button {
                id: save
                text: qsTr("Add Player")
                onClicked: {
                    console.log("Button 'Add Player' clicked")
//                    room.newPlayerFormSaved(firstName.text, lastName.text, level.currentValue)
                    playerModel.newPlayerFormSaved(firstName.text, lastName.text, level.currentValue)
                    windowNewPlayerForm.visible = false
                }
            }
        }
    }

}
