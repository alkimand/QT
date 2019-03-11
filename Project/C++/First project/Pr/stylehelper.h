#ifndef STYLEHELPER_H
#define STYLEHELPER_H

#include <QWidget>
#include <QString>
class StyleHelper
{
public:
    StyleHelper();
    static QString getWindowStyleSheet();//--
    static QString getMainPanelStyleSheet();//++
    static QString getContactsPanelStyleSheet();//++
    static QString getVisitsPanelStyleSheet();//++
    static QString getLabelStyleSheet();//++
    static QString getMainViewSheet();//++
    static QString getQTableViewSheet();//++

    static QString getCloseStyleSheet();
    static QString getMaximizeStyleSheet();
    static QString getRestoreStyleSheet();
    static QString getMinimizeStyleSheet();
    static QString getNextStyleSheet();
    static QString getPreviousStyleSheet();
    static QString getStopStyleSheet();
    static QString getPlayStyleSheet();
    static QString getPauseStyleSheet();






    static QString getMenuStyleSheet();//--
    static QString getTableViewStyleSheet();//++
    static QString getQSplitterSheet();//++
    static QString getQLineEditSheet();//++
    static QString getQLineEditTableWiewSheet();//++
    static QString getQPushbuttonAddSheet();//++
    static QString getQSpinButtonSheet();//++
    static QString getQComboboxSheet();//++
    static QString getQDateEditSheet();//++
    static QString getQDateEditTableWiewSheet();//++
};

#endif // STYLEHELPER_H
