import QtQuick
import Backend

Window {

    width: 2560
    height: 1600
    visible: true
    title: qsTr("DailyWallpaper")

    Backend {
        id: be
    }

    Image {
        id: imageHeader
        sourceSize.width: 1920
        sourceSize.height: 1080
        anchors.centerIn: parent
        // source: "qrc:/image/lasa.jpg"
        source: "https://www.bing.com/th?id=OHR.FloresIsland_ZH-CN6930246149_1920x1200.jpg&rf=LaDigue_1920x1200.jpg"
    }

    Rectangle {
        width: parent.width
        height: parent.height
        MouseArea {
            width: parent.width
            height: parent.height

            onClicked: {
                be.getJson()
            }
        }
    }

}
