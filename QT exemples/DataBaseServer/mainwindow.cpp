#include "mainwindow.h"
#include <QSqlDatabase>
#include <QList>
#include <QAbstractSocket>
#include <QWidget>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QCoreApplication>
#include <QtNetwork>
#include <QTcpSocket>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    //qDebug()<< QSqlDatabase::drivers();

    //this->db = QSqlDatabase::addDatabase("QSQLITE");

//https://www.youtube.com/watch?v=n8GzbdCkby8

//http://www.prog.org.ru/topic_26068_15.html
//3306
//root pasword 1


    QSqlDatabase  *db = new QSqlDatabase();

    db->addDatabase("QMYSQL");
    db->setHostName("localhost");
    db->setDatabaseName("testdb");
    db->setUserName("user");
    db->setPassword("password");

    if (db->open())
        qDebug() << "Db is open";
    else
        qDebug() << "Db connection error";


   // this->Socket = new QTcpSocket(this);
  //  m_ptcpServer = new QTcpServer(this);
   //m_ptcpServer->listen(QHostAddress::Any,125);


    //клиент на базе
//    db.setHostName("315.155.0.1");
//    db.setDatabaseName("DataBase_Name");
//    db.setPort(3308);
//    db.setUserName("Login_To_DB");
//    db.setPassword("Pass_From_DB");
//    db.setConnectOptions("MYSQL_OPT_RECONNECT=TRUE;");
//    db.open();
//this->db.open();





//    m_ptxtInfo  = new QTextEdit(this);
//    QVBoxLayout* MainLayout = new QVBoxLayout;
//    MainLayout->addWidget(m_ptxtInfo);
//    this->setLayout(MainLayout);







    //this->db2.setDatabaseName("ForeSalers.dat");


}

MainWindow::~MainWindow()
{

}
