import QtQuick 2.0

Item {
    id: item

    property string label: ""

    signal customClicked
    onCustomClicked: {txt.text = "Clicked!"}

    height: 100
    width: 100

    Rectangle {
        id: rct
        color: "purple"
        height: item.width
        width: item.width

        Text {
            id: txt
            anchors.centerIn: parent
            font.pointSize: 14
            text: item.label
            color: "#ffffff"
        }
    }
}
