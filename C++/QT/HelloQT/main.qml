import QtQuick 2.9
import QtQuick.Window 2.3

Window
{
    visible: true
    width: 1024
    height: 768
    title: qsTr("Hello QT")
    color: "#ffffff"

    Text
    {
        id: message
        anchors.centerIn: parent
        font.pixelSize: 44
        text: qsTr("Ciao QT!")
        color: "#008000"
    }
}
