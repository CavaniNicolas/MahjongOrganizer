import QtQuick.Controls 2
import QtQuick 2.12

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


    Row {
        id: rowMain
        anchors.fill: parent

        Column {
            id: columnLeft
            anchors.left: rowMain.left
            width: rowMain.width * 2 / 3
            height: rowMain.height

            ListView {
                id: listView
                width: parent.width * 9 / 10
                height: parent.height * 9 / 10
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                delegate: Item {
                    x: 5
                    width: 80
                    height: 50
                    Row {
                        id: listRow
                        spacing: 10
                        Rectangle {
                            width: 40
                            height: 40
                            color: colorCode
                        }

                        Text {
                            text: name
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                        }

                        CheckBox {
                            id: checkBox
                            anchors.verticalCenter: parent.verticalCenter
                            text: qsTr("Check Box")
                        }
                    }
                }
                model: ListModel {
                    ListElement {
                        name: "Grey"
                        colorCode: "grey"
                    }

                    ListElement {
                        name: "Red"
                        colorCode: "red"
                    }

                    ListElement {
                        name: "Blue"
                        colorCode: "blue"
                    }

                    ListElement {
                        name: "Green"
                        colorCode: "green"
                    }
                }
            }
        }

        Column {
            id: columnRight
            anchors.left: columnLeft.right
            anchors.right: rowMain.right
            height: rowMain.height

            Column {
                id: columnRightTop
                width: parent.width
                height: parent.height / 2
                topPadding: 50
                spacing: 50

                ComboBox {
                    id: comboBox
                    width: parent.width * 2 / 3
                    anchors.horizontalCenter: parent.horizontalCenter

                    model: [ "1h", "1h30", "2h" ]
                }

                ComboBox {
                    id: comboBox1
                    width: parent.width * 2 / 3
                    anchors.horizontalCenter: parent.horizontalCenter

                    model: [ "all together", "3 level groups", "beginner + leisure", "leisure + competitive" ]
                }
            }

            Column {
                id: columnRightBot
                width: parent.width
                anchors.top: columnRightTop.bottom
                anchors.bottom: parent.bottom

                topPadding: 50
                spacing: 50

                Button {
                    id: button
                    width: parent.width * 2 / 3
                    text: qsTr("Arrange tables")
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }

}
