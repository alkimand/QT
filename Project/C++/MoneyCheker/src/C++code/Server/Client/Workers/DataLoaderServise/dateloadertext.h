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

    QString fullFilePath;
    void getOpenFileName();



signals:

    void readyRead();




private slots:
    void slotProcessDatagrams();


};

#endif // DATELOADERUDP_H
