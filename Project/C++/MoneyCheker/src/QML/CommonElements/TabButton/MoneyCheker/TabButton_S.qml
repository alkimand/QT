import Settings 1.0
import "../"

TabButton_O {
    width: Settings.appContentWidgetSettings.contentCalculatoButtonWidth;
    height: Settings.appContentWidgetSettings.buttonHeight;
    radius: Settings.appContentWidgetSettings.borderRadius;
    activeColor: Settings.buttonSettings.buttonIsSelectedColorSetting;
    disactiveColor: Settings.buttonSettings.buttonIsNotSelectedColorSetting;
    activeFontColor: Settings.appContentWidgetSettings.activeFontColor;
    disactiveFontColor:Settings.appContentWidgetSettings.disactiveFontColor;
    tabIconTextMargin: Settings.appContentWidgetSettings.iconMarginTop;
    iconTextMargin:Settings.appContentWidgetSettings.tabiconTextMargin;
    fontSize:Settings.appContentWidgetSettings.fontSize;
    iconSize:Settings.appContentWidgetSettings.iconSize;
    fontFamily:Settings.appContentWidgetSettings.tabFontFamily;
    backgroundColor:Settings.columnSettings.columnFreeSpaceColor;
}
