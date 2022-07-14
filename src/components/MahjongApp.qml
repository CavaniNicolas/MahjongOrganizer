import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

Item {
    id: mahjongAppPage

    property int fontSize: 20

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

                        font.pixelSize: fontSize
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

                        font.pixelSize: fontSize
                        model: [ "all together", "3 level groups", "Beginner + Leisure", "Leisure + Competitive" ]

                        delegate: ItemDelegate {
                            width: comboBox1.width
                            contentItem: Text {
                                text: modelData
                                color: "green"
                                font: comboBox1.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: comboBox1.highlightedIndex === index
                        }
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
                        anchors.centerIn: parent

                        text: qsTr("Add new player")
                        font.pixelSize: fontSize

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
                        font.pixelSize: fontSize

                        enabled: !window.canClose

                        onClicked: {
                            mahjongApp.saveMembersInFile()
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
                        anchors.centerIn: parent

                        text: qsTr("Go with these players")
                        font.pixelSize: fontSize

                        onClicked: {
                            mahjongApp.setUpGame()
                            mainLoader.source = "TablesPage.qml"
                        }
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

}

