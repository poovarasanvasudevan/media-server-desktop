import QtQuick.Controls 2.1
import QtQuick 2.7
import QtQuick.Layouts 1.2

ApplicationWindow {
    visible: true
    width: 480
    height: 320
    minimumHeight: 320
    maximumHeight: 320
    minimumWidth: 480
    maximumWidth: 320



    title: "Office Application"


    Button {
        id: button
        x: 183
        y: 140
        text: qsTr("Join a Meeting")
        rightPadding: 16
        leftPadding: 16
    }


}
