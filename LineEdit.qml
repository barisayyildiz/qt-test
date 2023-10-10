import QtQuick

Rectangle {
    border.color: "black"
    width: 100
    height: 20
    color: "white"
    radius: 4
    smooth: true
    clip: true
    TextInput {
        anchors.fill: parent
        anchors.margins: 2
        text: 'Enter text...'
        color: focus ? "black" : "grey"
        font.pixelSize: parent.height - 4
    }
}
