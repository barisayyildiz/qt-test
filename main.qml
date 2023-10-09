import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "3D Object Viewer"

    Button {
        id: myButton
        anchors.centerIn: parent
        text: "Click me"
        onClicked: classA.callMe()
    }
}
