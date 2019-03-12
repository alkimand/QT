#ifndef CLIENTUDP_H
#define CLIENTUDP_H
#include "clientbase.h"
#include <QObject>
#include "modelserviseudp.h"

//https://habr.com/ru/post/140899/




class ClientUDP: public ClientBase
{
    Q_OBJECT
    //Q_PROPERTY(ModelServiseUDP* someProperty READ getSomeProperty WRITE setSomeProperty NOTIFY somePropertyChanged)
    Q_PROPERTY(ModelServiseUDP * someProperty READ readsomeProperty)
    //Q_PROPERTY(int someProperty READ someProperty)


public:
    explicit ClientUDP(); //no const
    ModelServiseUDP *model;

   // int someProperty;

   // void setSomeProperty(ModelServiseUDP *){};


   // ModelServiseUDP* getSomeProperty()const;
    //void setSomeProperty(const ModelServiseUDP & );
    ModelServiseUDP * someProperty;


    ModelServiseUDP *readsomeProperty() const
    {
        return model;
    }

signals:
   //void somePropertyChanged();

public slots:


protected:

private:
};

#endif // CLIENTUDP_H
