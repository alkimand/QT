#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    downloader = new Downloader(); // Инициализируем Downloader

    // по нажатию кнопки запускаем получение данных по http
    connect(ui->pushButton, &QPushButton::clicked, downloader, &Downloader::getData);
    //connect(this->ui->SetPass, SIGNAL(clicked()), downloader, SLOT (setPass()));
    connect(ui->SetPass, &QPushButton::clicked, downloader, &Downloader::setPass);

    // по окончанию получения данных считываем данные из файл
    connect(downloader, &Downloader::onReady, this, &Widget::readFile);
    //connect(this,SIGNAL(loadFinish()), this, SLOT(readFileAfterSendPas()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readFile()
{
    QFile file("C:/example/file.xml");
    if (!file.open(QIODevice::ReadOnly)) // Открваем файл, если это возможно
            return; // если открытие файла невозможно, выходим из слота
    // в противном случае считываем данные и устанавилваем их в textEdit
    ui->textEdit->setText(file.readAll());
    emit loadFinish();
}

void Widget::readFileAfterSendPas()
{
 qDebug () << "Widget::readFileAfterSendPas()";
}

