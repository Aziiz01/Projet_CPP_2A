import QtQuick 2.0
import QtLocation 5.6

Rectangle{
   Plugin{
       id: mapPlugin
       name: "asm"
   }


    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(59.91, 10.75)
        zoomLevel: 14
    }
}
