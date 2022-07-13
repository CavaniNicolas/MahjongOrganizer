import QtQuick 2.0

ListView {
    id: playersView
    width: 200; height: 250

    model: playerModel
    delegate: PlayersDelegate {
        width: playersView.width
        height: 50
    }


    Component {
        id: sectionHeading

        Rectangle {
            width: parent.width
            height: childrenRect.height
            color: "lightsteelblue"

            required property string section

            Text {
                text: " " // parent.section
                font.bold: true
                font.pixelSize: 25
            }
        }
    }

    section.property: "level"
    section.criteria: ViewSection.FullString
    section.delegate: sectionHeading
    section.labelPositioning: ViewSection.InlineLabels
}
