import QtQuick 2.6
import QtQuick.Controls 2.0
import org.calamares.yddx 1.0

ApplicationWindow {
    id: root
    width: 300
    height: 480
    visible: true

    Yddx {
        id: yddx
    }

    TextField {
        text: yddx.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: yddx.userName = text
    }
}
