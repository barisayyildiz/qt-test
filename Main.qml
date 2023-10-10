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

    UIController {
        id: backend
    }

    Image {
        source: "assets/images/rocket.png"
        width: 50
        height: 50
        y: 200
        x: 200
        rotation: backend.rotation
    }

    Column {
        spacing: 10
        Rectangle {
            Button {
                text: 'Clockwise'
                onClicked: {
                    backend.setRotation(true); // Correctly call the setIsButtonClicked function
                }
            }
        }
        Rectangle {
            Button {
                text: 'Counter-Clockwise'
                onClicked: {
                    backend.setRotation(false); // Correctly call the setIsButtonClicked function
                }
            }
            y: 100
        }
    }

}
