import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../../SmallCrossChekerButton"
import Settings 1.0

SmallCrossChekerButton_O {
	id:root
    activMainButtonColor:Settings.oneRowItemSettings.activMainButtonColor;
    activBackgroundButtonColor:Settings.oneRowItemSettings.activBackgroundButtonColor;
    pressedMainButtonColor:Settings.oneRowItemSettings.pressedMainButtonColor;
    pressedBackgroundButtonColor:Settings.oneRowItemSettings.pressedBackgroundButtonColor;
    buttonSize:Settings.oneRowItemSettings.buttonSize;// = 2*radius
    crossSize:Settings.oneRowItemSettings.crossSize;
    checkerSize:Settings.oneRowItemSettings.checkerSize;
    checkerHeigh:Settings.oneRowItemSettings.checkerHeigh;
    checkerMargin:Settings.oneRowItemSettings.checkerMargin;
    buttonBorderWidth:Settings.oneRowItemSettings.buttonBorderWidth;
    oneRowItemBorderHeigh:Settings.oneRowItemSettings.oneRowItemBorderHeigh;
    paddingRight:Settings.oneRowItemSettings.paddingRight;
    hoveredButtonColor:Settings.oneRowItemSettings.hoveredButtonColor;
}

