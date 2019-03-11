#include "controlwidget.h"
#include "generaltoolwidget.h"
#include <constantlist.h>

#include <QTableView>
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
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QFileDialog>
#include <QMessageBox>
Control_Widget::Control_Widget(QWidget *parent): GeneralToolWidget(parent)
{
    pagename = NAMES_TAB_ACTIONS;
    FolderChoiceLineEdit = new QLineEdit(this);
    TemplateFolderChoiceLineEdit = new QLineEdit(this);

    FolderChoicePushButton = new QPushButton("Выбрать папку проекта",this);
    TemplateFolderChoiceButton = new QPushButton("Выбрать папку шаблонов",this);
    TemplateChoiceButton = new QPushButton("Выбрать шаблоны",this);
    TemplateCopyToFolderButton= new QPushButton("Скопировать выбранные  шаблоны в папку",this);
    TemplateReWrriteFilerButton= new QPushButton("Переписать значения в шаблонах",this);

    FolderChoiceProgressBar = new QProgressBar(this);
    //need more code
    FolderChoiceProgressBar->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    //FolderChoiceProgressBar->textDirection()
    FolderChoiceProgressBar->setTextVisible(false);
    TemplateFolderProgressBar= new QProgressBar(this);
    TemplateFolderProgressBar->setTextVisible(false);
    TemplateChoiceProgressBar= new QProgressBar(this);
    TemplateChoiceProgressBar->setTextVisible(false);
    TemplateCopyToFolderProgressBar= new QProgressBar(this);
    TemplateCopyToFolderProgressBar->setTextVisible(false);
    TemplateReWrriteProgressBar= new QProgressBar(this);
    TemplateReWrriteProgressBar->setTextVisible(false);

    //AllTemplateTableView = new QTableView(this);
    //ChoiseTemplateTableView = new QTableView(this);
    TemplateQListWidget = new QListWidget(this);

    QGridLayout * GridLayout = new QGridLayout(this);
    QHBoxLayout *Hlayout = new QHBoxLayout;


    //GridLayout->addWidget(AllTemplateTableView,0,0,7,1);
    //GridLayout->addWidget(ChoiseTemplateTableView,0,5,7,1);


    GridLayout->addWidget(FolderChoicePushButton,    0,0,1,1);
    GridLayout->addWidget(FolderChoiceProgressBar   ,0,1,1,1);
    GridLayout->addWidget(FolderChoiceLineEdit      ,1,0,1,2);

    GridLayout->addWidget(TemplateFolderChoiceButton,2,0,1,1);
    GridLayout->addWidget(TemplateFolderProgressBar ,2,1,1,1);
    GridLayout->addWidget(TemplateFolderChoiceLineEdit,3,0,1,2);

    GridLayout->addWidget(TemplateChoiceButton,      4,0,1,1);
    GridLayout->addWidget(TemplateChoiceProgressBar ,4,1,1,1);

    GridLayout->addWidget(TemplateQListWidget        ,5,0,1,2);



    GridLayout->addWidget(TemplateCopyToFolderButton ,6,0,1,1);
    GridLayout->addWidget(TemplateCopyToFolderProgressBar,6,1,1,1);

    GridLayout->addWidget(TemplateReWrriteFilerButton,7,0,1,1);
    GridLayout->addWidget(TemplateReWrriteProgressBar ,7,1,1,1);
    //GridLayout->setHorizontalSpacing(10);
    // GridLayout->setVerticalSpacing(1);
    //QRect rect = GridLayout->geometry();
    //rect.setHeight(rect.height()/2);
    // GridLayout->setGeometry(rect);
    setLayout(GridLayout);

    //add signals and slot

    //QString templatePath = "C:://";
    //QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),templatePath,"All files(*.*);;Text File (*.txt);;Music file (*.mp3)");

    connect(FolderChoicePushButton, SIGNAL(clicked(bool)),this,SLOT(getProductFolder()));
    connect(TemplateFolderChoiceButton, SIGNAL(clicked(bool)),this,SLOT(getTemplateFolder()));
    connect(TemplateChoiceButton, SIGNAL(clicked(bool)),this,SLOT(createTemplateFileList()));
    connect(TemplateCopyToFolderButton, SIGNAL(clicked(bool)),this,SLOT( copyTemplateTofolder()));

    // connect(FolderChoiceProgressBar, SIGNAL(),this,SLOT(getProductFolder()));



    //++ fore test

    //TemplateFoldername = "C:/Users/User/Downloads/Cpp-lab-1 (1)";
    FolderChoiceLineEdit->setText("G:/QT/234/ConfData/test");
    TemplateFolderChoiceLineEdit->setText("G:/QT/234/ConfData");

}

QString Control_Widget::getfilename()
{

}


