#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QAbstractSocket>
#include <QWidget>
#include <QTcpSocket>
#include <QSqlDatabase>

class QTcpServer;
class QTextEdit;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTextEdit *m_ptxtInfo;
    QSqlDatabase  *db;
    QTcpSocket *Socket;
    QTcpServer *m_ptcpServer;

};


#endif // MAINWINDOW_H
