
import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

Item
{
    anchors.fill: parent

    property int fontSize: 20

    Rectangle {
        id: fileUrl

        anchors.horizontalCenter: parent.horizontalCenter
        y: parent.height / 3
        width: 400
        height: 50

        color: "lightgrey"

        Text {
            id: text
            anchors.centerIn: parent
            text: qsTr("fileUrl")
            font.pixelSize: fontSize
        }
    }
    Rectangle
    {
        width: 400
        height: 200
        anchors {
            top: fileUrl.bottom
            horizontalCenter: parent.horizontalCenter
            margins: 40
        }
        color: "lightsteelblue"

        RowLayout
        {
            anchors.centerIn: parent

            Button
            {
                id: defaultButton
                text: "Use default file"
                font.pixelSize: fontSize

                background: Rectangle {
                        color: parent.down ? "orange" :
                                (parent.hovered ? "#d6d6d6" : "#f6f6f6")
                }
            }

            Button
            {
                id: chooseButton
                text: "Choose file"
                font.pixelSize: fontSize

                background: Rectangle {
                        color: parent.down ? "orange" :
                                (parent.hovered ? "#d6d6d6" : "#f6f6f6")
                }
            }
            Button
            {
                id: loadButton
                text: "Load file"
                font.pixelSize: fontSize
                onClicked: mainLoader.source = "MahjongApp.qml"

                background: Rectangle {
                        color: parent.down ? "orange" :
                                (parent.hovered ? "#d6d6d6" : "#f6f6f6")
                }
            }
        }
    }
}
