
import QtQuick 2.0
import QtQuick.Controls 2.15

Item {

    property alias formErrorDialog: formErrorDialog
    property alias unsavedChangesDialog: unsavedChangesDialog
    property int fontSize: 16

    Dialog {
        id: formErrorDialog
        title: qsTr("New Player Form Error")
        anchors.centerIn: parent
        font.pixelSize: fontSize

        modal: true
        standardButtons: Dialog.Ok

        property alias text: textLabel1.text

        Label {
            id: textLabel1
            text: "Error saving new player, make sure to fill the entire form.
The new player was not added."
        }
    }

    Dialog {
        id: unsavedChangesDialog
        title: qsTr("Unsaved Changes")
        anchors.centerIn: parent
        font.pixelSize: fontSize

        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel

        property alias text: textLabel2.text

        onAccepted: {
            window.canClose = true
            window.close()
        }

        Label {
            id: textLabel2
            text: "You have unsaved changes, are you sure you want to quit ?"
        }

    }

}
