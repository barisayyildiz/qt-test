import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15
import Monty 1.0

Window {
    width: 600
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "lightblue"

    Rectangle {
        anchors.fill: parent
        Loader {
            id: loader
            source: "LineEdit.qml"
            anchors { left: parent.left; right: parent.right; top: parent.top }
        }
        Text {
            id: txt1
            text: "Binding: " + (loader.item ? loader.item.text : "")
            anchors { left: parent.left; right: parent.right; top: parent.top }
        }

        Text {
            id: txt2
            anchors { left: parent.left; right: parent.right; top: parent.top }
        }

        Binding {
            target: loader.item
            property: "Text"
        }

    }

}
