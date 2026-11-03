import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QGroundControl
import QGroundControl.Controls
import QGroundControl.Controllers
import QGroundControl.Palette
import QGroundControl.ScreenTools

Popup {
    id: root
    parent: Overlay.overlay
    width: Math.min(parent.width - 24, ScreenTools.defaultFontPixelWidth * 156)
    height: Math.min(parent.height - 24, ScreenTools.defaultFontPixelHeight * 29)
    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    padding: ScreenTools.defaultFontPixelWidth * 1.5
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape

    property var activeVehicle: QGroundControl.multiVehicleManager.activeVehicle
    readonly property real cellUnit: ScreenTools.defaultFontPixelWidth
    readonly property var columnWidths: [6, 8, 8, 10, 9, 10, 10, 8, 8, 8, 13, 13, 9, 10]
    readonly property var columnTitles: [qsTr("编号"), qsTr("方位(°)"), qsTr("俯仰(°)"), qsTr("距离(m)"),
                                         qsTr("高度(m)"), qsTr("速度(m/s)"), qsTr("幅度(dB)"), qsTr("置信度"),
                                         qsTr("状态"), qsTr("类型"), qsTr("经度(°)"), qsTr("纬度(°)"),
                                         qsTr("更新前(s)"), qsTr("操作")]
    readonly property real tableWidth: columnWidths.reduce(function(total, value) { return total + value }, 0) * cellUnit

    function numberText(value, decimals) {
        return isFinite(value) ? Number(value).toFixed(decimals) : "—"
    }

    function stateText(value) {
        switch (value) {
        case 0x11: return qsTr("搜索")
        case 0x22: return qsTr("跟踪")
        case 0x44: return qsTr("仅跟踪")
        default: return "0x" + value.toString(16).toUpperCase()
        }
    }

    QGCPalette { id: radarPalette; colorGroupEnabled: true }

    background: Rectangle {
        color: radarPalette.window
        border.color: radarPalette.text
        radius: 6
    }

    contentItem: ColumnLayout {
        spacing: ScreenTools.defaultFontPixelHeight * 0.5

        RowLayout {
            Layout.fillWidth: true
            QGCLabel {
                text: qsTr("雷达无人机目标 · %1 架").arg(RadarBridge.targets.count)
                font.bold: true
                font.pointSize: ScreenTools.largeFontPointSize
                Layout.fillWidth: true
            }
            QGCButton {
                text: qsTr("关闭")
                onClicked: root.close()
            }
        }

        QGCLabel {
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            text: RadarBridge.receiving
                  ? qsTr("监听 UDP %1 · 仅显示显控标记为无人机的目标 · 6 秒未更新自动移除").arg(RadarBridge.listenPort)
                  : qsTr("雷达 UDP 监听未就绪，请检查端口与接收日志。")
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumHeight: ScreenTools.defaultFontPixelHeight * 5
            color: radarPalette.windowShade
            border.color: radarPalette.text
            clip: true

            Flickable {
                id: horizontalViewport
                anchors.fill: parent
                anchors.margins: 1
                contentWidth: Math.max(width, root.tableWidth)
                contentHeight: height
                flickableDirection: Flickable.HorizontalFlick
                boundsBehavior: Flickable.StopAtBounds
                clip: true
                ScrollBar.horizontal: ScrollBar {
                    policy: horizontalViewport.contentWidth > horizontalViewport.width
                            ? ScrollBar.AlwaysOn : ScrollBar.AlwaysOff
                }

                Column {
                    width: horizontalViewport.contentWidth
                    height: horizontalViewport.height - ScreenTools.defaultFontPixelHeight * 0.75

                    Row {
                        id: headerRow
                        width: parent.width
                        height: ScreenTools.defaultFontPixelHeight * 2.3
                        Repeater {
                            model: root.columnTitles
                            delegate: Rectangle {
                                required property int index
                                required property string modelData
                                width: root.columnWidths[index] * root.cellUnit
                                height: headerRow.height
                                color: radarPalette.windowShadeDark
                                QGCLabel {
                                    anchors.fill: parent
                                    anchors.margins: root.cellUnit * 0.4
                                    text: modelData
                                    font.bold: true
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    elide: Text.ElideRight
                                }
                            }
                        }
                    }

                    ListView {
                        id: targetList
                        width: parent.width
                        height: parent.height - headerRow.height
                        model: RadarBridge.targets
                        clip: true
                        boundsBehavior: Flickable.StopAtBounds
                        ScrollBar.vertical: ScrollBar {
                            x: horizontalViewport.contentX + horizontalViewport.width - width
                            policy: ScrollBar.AsNeeded
                        }
                        delegate: Rectangle {
                            id: targetRow
                            required property int index
                            required property int targetId
                            required property real latitude
                            required property real longitude
                            required property real altitude
                            required property real speed
                            required property real distance
                            required property real azimuth
                            required property real elevation
                            required property int trackType
                            required property int targetAttribute
                            required property real ageSeconds
                            readonly property var cells: [String(targetId), root.numberText(azimuth, 2),
                                                          root.numberText(elevation, 2), root.numberText(distance, 1),
                                                          root.numberText(altitude, 1), root.numberText(speed, 2),
                                                          "—", "—", root.stateText(targetAttribute),
                                                          qsTr("无人机"), root.numberText(longitude, 7),
                                                          root.numberText(latitude, 7), root.numberText(ageSeconds, 1)]
                            width: targetList.width
                            height: ScreenTools.defaultFontPixelHeight * 2.5
                            color: index % 2 === 0 ? radarPalette.window : radarPalette.windowShade

                            Row {
                                anchors.fill: parent
                                Repeater {
                                    model: targetRow.cells
                                    delegate: Item {
                                        required property int index
                                        required property string modelData
                                        width: root.columnWidths[index] * root.cellUnit
                                        height: targetRow.height
                                        QGCLabel {
                                            anchors.fill: parent
                                            anchors.margins: root.cellUnit * 0.4
                                            text: modelData
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                            elide: Text.ElideRight
                                        }
                                    }
                                }
                                Item {
                                    width: root.columnWidths[13] * root.cellUnit
                                    height: targetRow.height
                                    QGCButton {
                                        anchors.centerIn: parent
                                        width: parent.width - root.cellUnit
                                        text: qsTr("跟随")
                                        enabled: !!root.activeVehicle && !RadarBridge.followBusy && targetRow.ageSeconds < 6
                                        onClicked: RadarBridge.followTarget(targetRow.targetId)
                                    }
                                }
                            }
                        }
                    }
                }
            }

            QGCLabel {
                anchors.centerIn: parent
                width: parent.width - root.cellUnit * 4
                visible: targetList.count === 0
                text: qsTr("暂无无人机目标\n等待显控发送目标数据；超时目标会自动从列表移除。")
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
            }
        }

        QGCLabel {
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            text: root.activeVehicle
                  ? qsTr("跟随指令发送至当前飞行器 %1；目标更换编号后需重新选择跟随。").arg(root.activeVehicle.id)
                  : qsTr("连接飞行器后可使用“跟随”；雷达目标接收与显示不受影响。")
        }
        QGCLabel {
            Layout.fillWidth: true
            visible: RadarBridge.followStatus.length > 0
            text: RadarBridge.followStatus
            wrapMode: Text.WordWrap
        }
        QGCLabel {
            Layout.fillWidth: true
            text: qsTr("当前 LD041 帧未提供幅度与置信度，这两列显示为 —。")
            font.pointSize: ScreenTools.smallFontPointSize
            wrapMode: Text.WordWrap
        }
    }
}
