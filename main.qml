// Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick 2.1
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtQuick3D
import QtQuick.Controls 2.15
import QtQuick.Scene3D 2.6

Rectangle {
    anchors.fill: parent

    Scene3D {
        anchors.fill: parent
        focus: true
        aspects: ["input, logic"]
        Entity {
            id: root

            // Render from the mainCamera
            components: [
                RenderSettings {
                    activeFrameGraph: ForwardRenderer {
                        id: renderer
                        camera: mainCamera
                    }
                },
                // Event Source will be set by the Qt3DQuickWindow
                InputSettings { }
            ]

            BasicCamera {
                id: mainCamera
                position: Qt.vector3d( 23.0, 6.0, 20.0 )
            }

            FirstPersonCameraController { camera: mainCamera }

            WireframeMaterial {
                id: wireframeMaterial
                effect: WireframeEffect {}
                ambient: Qt.rgba( 0.2, 0.0, 0.0, 1.0 )
                diffuse: Qt.rgba( 0.8, 0.0, 0.0, 1.0 )
            }

            TrefoilKnot {
                id: trefoilKnot
                material: wireframeMaterial
            }

            TrefoilKnot {
                id: trefoilKnot2
                x: 10
                material: wireframeMaterial
            }


            Node {
                x: 0
                y: 0
                eulerRotation.y: 0
                Rectangle {
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: "orange"
                    width: text.width+10
                    height: text.height+10
                    Text {
                        anchors.centerIn: parent
                        id: text
                        text: "I'm Suzanne"
                        font.pointSize: 14
                        color: "black"
                    }
                }
            }
        }

    }
    Text {
        id: title
        text: qsTr("TITLE")
        font.family: "Arial"
        font.pointSize: 30
        color: "black"

        anchors.top:parent.top
        anchors.left:parent.left
        anchors.leftMargin: 20
        anchors.topMargin: 20
    }
}
