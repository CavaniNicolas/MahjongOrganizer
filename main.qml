import QtQuick 2.2
import QtQuick.Controls 2
import QtQuick.Controls.Material 2
import QtQuick.Layouts 1
import QtQuick.Window 2
import QtQuick 2.0

ApplicationWindow {
    id: window
    width: 400
    height: 500
    visible: true

    Rectangle {
        x: 100
        y: 100
        width: 100
        height: 100
        color: "yellow"
        border.color: "black"
        border.width: 5
        radius: 10
    }

    ListView {
        width: 180; height: 200

        model: ContactModel {}
        delegate: Text {
            text: name + ": " + number
        }
    }

//    ListView {
//        anchors.fill: parent
//        model: ContactModel {}
//        delegate: ContactDelegate {}
//        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
//        focus: true
//    }
}
