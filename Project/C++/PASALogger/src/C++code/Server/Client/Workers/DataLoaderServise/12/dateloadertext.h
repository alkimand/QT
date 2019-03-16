#ifndef DateLoaderText_H
#define DateLoaderText_H
#include "dataloaderbaseclass.h"

//class QUdpSocket;

class DateLoaderText: public DataLoaderBaseClass
        //:DataLoaderBaseClass
{
    Q_OBJECT

public:
    explicit  DateLoaderText(WorkerBaseClass *, CLIENT_TYPE const &);


private:
   // QUdpSocket* udp_socket;
   // int port;
    void create_connect_to_worker();

signals:
    //void sendData(QString);

private slots:
    void start();
    void stop();
    void slotProcessDatagrams();

};

#endif // DateLoaderText_H
