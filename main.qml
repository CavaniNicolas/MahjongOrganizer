import QtQuick 2.2
import QtQuick.Controls 2
import QtQuick.Controls.Material 2
import QtQuick.Layouts 1
import QtQuick.Window 2

ApplicationWindow {
    id: window
    width: 400
    height: 500
    visible: true

    Rectangle {
        width: 100
        height: 100
        color: "yellow"
        border.color: "black"
        border.width: 5
        radius: 10
    }

}
