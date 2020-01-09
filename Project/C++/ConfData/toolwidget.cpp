
#include <QFileDialog>
#include <QAction>
#include <QMessageBox>
#include <QTextStream>
#include <QCloseEvent>
#include <QApplication>
#include <QTabWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QDataWidgetMapper>
#include <QHBoxLayout>
#include <QMap>
#include <QDebug>

//widgets
#include "toolwidget.h"
#include "firstwidget.h"
#include "ktp_2_widget.h"
#include "controlwidget.h"

#include "generalproduct.h"
#include "product_ktp.h"


//#include "toolwidget2.h"

ToolWidget::ToolWidget(QWidget *parent)
    : QWidget(parent)
{
    action = new QAction(this);
    action->setCheckable(true);
    connect(action, SIGNAL(triggered()), this, SLOT(show()));
    connect(action, SIGNAL(triggered()), this, SLOT(setFocus()));

    isUntitled = true;
//    connect(document(), SIGNAL(contentsChanged()),
//            this, SLOT(documentWasModified()));

    setWindowIcon(QPixmap(":/sourse/images_button/raketa.png"));
    setWindowTitle("[*]");
    setAttribute(Qt::WA_DeleteOnClose);

    //tabwidget
    tabwidget = new QTabWidget(this);

    //другие виджеты
    //this->createGeneralWidget(); //создаем первый виджет после него создаем другие в зависимости от типа

    // + firstwidget вкладка общее
    GeneralToolWidget *firstwidget = new FirstWidget(this);
    GeneralListOfWidget.append(firstwidget);

    //добавление
    tabwidget->addTab(GeneralListOfWidget.back(),GeneralListOfWidget.back()->getpagename());
    //имеем слот с изменяемым чекбоксом - в него вставляем логику по добовлению новых окон



    //this->InfoWidget = new FirstWidget(this);
    //tabwidget->addTab(InfoWidget,"Корпус и размеры");
    //GeneralListOfWidget.append(InfoWidget);

    //InfoWidget->setHidden(true);

   // tabwidget->setTabsClosable(true);
     // tabwidget->removeTab(1);
    //tabwidget->addTab(new QWidget,"Корпус");

    QHBoxLayout *Hlayout = new QHBoxLayout;
    Hlayout->addWidget(tabwidget);
    //Hlayout->addLayout(Vlayout2);
    this->setLayout(Hlayout);
}

void ToolWidget::newFile()
{
    static int documentNumber = 1;

    curFile = tr("document%1.cnfg").arg(documentNumber);
    setWindowTitle(curFile + "[*]");
    action->setText(curFile);
    isUntitled = true;
    ++documentNumber;
    //--
    qDebug()<<" checktemplate(TEMPLATEFILE) = " << checktemplate(TEMPLATEFILE);
}

