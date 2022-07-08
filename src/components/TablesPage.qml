import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

Item {
    id: mahjongApp

    property int fontSize: 20

    RowLayout {
        id: rowMainTables
        anchors.fill: parent
        spacing: 0

        ColumnLayout {
            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true

                TablesView {
                    id: tablesView
                    width: parent.width * 9 / 10
                    height: parent.height * 9 / 10
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    orientation: Qt.Vertical
                    verticalLayoutDirection: ListView.TopToBottom
                }
            }
        }
    }

}
