//Второй лист КТП
#ifndef KTP_2_WIDGET_H
#define KTP_2_WIDGET_H

#include <QMap>
#include <QWidget>
#include "generaltoolwidget.h"

class QLabel;
class QLineEdit;
class QDateEdit;
class QComboBox;
class GeneralProduct;

class KTP_2_Widget : public GeneralToolWidget
{
    Q_OBJECT
public:

    explicit KTP_2_Widget(QWidget *parent = nullptr);
private :
    void initpage(){};

    GeneralToolWidget *parent;

    QLabel *NumberTrLabel;//0
    QLabel *TypeTrLabel;
    QLabel *PowerTrLabel;

    QLabel *PackageTypeLabel;
    QLabel *PackageSizeLabel;//4

    QLabel *HighVoltageLabel;
    QLabel *MaxHighVoltageLabel;
    QLabel *LowVoltageLabel;//7

    QLabel *NameProductLabel;
    QLabel *MassLabel;
    QLabel *ClimaticVersionLabel;//10
    QLabel *DegreeProtectionLabel;//11

    QComboBox *NumberTrComboBox;//0
    QComboBox *TypeTrComboBox;//1

    QComboBox *PowerTrComboBox;

    QComboBox *PackageTypeComboBox;
    QComboBox *PackageSizeComboBox;//4

    QComboBox *HighVoltageComboBox;
    QComboBox *MaxHighVoltageComboBox;
    QComboBox *LowVoltageComboBox;//7
    QLineEdit *NameProductQLineEdit;
    QLineEdit *MassQLineEdit;
    QComboBox *ClimaticVersionComboBox;//10
    QComboBox *DegreeProtectionComboBox;//11

    QString pagename;
    QString getpagename();
signals:
   // void setProductTupetoToolWidget(const QString & );


private slots:
    void test();
    //void getProductTupefromQComboBox(const QString & );

};

#endif // KTP_2_WIDGET_H
