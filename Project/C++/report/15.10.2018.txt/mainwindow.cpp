#include "mainwindow.h"
#include "creator.h"
#include "ui_mainwindow.h"

#include <QCalendarWidget>
#include <QDebug>
#include <QDial>
//include <QDir>
//#include <QDir>
#include <QLineEdit>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // create Creator object + workers in it
    MyCreator = new Creator (this);
    connect (this->ui->NewpushButton,SIGNAL(clicked(bool)), MyCreator, SLOT(CNewpushButtonCliked(bool)));
    connect (this->ui->DelpushButton,SIGNAL(clicked(bool)), MyCreator, SLOT(CDellpushButtonCliked(bool)));
    connect (this->ui->SavepushButton,SIGNAL(clicked(bool)), MyCreator, SLOT(CSavepushButtonCliked(bool)));
    connect (this->ui->calendarWidget,SIGNAL(clicked(const QDate &)), MyCreator, SLOT(CSelectDate(const QDate &)));
    connect (this,SIGNAL(setDate(const QDate &)), MyCreator, SLOT(CSelectDate(const QDate &)));
    connect (this->ui->listWidget,SIGNAL(currentTextChanged(const QString &)), this, SLOT(listWidgetDatechange(const QString &)));
    connect (this->ui->pathPushButton,SIGNAL(clicked(bool)), this, SLOT(getPathFolder()));
    connect (this,SIGNAL (pathChanges(const QString &)), MyCreator, SLOT(pathChangesSlot(const QString &)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getPathFolder()
{
    qDebug() << "getPathFolder()";
    QString filename;
    QString templatePath1 = "C:/Users/User/Downloads/Cpp-lab-1 (1)";
    filename = QFileDialog::getExistingDirectory(this, tr("Open Directory"),templatePath1,
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    //QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),templatePath,"All files(*.*);;Text File (*.txt);;Music file (*.mp3)");
    this->ui->folderlineEdit->setText(filename);
    emit pathChanges(filename);
}

void MainWindow::debugSlot()
{
    qDebug() << "This is debugSlot()";
    //emit Creator::MyCreator.test4();
}

void MainWindow::debugStringSlot(const QString & string)
{
    qDebug() << "debugStringSlot(const QString &) " << string;
}
void MainWindow::changeSliderSlot(int value)
{

    QDate dateincalendarWidget =this->ui->calendarWidget->selectedDate();
    this->ui->calendarWidget->setSelectedDate(dateincalendarWidget.addDays(value));
}

void MainWindow::listWidgetDatechange(const QString & newDate)
{
    QDate Date = QDate::fromString(newDate,"dd.MM.yyyy");
    emit setDate (Date);
}


