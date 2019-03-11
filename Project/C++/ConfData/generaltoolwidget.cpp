#include "generaltoolwidget.h"
#include <QWidget>
#include <QLabel>
#include "generalproduct.h"

GeneralToolWidget::GeneralToolWidget(QWidget *parent): QWidget(parent)
{

}

void GeneralToolWidget::create_product()
{
    //?
    int number;
    //?
    product = new GeneralProduct();
}
