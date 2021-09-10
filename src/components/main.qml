import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: window
    width: 1200
    height: 900
    visible: true
    title: "Mahjong Table Arranger"

    property bool canClose: true
    onClosing: {
        close.accepted = canClose
        if (canClose == false) {
            dialogItems.unsavedChangesDialog.open()
        }
    }

    // Non resizable
    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height


    RowLayout {
        id: rowMain
        anchors.fill: parent
        spacing: 0

        ColumnLayout {
            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true

                PlayersView {
                    id: listView
                    width: parent.width * 9 / 10
                    height: parent.height * 9 / 10
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    orientation: Qt.Vertical
                    verticalLayoutDirection: ListView.TopToBottom
                }

            }
        }

        ColumnLayout {
            id: columnRight
            spacing: 0

            ColumnLayout {
                id: columnRightTop
                spacing: 0

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    ComboBox {
                        id: comboBox
                        width: parent.width * 2 / 3
                        anchors.centerIn: parent

                        model: [ "1h", "1h30", "2h" ]
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    ComboBox {
                        id: comboBox1
                        width: parent.width * 2 / 3
                        anchors.centerIn: parent

                        model: [ "all together", "3 level groups", "Beginner + Leisure", "Leisure + Competitive" ]
                    }
                }

                Rectangle {
//                    id: spacer
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
            }

            ColumnLayout {
                id: columnRightBot
                spacing: 0

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Button {
                        id: buttonNewPlayer
                        width: parent.width * 2 / 3
                        text: qsTr("Add new player")
                        anchors.centerIn: parent

                        onClicked: {
                            var component = Qt.createComponent("NewPlayerForm.qml")
                            var windowForm    = component.createObject(window)

                            windowForm.show()
                        }
                    }

                }


                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Button {
                        id: buttonSavePlayers
                        width: parent.width * 2 / 3
                        anchors.centerIn: parent
                        text: qsTr("Save players")

                        enabled: !canClose

                        onClicked: {
                            window.canClose = true
                        }
                    }

                }


                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Button {
                        id: buttonStart
                        width: parent.width * 2 / 3
                        text: qsTr("Go with these players")
                        anchors.centerIn: parent
                    }

                }

                Rectangle {
//                    id: spacer
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }

            }
        }
    }

    DialogItems {
        anchors.centerIn: parent
        id: dialogItems
    }

    Connections {
//        target: room
        target: playerModel
        function onNewPlayerFormError() {
            dialogItems.formErrorDialog.open()
        }
        function onNewPlayerFormAdded() {
            window.canClose = false
        }
    }

}

