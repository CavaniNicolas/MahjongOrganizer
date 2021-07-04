import QtQuick
import QtQuick 2.2
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
import QtQuick.Window

ApplicationWindow {
    id: window
    width: 400
    height: 500
    visible: true

    Rectangle {
        width: 100
        height: 100
        color: "blue"
        border.color: "black"
        border.width: 5
        radius: 10
    }

}
