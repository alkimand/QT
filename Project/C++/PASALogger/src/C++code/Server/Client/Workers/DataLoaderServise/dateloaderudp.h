#ifndef DATELOADERUDP_H
#define DATELOADERUDP_H
#include "dataloaderbaseclass.h"

class QUdpSocket;

class DateLoaderUDP: public DataLoaderBaseClass
        //:DataLoaderBaseClass
{
    Q_OBJECT

public:
    explicit  DateLoaderUDP(WorkerBaseClass *, CLIENT_TYPE const &);
    ~DateLoaderUDP();
    void setStatus(const int &);

private:
    QUdpSocket* udp_socket;
    int port;
    void create_connect_to_worker();

signals:
    //void sendData(QString); //move to Base class
    void sendData(QByteArray const &);

private slots:
    void start();
    void stop();
    void slotProcessDatagrams();

};

#endif // DATELOADERUDP_H
