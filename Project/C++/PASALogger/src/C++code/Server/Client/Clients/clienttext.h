#ifndef CLIENTTEXT_H
#define CLIENTTEXT_H
#include "clientbase.h"

#include <QObject>

#include "modelservistext.h"

class ClientText: public ClientBase
{
    Q_OBJECT
    //Q_PROPERTY(ModelServiseUDP* someProperty READ getSomeProperty WRITE setSomeProperty NOTIFY somePropertyChanged)
    //Q_PROPERTY(ModelServiseText * model READ readModel WRITE setVin NOTIFY modelChanged)

public:
    explicit ClientText(); //no const
//    ModelServiseText *model;

//    void setVin(const ModelServiseText* model){};

//    ModelServiseText *readModel() const
//    {
//        return model;
//    }




signals:
   //void modelChanged();

public slots:


protected:

private:
};

#endif // CLIENTTEXT_H
