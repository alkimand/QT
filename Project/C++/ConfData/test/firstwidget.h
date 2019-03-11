//Первый лист - виджет внутри firstwidget (tab)
#ifndef FIRSTWIDGET_H
#define FIRSTWIDGET_H
#include <QMap>
#include <QWidget>
#include "generaltoolwidget.h"
//#include "toolwidget.h"

class QLabel;
class QLineEdit;
class QDateEdit;
class QComboBox;
class GeneralProduct;

//class FirstWidget : public QWidget
class FirstWidget : public GeneralToolWidget
{
    Q_OBJECT
public:

    explicit FirstWidget(QWidget *parent = nullptr);
private :
    GeneralToolWidget *parent;
    //void SetObjectPage();
    //всегда 2 стринга
    //QMultiMap <QString, QString> FirstWidgetMap;

    QLabel *TypeLabel;
    QLabel *TYLabel;
    QLabel *NumberLabel;
    QLabel *PMnumberLabel;
    QLabel *DateCreationLabel;
    //QLabel *Marks;

    //QLineEdit *TypeQLineEdit;
    QComboBox *TypeQComboBox;

    QLineEdit *TYQLineEdit;
    QLineEdit *NumberQLineEdit;
    QLineEdit *PMnumberQLineEdit;
    QDateEdit *DateCreation;
    QString pagename;
    QString getpagename();
    void initpage(){};
signals:
   // void setProductTupetoToolWidget(const QString & );


private slots:
    void test();
    //void getProductTupefromQComboBox(const QString & );

};

#endif // FIRSTWIDGET_H
