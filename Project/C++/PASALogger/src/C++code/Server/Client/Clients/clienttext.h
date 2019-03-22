#ifndef CLIENTEXT_H
#define CLIENTEXT_H
#include "clientbase.h"
#include <QObject>
#include "modelserviseudp.h"
#include "proximodelserviseudp.h"

//https://habr.com/ru/post/140899/
//https://www.qtcentre.org/threads/48479-QAbstractListModel-does-not-update-QML-ListView
//https://yandex.ru/search/?text=emit%20dataChanged()%20qml&&lr=47



class ClientText: public ClientBase
{
    Q_OBJECT
    //Q_PROPERTY(ModelServiseUDP* someProperty READ getSomeProperty WRITE setSomeProperty NOTIFY somePropertyChanged)
    Q_PROPERTY(ModelServiseUDP * model READ readModel WRITE setVin NOTIFY modelChanged)
    Q_PROPERTY(ProxiModelServiseUDP * proximodel READ readproxiModel WRITE setproximodel NOTIFY proxiModelChanged)

public:
    explicit ClientText(); //no const
    ModelServiseUDP *model;
    ProxiModelServiseUDP *proximodel;


    void run();
    void setVin(const ModelServiseUDP *model);
    void setproximodel(const ProxiModelServiseUDP *proximodel);



    ~ClientText();
    ModelServiseUDP *readModel() const
    {
        return model;
    }

    ProxiModelServiseUDP *readproxiModel() const
    {
        return proximodel;
    }





signals:

   void modelChanged();
void proxiModelChanged();
public slots:
//   void setStatus(int const & ){};
//   void clearDataPool();
  // void saveAsSlot();
  // void clearDataPool();

protected:

private:
};

#endif // CLIENTUDP_H
