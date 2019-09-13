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
            id: logDataListView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth:400
            Layout.preferredWidth:400
            Layout.topMargin:4
            Layout.rightMargin:4
            spacing: -1

            clip: true

            model: LogDataQStringListViewModel

            onCountChanged: {
                console.log("Count Changed!");
                logDataListView.positionViewAtEnd();
            }

            delegate: Rectangle {
                width: parent.width
                height: 25
                border.width:1
                border.color: "#000000"

                Layout.fillWidth: true
                Layout.fillHeight: true

                Text {
                    padding: 4
                    text: display
                }
            }
        }
    }
}