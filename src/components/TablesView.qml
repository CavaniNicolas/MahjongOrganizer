import QtQuick 2.0

ListView {
    width: 200; height: 250

    model: playerModel
    delegate: TablesDelegate {}


    Component {
        id: sectionHeading

        Rectangle {
            width: parent.width
            height: childrenRect.height
            color: "lightgreen"

            required property string section

            Text {
                text: parent.section
                font.bold: true
                font.pixelSize: 25
            }
        }
    }

    section.property: "table"
    section.criteria: ViewSection.FullString
    section.delegate: sectionHeading
    section.labelPositioning: ViewSection.InlineLabels
}
