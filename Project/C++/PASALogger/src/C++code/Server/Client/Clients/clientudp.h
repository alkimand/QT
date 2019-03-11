#ifndef CLIENTUDP_H
#define CLIENTUDP_H
#include "clientbase.h"

class ModelServiseBaseClass;
class ModelServiseUDP;
class ClientUDP: public ClientBase
{
    Q_OBJECT
    //Q_PROPERTY(ModelServiseUDP* someProperty READ getSomeProperty WRITE setSomeProperty NOTIFY somePropertyChanged)
    Q_PROPERTY(ModelServiseUDP * someProperty READ someProperty CONSTANT)

public:
    explicit ClientUDP();//no const
    ModelServiseUDP *model;

    //int getSomeProperty()const;
    //void setSomeProperty(const int & );


   // ModelServiseUDP* getSomeProperty()const;
    //void setSomeProperty(const ModelServiseUDP & );
    ModelServiseUDP* someProperty;

signals:
   //void somePropertyChanged();

public slots:


protected:

private:
};

#endif // CLIENTUDP_H
