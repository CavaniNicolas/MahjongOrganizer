
import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.0

Item
{
    id: loadFilePage

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
            id: fileUrlText
            anchors.centerIn: parent
            width: parent.width - 10
            text: mahjongApp.fileURL //qsTr("fileUrl")
            font.pixelSize: fontSize
            elide: Text.ElideLeft
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
                onClicked:
                {
                    mahjongApp.useDefaultFile()
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

                onClicked: {
                    fileDialog.open()
                }
            }
            Button
            {
                id: loadButton
                text: "Load file"
                font.pixelSize: fontSize
                onClicked: {
                    mahjongApp.loadFile()
                    mainLoader.source = "MahjongApp.qml"
                }
                background: Rectangle {
                        color: parent.down ? "orange" :
                                (parent.hovered ? "#d6d6d6" : "#f6f6f6")
                }
            }
        }

        //remove file:///
        FileDialog {
            id: fileDialog
            title: "Please choose a file"
            folder: shortcuts.home
            nameFilters: [ "JSON files (*json)", "All files (*)" ]
            onAccepted: {
                //console.log("You chose: " + fileDialog.fileUrl)
                mahjongApp.fileURL = fileDialog.fileUrl
                close()
            }
            onRejected: {
                console.log("Canceled")
                close()
            }
            Component.onCompleted: visible = false
        }
    }
}