bool ToolWidget::save()
{
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool ToolWidget::saveAs()
{
    QString fileName =
            QFileDialog::getSaveFileName(this, tr("Save As"), curFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

QSize ToolWidget::sizeHint() const
{
  //qDebug()<<" ToolWidget::sizeHint() ";
    return QSize(100 * fontMetrics().width('x'),
                 40 * fontMetrics().lineSpacing());
}

ToolWidget *ToolWidget::open(QWidget *parent)
{
    QString fileName =
            QFileDialog::getOpenFileName(parent, tr("Open"), ".");
    if (fileName.isEmpty())
        return 0;

    return openFile(fileName, parent);
}

ToolWidget *ToolWidget::openFile(const QString &fileName, QWidget *parent)
{
    ToolWidget *toolwidget = new ToolWidget(parent);
//    if (ToolWidget->readFile(fileName)) {
//        ToolWidget->setCurrentFile(fileName);
//        return ToolWidget;
//    } else {
//        delete ToolWidget;
//        return 0;
//    }
    return toolwidget;
}

void ToolWidget::closeEvent(QCloseEvent *event)
{
    if (okToContinue()) {

        event->accept();
    } else {
        event->ignore();
    }
}

void ToolWidget::documentWasModified()
{
    setWindowModified(true);
}

//запись в поле Type от сигнала в FirstWidget
//+логика создания окон
void ToolWidget::setProductType(const QString &Type)
{
    //qDebug()<<" ToolWidget setProductType " << Type;
    this->ProductType = Type;

    if (GeneralListOfWidget.size() != 1)
    {
        qDebug()<<" GeneralListOfWidget.size() != 0  = " <<GeneralListOfWidget.size() ;
        for (int i=1;i<GeneralListOfWidget.size();i++)
        {
            delete GeneralListOfWidget.at(i);
        }
        GeneralToolWidget * first = GeneralListOfWidget.at(0);
        GeneralListOfWidget.clear();
        GeneralListOfWidget.append(first);
    }
    //логика и создание новых виджетов
    if (ProductType == PRODUCT_TYPE_KTP)
    {
        LCreateKTPWidget();//внутри создание множества виджетов + занесение в лист = создание нескольких окон необходимых для работы
        LCreateControlWidget(); //итоговый виджет для вывода в фаил
    }
    else if (ProductType == PRODUCT_TYPE_STP)
    {

    }
    else if (ProductType == PRODUCT_TYPE_PKU)
    {

    }
    else if (ProductType == PRODUCT_TYPE_NKU)
    {

    }

}

void ToolWidget::test()
{
    qDebug()<<" ToolWidget SLOT(test()";
}



bool ToolWidget::okToContinue()
{

//  if (document()->isModified()) {
//        int r = QMessageBox::warning(this, tr("MDI ToolWidget"),
//                        tr("File %1 has been modified.\n"
//                           "Do you want to save your changes?")
//                        .arg(strippedName(curFile)),
//                        QMessageBox::Yes | QMessageBox::No
//                        | QMessageBox::Cancel);
//        if (r == QMessageBox::Yes) {
//            return save();
//        } else if (r == QMessageBox::Cancel) {
//            return false;
//        }
//    }
    return true;
}

bool ToolWidget::saveFile(const QString &fileName)
{
    if (writeFile(fileName)) {
        setCurrentFile(fileName);
        return true;
    } else {
        return false;
    }
}

void ToolWidget::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    isUntitled = false;
    action->setText(strippedName(curFile));
    //document()->setModified(false);
    setWindowTitle(strippedName(curFile) + "[*]");
    setWindowModified(false);
}

bool ToolWidget::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("MDI ToolWidget"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(file.fileName())
                             .arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    //setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();
    return true;
}

bool ToolWidget::writeFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("MDI ToolWidget"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(file.fileName())
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    //out << toPlainText();
    QApplication::restoreOverrideCursor();
    return true;
}

QString ToolWidget::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void ToolWidget::createGeneralWidget()
{
    this->GeneralWidget = new FirstWidget(this);
    GeneralToolWidget *widget = new FirstWidget(this);
    GeneralListOfWidget.append(widget);
}

void ToolWidget::createGeneralProduct() //создаем указатель на класс GeneralProduct + логика выбора типа наследника GeneralProduct
{
   if (Product != nullptr)
   {
     delete   Product;
   }
   //Product = new GeneralProduct(this);
   createMapProduct();
  // this->Product = new GeneralProduct(this);
    //enum  Enum_Type{ Type_KTP = 1, Type_STP = 2, UPE_PKU = 3, Type_NKU = 4 };
   //this->Product = new Product_KTP(this);
}

//создаем QMap для дальнейшего выбора при создании объекта
void ToolWidget::createMapProduct()
{
    Type_Map.insert(PRODUCT_TYPE_KTP, TYPE_KTP);
    Type_Map.insert(PRODUCT_TYPE_STP, TYPE_STP);
    Type_Map.insert(PRODUCT_TYPE_PKU, TYPE_PKU);
    Type_Map.insert(PRODUCT_TYPE_NKU, TYPE_NKU);
}

void ToolWidget::LCreateKTPWidget()
{
    GeneralToolWidget *widget = new KTP_2_Widget(this);
    GeneralListOfWidget.append(widget);
    tabwidget->addTab(GeneralListOfWidget.back(),GeneralListOfWidget.back()->getpagename());
}

void ToolWidget::LCreateControlWidget()
{
    GeneralToolWidget *widget = new Control_Widget(this);
    GeneralListOfWidget.append(widget);
    tabwidget->addTab(GeneralListOfWidget.back(),GeneralListOfWidget.back()->getpagename());
}

bool ToolWidget::checktemplate(const QString &fileName)
{
    if (QFile(fileName).exists()) return true;
    else return false;
}

void ToolWidget::loadtemplate(const QString &fileName)
{
    //дописать создание объекта после парсинга файла
}
