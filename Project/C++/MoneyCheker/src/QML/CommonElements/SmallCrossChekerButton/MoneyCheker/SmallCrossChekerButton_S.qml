import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../../SmallCrossChekerButton"
import "../../../Setting"

SmallCrossChekerButton_O {
	id:root
    activMainButtonColor:settingData.oneRowItemSettings.activMainButtonColor;
    activBackgroundButtonColor:settingData.oneRowItemSettings.activBackgroundButtonColor;
    pressedMainButtonColor:settingData.oneRowItemSettings.pressedMainButtonColor;
    pressedBackgroundButtonColor:settingData.oneRowItemSettings.pressedBackgroundButtonColor;
    buttonSize:settingData.oneRowItemSettings.buttonSize;// = 2*radius
    crossSize:settingData.oneRowItemSettings.crossSize;
    checkerSize:settingData.oneRowItemSettings.checkerSize;
    checkerHeigh:settingData.oneRowItemSettings.checkerHeigh;
    checkerMargin:settingData.oneRowItemSettings.checkerMargin;
    buttonBorderWidth:settingData.oneRowItemSettings.buttonBorderWidth;
    oneRowItemBorderHeigh:settingData.oneRowItemSettings.oneRowItemBorderHeigh;
    paddingRight:settingData.oneRowItemSettings.paddingRight;
    hoveredButtonColor:settingData.oneRowItemSettings.hoveredButtonColor;
}

