import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.13
import toy.qt 1.0

ApplicationWindow {
    id: root
    minimumWidth: 640
    height: 480
    visible: true
//    color: "#21301f"

    Text1 {
        id: backend
    }

    RowLayout {
        id: rlayout
        anchors.fill: parent
        spacing:3

        Rectangle {
            color: 'teal'
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth:230
            Layout.maximumWidth:230


            Slider {
                id: dropRateSlider
                anchors.centerIn: parent

                value: 1
                onValueChanged: {
                    drp.setDropRate(value)
                    dropRateText.text = (value*100).toFixed(1) + "%"
                }
            }

            Text {
                id: dropRateText

                anchors.horizontalCenter: dropRateSlider.horizontalCenter
                anchors.top: dropRateSlider.bottom

                text: "100%"
            }
        }

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth:400
            Layout.preferredWidth:400
            Layout.topMargin:4
            Layout.rightMargin:4

            clip: true

            model: ListModel {
                ListElement {
                    done: true
                    desc: "Test Desc"
                }
            }

            delegate: RowLayout {
                width: parent.width

                CheckBox {}
                TextField {
                    Layout.fillWidth: true
                }
            }
        }
    }
}