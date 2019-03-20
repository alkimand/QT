#ifndef CLIENTUDP_H
#define CLIENTUDP_H
#include "clientbase.h"
#include <QObject>
#include "modelserviseudp.h"

//https://habr.com/ru/post/140899/
//https://www.qtcentre.org/threads/48479-QAbstractListModel-does-not-update-QML-ListView
//https://yandex.ru/search/?text=emit%20dataChanged()%20qml&&lr=47



class ClientUDP: public ClientBase
{
    Q_OBJECT
    //Q_PROPERTY(ModelServiseUDP* someProperty READ getSomeProperty WRITE setSomeProperty NOTIFY somePropertyChanged)
    Q_PROPERTY(ModelServiseUDP * model READ readModel WRITE setVin NOTIFY modelChanged)

public:
    explicit ClientUDP(); //no const
    ModelServiseUDP *model;
    void run();
    void setVin(const ModelServiseUDP* model){};
    ~ClientUDP();
    ModelServiseUDP *readModel() const
    {
        return model;
    }




signals:
void modelChanged();

public slots:
void setStatus(const int &);
void clearDataPool();
//void clearDataPool();

protected:

private:
};

#endif // CLIENTUDP_H
