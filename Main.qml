import QtQuick
import QtQuick.Controls
import UserList 1.0
import Shapes 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Test")

    Rectangle {
        anchors.fill: parent
        color: "lightblue"

        EllipseItem {
            id: ellipse
            anchors.fill: parent
            anchors.margins: 50
            color: "red"
        }

        Timer {
            interval: 2000
            running: true
            onTriggered: ellipse.color = "orange"
        }

    }
}
