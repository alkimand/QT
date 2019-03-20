#ifndef DATELOADERTEXT_H
#define DATELOADERTEXT_H
#include "dataloaderbaseclass.h"

//class QUdpSocket;

class DateLoaderText: public DataLoaderBaseClass
        //:DataLoaderBaseClass
{
    Q_OBJECT

public:
    explicit DateLoaderText(WorkerBaseClass *, CLIENT_TYPE const &);
    ~DateLoaderText();
    void setStatus(const int &){};

private:
    //QUdpSocket* udp_socket;
    QString fileName;
    void create_connect_to_worker();


signals:
    //void sendData(QString); //move to Base class
    void readyRead();



private slots:
    void start();
    void stop();
    void slotProcessDatagrams();


};

#endif // DATELOADERUDP_H
