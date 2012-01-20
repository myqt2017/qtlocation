/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/
import QtQuick 2.0;
import QtLocation 5.0
import QtMultimedia 4.0

// NOTE: If the creation of this compoment fails, make sure you have the latest
// qtmultimedia and relevant gstreamer etc packages installed.
// You can test your system with qtmultimedia examples.
MapQuickItem {  //to be used inside MapComponent only
    id: testVideoItem

    coordinate: Coordinate { latitude : 0; longitude : 0 }
    //    zoomLevel: 8 // set this if you want the video to follow zoom level changes

    function setGeometry(markers, index) {
        coordinate.latitude = markers[index].coordinate.latitude
        coordinate.longitude = markers[index].coordinate.longitude
    }

    sourceItem: Rectangle {
        id: testVideo
        color: "black"
        x: 0;
        y: 0;
        z: 500
        width: 176;
        height: 144;
        MediaPlayer {
            id: player
            source: Qt.resolvedUrl("../../demo.ogv")
            playing: true

            onError: {
                if (MediaPlayer.NoError != error) {
                    console.log(errorString)
                }
            }
        }
        VideoOutput {
            id: videoItem
            source: player
            anchors.fill: parent
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if (player.playing)
                        player.stop()
                    else
                        player.play()
                }
            }
        }
    }
}