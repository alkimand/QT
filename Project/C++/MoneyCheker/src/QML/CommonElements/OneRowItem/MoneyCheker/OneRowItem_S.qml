import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../../../Setting"
import "../"
import "../../SmallCrossChekerButton/MoneyCheker"

OneRowItem_O {
    id:root

    //COMMON
    commonFontFamily: settingData.oneRowItemSettings.commonFontFamily;
    backgroundColor: settingData.oneRowItemSettings.backgroundColor;
    backgroundFontColor: settingData.appContentWidgetSettings.disactiveFontColor;
    rowItemWidth: settingData.appContentWidgetSettings.contentCalculatorPageWidth;
    rowItemHeight:settingData.oneRowItemSettings.rowItemHeight;
    rowMargin:settingData.oneRowItemSettings.rowMargin;
    paddingLeft:settingData.oneRowItemSettings.paddingLeft;
    paddingRight:settingData.oneRowItemSettings.paddingRight;
    textSecondLineType: SettingData.DataType.CURRENCY_DATA_TYPE;
    textRowSpacing: settingData.oneRowItemSettings.textRowSpacing;
    hasBorder:SettingData.HasBorder.NO_BORDER
    borderRadius: settingData.appContentWidgetSettings.borderRadius;


    //textLine
    textBlockWidth:settingData.oneRowItemSettings.textBlockWidth;
    textFirstLineFontColor:settingData.oneRowItemSettings.textFirstLineFontColor;
    textSecondLineFontColor: settingData.oneRowItemSettings.textSecondLineFontColor;
    textFirstLineTopMargin: settingData.oneRowItemSettings.textFirstLineTopMargin;
    textFirstLineFontSize:settingData.oneRowItemSettings.textFirstLineFontSize;
    textSecondLineFontSize:settingData.oneRowItemSettings.textSecondLineFontSize;
    textSecondLine: ""


    //Label
    labelFontColor:settingData.oneRowItemSettings.labelFontColor;
    labelРighlightingFontColor:settingData.oneRowItemSettings.labelРighlightingFontColor;
    labelFontSize:settingData.oneRowItemSettings.labelFontSize;
    labelBorderColorWidth:settingData.oneRowItemSettings.labelBorderColorWidth;
    labelLeftPadding:settingData.oneRowItemSettings.labelLeftPadding;
    labelMargins:settingData.oneRowItemSettings.labelMargins;


    //Button
    activMainButtonColor:settingData.oneRowItemSettings.activMainButtonColor;
    activBackgroundButtonColor:settingData.oneRowItemSettings.activBackgroundButtonColor;
    pressedMainButtonColor:settingData.oneRowItemSettings.pressedMainButtonColor;
    pressedBackgroundButtonColor:settingData.oneRowItemSettings.pressedBackgroundButtonColor;
    buttonSize:settingData.oneRowItemSettings.buttonSize;// = 2*radius
    crossSize:settingData.oneRowItemSettings.crossSize;
    checkerSize:settingData.oneRowItemSettings.checkerSize;
    checkerMargin:settingData.oneRowItemSettings.checkerMargin;
    buttonBorderWidth:settingData.oneRowItemSettings.buttonBorderWidth;
    oneRowItemBorderHeigh:settingData.oneRowItemSettings.oneRowItemBorderHeigh;
    checkerHeigh:settingData.oneRowItemSettings.checkerHeigh;

}





