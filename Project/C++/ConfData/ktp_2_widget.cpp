#include "ktp_2_widget.h"
#include "generaltoolwidget.h"
#include <constantlist.h>

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


KTP_2_Widget::KTP_2_Widget(QWidget *parent): GeneralToolWidget(parent)
{
    pagename = NAMES_TAB_KTP_2;
    QHBoxLayout *Hlayout = new QHBoxLayout;

    QFormLayout *FormLayout = new QFormLayout;

    StringOfLabel << "Количество трансформаторов" << "Тип трансформатора" << "Мощность силовых трансформаторов, кВА" <<
                     "Типоразмер корпуса" << "Габаритные размеры, мм" << "Напряжение ВН кВ"<< "Наибольшее рабочее напряжение на стороне ВН, кВ"<< "Напряжение НН кВ"
                  <<"Наименование продукции" <<"Масса, кг" << "Климатическое исполнение и месту размещения" << "Степень защиты";
    //QLabel



    this->NumberTrLabel= new QLabel(StringOfLabel.at(0),this);
    ListOfLabel.append(NumberTrLabel);
    this->TypeTrLabel= new QLabel(StringOfLabel.at(1),this);
    ListOfLabel.append(TypeTrLabel);
    this->PowerTrLabel= new QLabel(StringOfLabel.at(2),this);
    ListOfLabel.append(PowerTrLabel);
    this->PackageTypeLabel= new QLabel(StringOfLabel.at(3),this);
    ListOfLabel.append(PackageTypeLabel);
    this->PackageSizeLabel= new QLabel(StringOfLabel.at(4),this);
    ListOfLabel.append(PackageSizeLabel);
    this->HighVoltageLabel= new QLabel(StringOfLabel.at(5),this);
    ListOfLabel.append(HighVoltageLabel);
    this->MaxHighVoltageLabel= new QLabel(StringOfLabel.at(6),this);
    ListOfLabel.append(MaxHighVoltageLabel);
    this->LowVoltageLabel= new QLabel(StringOfLabel.at(7),this);
    ListOfLabel.append(LowVoltageLabel);
    this->NameProductLabel= new QLabel(StringOfLabel.at(8),this);
    ListOfLabel.append(NameProductLabel);
    this->MassLabel= new QLabel(StringOfLabel.at(9),this);
    ListOfLabel.append(MassLabel);
    this->ClimaticVersionLabel= new QLabel(StringOfLabel.at(10),this);
    ListOfLabel.append(ClimaticVersionLabel);
    this->DegreeProtectionLabel= new QLabel(StringOfLabel.at(11),this);
    ListOfLabel.append(DegreeProtectionLabel);

    //qDebug()<<" ListOfLabel.size() = " << ListOfLabel.size();

    //QComboBox || QLineEdit
    QStringList Datalist;

    this->NumberTrComboBox = new QComboBox(this);//0
    Datalist.clear();
    Datalist <<NULL_POSITION << "1"<< "2";
    NumberTrComboBox->addItems(Datalist);
    ListOfWidget.append(NumberTrComboBox);

    this->TypeTrComboBox = new QComboBox(this);//1 //_________________________________________Заменить на модель с SQL
    Datalist.clear();
    Datalist << NULL_POSITION <<"ТМ"<< "ТМГ";
    TypeTrComboBox->addItems(Datalist);
    ListOfWidget.append(TypeTrComboBox);

    this->PowerTrComboBox = new QComboBox(this);//2
    Datalist.clear();
    Datalist <<NULL_POSITION << "630"<< "1000";
    PowerTrComboBox->addItems(Datalist);
    ListOfWidget.append(PowerTrComboBox);

    this->PackageTypeComboBox = new QComboBox(this);//3
    Datalist.clear();
    Datalist <<NULL_POSITION << "400 кВА тупиковая"<< "до 400 кВА тупиковая" <<"630 кВА проходная";
    PackageTypeComboBox->addItems(Datalist);
    ListOfWidget.append(PackageTypeComboBox);

    this->PackageSizeComboBox = new QComboBox(this);//4
    Datalist.clear();
    Datalist <<NULL_POSITION << "2200х2000х4600"<< "1800х1600х4700";
    PackageSizeComboBox->addItems(Datalist);
    ListOfWidget.append(PackageSizeComboBox);

    this->HighVoltageComboBox = new QComboBox(this);
    Datalist.clear();
    Datalist <<NULL_POSITION << "6"<< "10";
    HighVoltageComboBox->addItems(Datalist);
    ListOfWidget.append(HighVoltageComboBox);

    this->MaxHighVoltageComboBox = new QComboBox(this);
    Datalist.clear();
    Datalist <<NULL_POSITION << "7.2"<< "11";
    MaxHighVoltageComboBox->addItems(Datalist);
    ListOfWidget.append(MaxHighVoltageComboBox);

    this->LowVoltageComboBox = new QComboBox(this);//7
    Datalist.clear();
    Datalist <<NULL_POSITION << "0,22" <<"0,38"<< "0,4";
    LowVoltageComboBox->addItems(Datalist);
    ListOfWidget.append(LowVoltageComboBox);

    this->NameProductQLineEdit = new  QLineEdit(this);
    NameProductQLineEdit->setClearButtonEnabled(true);
    ListOfWidget.append(NameProductQLineEdit);

    this->MassQLineEdit = new  QLineEdit(this);
    MassQLineEdit->setClearButtonEnabled(true);
    ListOfWidget.append(MassQLineEdit);

    this->ClimaticVersionComboBox = new QComboBox(this);//10
    Datalist.clear();
    Datalist <<NULL_POSITION << "У1" <<"У2"<< "У3"<<"У4";
    ClimaticVersionComboBox->addItems(Datalist);
    ListOfWidget.append(ClimaticVersionComboBox);

    this->DegreeProtectionComboBox = new QComboBox(this);//11
    Datalist.clear();
    Datalist <<NULL_POSITION << "IP31" <<"IP41"<< "IP51"<<"IP61";
    DegreeProtectionComboBox->addItems(Datalist);

    //qDebug()<<" DegreeProtectionComboBox->itemText(1); = " << DegreeProtectionComboBox->count();//-
    //qDebug()<<" DegreeProtectionComboBox->itemText(2); = " << DegreeProtectionComboBox->itemText(2);//-

    ListOfWidget.append(DegreeProtectionComboBox);

//qDebug()<<" ListOfWidget.size() = " << ListOfWidget.size();
    //добавляем в форму из листов widgets
    for (int i=0; i < ListOfWidget.size(); i++)
        FormLayout->addRow(ListOfLabel.at(i),ListOfWidget.at(i));
    Hlayout->addLayout(FormLayout);
    this->setLayout(Hlayout);

}

QString KTP_2_Widget::getpagename()
{
    return pagename;
}


void KTP_2_Widget::test()
{
    qDebug()<<" FirstWidget SLOT(test()";
}

