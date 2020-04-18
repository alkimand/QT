import Settings 1.0
import "../"
import "../../SmallCrossChekerButton/MoneyCheker"
import "../RowLogic.js" as Logic
OneRowItem_O {
    id:root

    //COMMON
    commonFontFamily: Settings.oneRowItemSettings.commonFontFamily;
    backgroundColor: Settings.oneRowItemSettings.backgroundColor;
    backgroundFontColor: Settings.appContentWidgetSettings.disactiveFontColor;
    rowItemWidth: Settings.appContentWidgetSettings.contentCalculatorPageWidth;
    rowItemHeight:Settings.oneRowItemSettings.rowItemHeight;
    rowMargin:Settings.oneRowItemSettings.rowMargin;
    paddingLeft:Settings.oneRowItemSettings.paddingLeft;
    paddingRight:Settings.oneRowItemSettings.paddingRight;
    textSecondLineType: Logic.DataType.CURRENCY_DATA_TYPE
    textRowSpacing: Settings.oneRowItemSettings.textRowSpacing;
    hasBorder:Settings.HasBorder.NO_BORDER
    borderRadius: Settings.appContentWidgetSettings.borderRadius;


    //textLine
    textBlockWidth:Settings.oneRowItemSettings.textBlockWidth;
    textFirstLineFontColor:Settings.oneRowItemSettings.textFirstLineFontColor;
    textSecondLineFontColor: Settings.oneRowItemSettings.textSecondLineFontColor;
    textFirstLineTopMargin: Settings.oneRowItemSettings.textFirstLineTopMargin;
    textFirstLineFontSize:Settings.oneRowItemSettings.textFirstLineFontSize;
    textSecondLineFontSize:Settings.oneRowItemSettings.textSecondLineFontSize;
    textSecondLine: "";

    //Label
    labelFontColor: Settings.oneRowItemSettings.labelFontColor;
    labelРighlightingFontColor: Settings.oneRowItemSettings.labelРighlightingFontColor;
    labelFontSize: Settings.oneRowItemSettings.labelFontSize;
    labelBorderColorWidth:Settings.oneRowItemSettings.labelBorderColorWidth;
    labelLeftPadding:Settings.oneRowItemSettings.labelLeftPadding;
    labelMargins:Settings.oneRowItemSettings.labelMargins;


    //Button
    activMainButtonColor:Settings.oneRowItemSettings.activMainButtonColor;
    activBackgroundButtonColor:Settings.oneRowItemSettings.activBackgroundButtonColor;
    pressedMainButtonColor:Settings.oneRowItemSettings.pressedMainButtonColor;
    pressedBackgroundButtonColor:Settings.oneRowItemSettings.pressedBackgroundButtonColor;
    buttonSize:Settings.oneRowItemSettings.buttonSize;// = 2*radius
    crossSize:Settings.oneRowItemSettings.crossSize;
    checkerSize:Settings.oneRowItemSettings.checkerSize;
    checkerMargin:Settings.oneRowItemSettings.checkerMargin;
    buttonBorderWidth:Settings.oneRowItemSettings.buttonBorderWidth;
    oneRowItemBorderHeigh:Settings.oneRowItemSettings.oneRowItemBorderHeigh;
    checkerHeigh:Settings.oneRowItemSettings.checkerHeigh;

    //combobox and date combo animation
    tottallAnimationTime: Settings.oneRowItemSettings.tottallAnimationTime;

}





