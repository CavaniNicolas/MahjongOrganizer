
import QtQuick 2.0
import QtQuick.Controls 2.15

Item {

    property alias formErrorDialog: formErrorDialog
    property alias unsavedChangesDialog: unsavedChangesDialog
    property alias saveMembersConfirmationDialog: saveMembersConfirmationDialog
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

    Dialog {
        id: saveMembersConfirmationDialog
        title: qsTr("Confirm Save")
        anchors.centerIn: parent
        font.pixelSize: fontSize

        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel

        property alias text: textLabel3.text

        onAccepted: {
            mahjongApp.saveMembersInFile()
            window.canClose = true
        }

        Label {
            id: textLabel3
            text: "You are about to save members, are you sure ?"
        }
    }

}
