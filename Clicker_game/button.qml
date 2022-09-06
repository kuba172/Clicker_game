import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    Button
    {
        objectName: "button"
        height:100
        width:200
        flat: true
        contentItem: Text {
                font.family: "Comic Sans MS";
                color: start_button.down ? "#ff00ff":(start_button.hovered ? "#ffff00" : "#ff00ff")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 60;
                elide: Text.ElideRight
           }
        background: Rectangle {
                      opacity: enabled ? 1 : 0.3
                      color: start_button.down ? "#ffff00":(start_button.hovered ? "#ff00ff" : "#ffff00")
                      border.color: start_button.down ? "#ffff00" : "#ff00ff"
                      border.width: 1
                      radius: 20
        }
    }

}
