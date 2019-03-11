#include "firstwidget.h"
#include "generaltoolwidget.h"
#include <constantlist.h>
#include "toolwidget.h"

#include <QHBoxLayout>
#include <QGridLayout>
#include <QList>
#include <QMap>
#include <QLineEdit>
#include <QLabel>
#include <QDateEdit>
#include <QDebug>
#include <QFormLayout>
#include <QDate>
#include <QComboBox>

FirstWidget::FirstWidget(QWidget *parent): GeneralToolWidget(parent)
{
    //this->parent = parent;
    pagename = NAMES_TAB_FIRST;
    QHBoxLayout *Hlayout = new QHBoxLayout;
    //QGridLayout *GridLayout = new QGridLayout;
    QFormLayout *FormLayout = new QFormLayout;

    StringOfLabel << "Тип оборудования" << "ТУ №" << "Зав №" << "ПМ №"
                  << "Дата изготовления";
    this->TypeLabel= new QLabel(StringOfLabel.at(0),this);
    this->ListOfLabel.append(TypeLabel);

    //this->TypeLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->TYLabel= new QLabel(StringOfLabel.at(1),this);
    ListOfLabel.append(TYLabel);

    this->NumberLabel= new QLabel(StringOfLabel.at(2),this);
    ListOfLabel.append(NumberLabel);

    this->PMnumberLabel= new QLabel(StringOfLabel.at(3),this);
    ListOfLabel.append(PMnumberLabel);

    this->DateCreationLabel= new QLabel(StringOfLabel.at(4),this);
    ListOfLabel.append(DateCreationLabel);

    //this->TypeQLineEdit = new QLineEdit(this);
    this->TypeQComboBox = new QComboBox(this); //_________________________________________Заменить на модель с SQL
    QStringList Datalist = { NULL_POSITION, PRODUCT_TYPE_KTP, PRODUCT_TYPE_STP, PRODUCT_TYPE_PKU, PRODUCT_TYPE_NKU };
    TypeQComboBox->addItems(Datalist);
    ListOfWidget.append(TypeQComboBox);

    connect(this->TypeQComboBox,SIGNAL (currentTextChanged(const QString &)), parent,  SLOT(setProductType(const QString & )));//



    this->TYQLineEdit = new QLineEdit(this);
    ListOfWidget.append(TYQLineEdit);
    TYQLineEdit->setText("3412-001-09444327-2012");
    TYQLineEdit->setClearButtonEnabled(true);

    this->NumberQLineEdit = new QLineEdit(this);
    NumberQLineEdit->setClearButtonEnabled(true);
    ListOfWidget.append(NumberQLineEdit);

    this->PMnumberQLineEdit = new QLineEdit(this);
    ListOfWidget.append(PMnumberQLineEdit);
    PMnumberQLineEdit->setClearButtonEnabled(true);

    this->DateCreation = new QDateEdit(this);
    this->DateCreation->setCalendarPopup(true);
    ListOfWidget.append(DateCreation);

    QDate today = QDate::currentDate();
    DateCreation->setMinimumDate(today.addDays(-30));
    DateCreation->setDate(today);
    Pagesize = ListOfWidget.count();

    //добавляем в форму из листов widgets
    for (int i=0; i < Pagesize; i++)
        FormLayout->addRow(ListOfLabel.at(i),ListOfWidget.at(i));
    Hlayout->addLayout(FormLayout);
    this->setLayout(Hlayout);

    //connect(this->TypeQComboBox,SIGNAL(),);
}

QString FirstWidget::getpagename()
{
    return pagename;
}


void FirstWidget::test()
{
    qDebug()<<" FirstWidget SLOT(test()";
}

//void FirstWidget::getProductTypefromQComboBox(const QString &)
//{
//    QString ProductType = this->TypeQComboBox->currentText();
//    qDebug()<<" FirstWidget::getProductTypefromQComboBox" << ProductType;

//    emit setProductTypetoToolWidget(ProductType);

//}

//void FirstWidget::SetObjectPage()
//{

//}
