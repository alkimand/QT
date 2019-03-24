#ifndef CLIENTUDP_H
#define CLIENTUDP_H
#include "clientbase.h"
#include <QObject>
#include "modelserviseudp.h"
#include "proximodelserviseudp.h"

//https://habr.com/ru/post/140899/
//https://www.qtcentre.org/threads/48479-QAbstractListModel-does-not-update-QML-ListView
//https://yandex.ru/search/?text=emit%20dataChanged()%20qml&&lr=47



class ClientUDP: public ClientBase
{
    Q_OBJECT
    Q_PROPERTY(ModelServiseUDP * model READ readModel WRITE setVin NOTIFY modelChanged)
    Q_PROPERTY(ProxiModelServiseUDP * proximodel READ readproxiModel WRITE setproximodel NOTIFY proxiModelChanged)
    //Q_PROPERTY(QString documentTittle READ readDocumentTittle WRITE setDocumentTittle NOTIFY documentTittleChanged)

public:
    explicit ClientUDP(); //no const
    ModelServiseUDP *model;
    ProxiModelServiseUDP *proximodel;
    void run();
    void setVin(const ModelServiseUDP *model);
    ~ClientUDP();
    ModelServiseUDP *readModel() const
    {
        return model;
    }

    void setproximodel(const ProxiModelServiseUDP *proximodel);
    //void setDocumentTittle(const QString );

//    QString readDocumentTittle()
//    {
//        return tittle;
//    }

    ProxiModelServiseUDP *readproxiModel() const
    {
        return proximodel;
    }


signals:
void modelChanged();
void proxiModelChanged();
//void documentTittleChanged();

public slots:
//void setStatus(const int &);
//void clearDataPool();
//void clearDataPool();

protected:

private:
};

#endif // CLIENTUDP_H
