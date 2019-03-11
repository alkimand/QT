//Виджет в тулбаре для наследования и общих методов
#ifndef GENERALTOOLWIDGET_H
#define GENERALTOOLWIDGET_H
#include <QWidget>
class QWidget;
class QLabel;
class GeneralProduct;

class GeneralToolWidget: public QWidget
{
    Q_OBJECT
public:
    explicit GeneralToolWidget (QWidget *parent = nullptr);//создание всего в конструкторе
    QList <QWidget*> ListOfWidget;//маленькие вижджеты на конкретном виджете
    QList <QLabel*> ListOfLabel;
    QStringList StringOfLabel;//не обязательный лист - названия в ListOfLabel
    int Pagesize;
    //virtual void SetObjectPage(GeneralProduct *)=0;
    virtual QString getpagename()=0;//поучаем имя = название старницы для вставки в toolwidget
    private :
    GeneralProduct *product;

private:
virtual void initpage()=0;
private slots:
    void create_product();





};

#endif // GENERALTOOLWIDGET_H
