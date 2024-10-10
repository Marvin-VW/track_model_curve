// Copyright (C) 2023 twyleg
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts

import "./items"

ApplicationWindow
{
    id: app

    visible: true
    width: 1920
    height: 1080
    title: qsTr("Minimal Qml Live Image Viewer")

    Row {
        width: parent.width
        height: parent.height

        Column {
            width: 400
            spacing: 10

            AdvancedSlider {
                id: positionX
                width: parent.width
                name: "positionX"
                from: 0
                to: 20000
                value: parameterModel.positionX
                stepSize: 1
                onValueChanged: parameterModel.positionX = value
            }

            AdvancedSlider {
                id: positionY
                width: parent.width
                name: "positionY"
                from: 0
                to: 20000
                value: parameterModel.positionY
                stepSize: 1
                onValueChanged: parameterModel.positionY = value
            }


            AdvancedSlider {
                id: curve_radius
                width: parent.width
                name: "curve_radius"
                from: 1
                to: 2000
                value: parameterModel.curve_radius
                stepSize: 1
                onValueChanged: parameterModel.curve_radius = value
            }

            AdvancedSlider {
                id: track_width
                width: parent.width
                name: "track_width"
                from: 1
                to: 2000
                value: parameterModel.track_width
                stepSize: 1
                onValueChanged: parameterModel.track_width = value
            }

            AdvancedSlider {
                id: dashed_length
                width: parent.width
                name: "dashed_length"
                from: 1
                to: 1000
                value: parameterModel.dashed_length
                stepSize: 1
                onValueChanged: parameterModel.dashed_length = value
            }

            AdvancedSlider {
                id: dashed_space
                width: parent.width
                name: "dashed_space"
                from: 1
                to: 1000
                value: parameterModel.dashed_space
                stepSize: 1
                onValueChanged: parameterModel.dashed_space = value
            }

            AdvancedSlider {
                id: line_width
                width: parent.width
                name: "line_width"
                from: 1
                to: 100
                value: parameterModel.line_width
                stepSize: 1
                onValueChanged: parameterModel.line_width = value
            }

            AdvancedSlider {
                id: curved_angle_start
                width: parent.width
                name: "curved_angle_start"
                from: 0
                to: 360
                value: parameterModel.curved_angle_start
                stepSize: 1
                onValueChanged: parameterModel.curved_angle_start = value
            }

            AdvancedSlider {
                id: curved_angle_end
                width: parent.width
                name: "curved_angle_end"
                from: 0
                to: 360
                value: parameterModel.curved_angle_end
                stepSize: 1
                onValueChanged: parameterModel.curved_angle_end = value
            }

            AdvancedSwitch {
                name: "dashed_left"
                width: parent.width
                onValueChanged: parameterModel.dashed_left = value
            }


            AdvancedSwitch {
                name: "dashed_right"
                width: parent.width
                onValueChanged: parameterModel.dashed_right = value
            }

            AdvancedSlider {
                id: subdivisions
                width: parent.width
                name: "subdivisions"
                from: 0
                to: 200
                value: parameterModel.subdivisions
                stepSize: 1
                onValueChanged: parameterModel.subdivisions = value
            }

        }

        Image {
            id: testImage
            width: 1280
            height: 960
            cache: false
            source: "image://stream/" + id
            property int id: 0

            function reload() {
                id++;
            }
        }
    }

    Connections {
        target: imageModel

        function onImageChanged() {
            testImage.reload()
        }
    }

}

