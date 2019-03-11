#ifndef CLIENTUDP_H
#define CLIENTUDP_H
#include "clientbase.h"
#include <QObject>
//https://stackoverflow.com/questions/6728615/warning-about-non-notifyable-properties-in-qml

class ModelServiseBaseClass;
class ModelServiseUDP;
class ClientUDP: public ClientBase
{
    Q_OBJECT
    //Q_PROPERTY(ModelServiseUDP* someProperty READ getSomeProperty WRITE setSomeProperty NOTIFY somePropertyChanged)
    Q_PROPERTY(ModelServiseUDP * someProperty READ someProperty)

public:
    explicit ClientUDP(); //no const
    ModelServiseUDP *model;

    //int getSomeProperty()const;
   // void setSomeProperty(ModelServiseUDP *){};


   // ModelServiseUDP* getSomeProperty()const;
    //void setSomeProperty(const ModelServiseUDP & );
    //ModelServiseUDP * someProperty;

    ModelServiseUDP *someProperty() const {
        return model;
    }

signals:
   //void somePropertyChanged();

public slots:


protected:

private:
};

#endif // CLIENTUDP_H
