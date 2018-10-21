import QtQuick 2.6
import QtQuick.Controls 2.0
import org.calamares.widget 1.0

ApplicationWindow {
    id: root
    width: 300
    height: 480
    visible: true

    Widget {
        id: widget
    }

    TextField {
        text: widget.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: widget.userName = text
    }
}