QString Control_Widget::getpagename()
{
    return pagename;
}

void Control_Widget::getProductFolder()
{
    QString templatePath1 = "C:/Users/User/Downloads/Cpp-lab-1 (1)";
    filename = QFileDialog::getExistingDirectory(this, tr("Open Directory"),templatePath1,
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    //QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),templatePath,"All files(*.*);;Text File (*.txt);;Music file (*.mp3)");
    FolderChoiceLineEdit->setText(filename);
    if (!filename.isEmpty())
        FolderChoiceProgressBar->setValue(100);
    else
        FolderChoiceProgressBar->setValue(0);
}


void Control_Widget::getTemplateFolder()
{
    QString templatePath2 = "C:/Users/User/Downloads/Cpp-lab-1 (1)";
    TemplateFoldername = QFileDialog::getExistingDirectory(this, tr("Open Directory"),templatePath2,
                                                           QFileDialog::ShowDirsOnly
                                                           | QFileDialog::DontResolveSymlinks);
    //Templatefilename = QFileDialog::getOpenFileName(this, tr("Open File"),templatePath,"All files(*.*);;Text File (*.txt);;Music file (*.mp3)");
    TemplateFolderChoiceLineEdit->setText(TemplateFoldername);
    if (!TemplateFoldername.isEmpty())
        TemplateFolderProgressBar->setValue(100);
    else
        TemplateFolderProgressBar->setValue(0);

}

void Control_Widget::createTemplateFileList()
{
    //Templatefilenames_temp
    //QString templatePath3 = "C:/Users/User/Downloads/Cpp-lab-1 (1)";

    QStringList newTemplatefilenames = QFileDialog::getOpenFileNames (this, "Выбор шаблонов", TemplateFoldername, "All files(*.*)");
    QString str;
    if (!newTemplatefilenames.isEmpty())
        TemplateQListWidget->clear();

    //make Checked QListWidgetItem

    foreach (str, newTemplatefilenames)
    {
        QListWidgetItem *item = new QListWidgetItem(str, TemplateQListWidget);
        item->setCheckState(Qt::Checked);
    }


    //TemplateQListWidget->removeDuplicates();
    //    if (!Templatefilenames.isEmpty())
    //        TemplateChoiceProgressBar->setValue(100);
    //    else
    //        TemplateChoiceProgressBar->setValue(0);
    //create checked template file list
    Templatefilenames.clear();
    Templatefilenames = newTemplatefilenames;

    //    QList <QListWidgetItem *>  list = TemplateQListWidget->selectedItems();
    //    for (int i =0; i<list.size();i++)
    //    {
    //        Templatefilenames.append(list.at(i)->text());
    //    }

    if (!newTemplatefilenames.isEmpty())
        TemplateChoiceProgressBar->setValue(100);
    else
        TemplateChoiceProgressBar->setValue(0);


}

void Control_Widget::copyTemplateTofolder()
{
    Templatefilenames.clear();
    filenames.clear();
    QStringList pathSplitstringList;
    //create list of Templatefilenames + list filenames
    for(int i = 0; i < TemplateQListWidget->count(); ++i)
    {
        QListWidgetItem* item = TemplateQListWidget->item(i);
        if (item->checkState() == Qt::CheckState::Checked)
        {
            Templatefilenames.append((item->data(Qt::EditRole)).toString());
            pathSplitstringList = Templatefilenames.back().split("/");
            filenames.append( pathSplitstringList.back());
            qDebug() <<"(item add - " <<pathSplitstringList.back();
        }
    }

    //copy file to product folder
    QString destFilePath;
    //int needReWriteThisfile = -1;
    //int needReWriteAllfile = -1;//на будущее
    int needReWrite{};
    for(int i = 0; i < filenames.count(); ++i)
    {
        destFilePath =  FolderChoiceLineEdit->text() + "/" + filenames.at(i);
        QFile destfile (destFilePath);
        if (!destfile.exists())
        {
            QFile::copy(Templatefilenames.at(i), destFilePath);
            if (filenames.count()!=0)
                TemplateCopyToFolderProgressBar->setValue((i + 1) / filenames.count() * 100);
        }
        else
        {
            if (needReWrite != QMessageBox::YesToAll)

                needReWrite = QMessageBox::warning(this, tr("Запрос на перезапись шаблонов"),
                                                   tr("Файл < %1 > уже существует, заменить?")
                                                   .arg(filenames.at(i)),
                                                   QMessageBox::Yes | QMessageBox::No);
            if (needReWrite == QMessageBox::Yes)
            {
                destfile.remove();
                QFile::copy(Templatefilenames.at(i), destFilePath);
            }
        }
    }
    TemplateCopyToFolderProgressBar->setValue(100);
}

