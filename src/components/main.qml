import QtQuick.Controls 2
import QtQuick 2.12

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


    Rectangle {
        width: 180; height: 200

        Component {
            id: contactDelegate
            Item {
                width: 180; height: 40
                Column {
                    Text { text: '<b>Name:</b> ' + name }
                    Text { text: '<b>Number:</b> ' + number }
                }
            }
        }

        ListView {
            anchors.fill: parent
            model: ContactModel {}
            delegate: contactDelegate
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true
        }
    }
}
