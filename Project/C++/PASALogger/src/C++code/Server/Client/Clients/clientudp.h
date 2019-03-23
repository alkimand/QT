#ifndef CLIENTUDP_H
#define CLIENTUDP_H
#include "clientbase.h"
#include <QObject>
#include "modelserviseudp.h"

class ClientUDP: public ClientBase
{
    Q_OBJECT
    Q_PROPERTY(ModelServiseUDP * model READ readModel WRITE setVin NOTIFY modelChanged)

public:
    explicit ClientUDP(); //no const
    ModelServiseUDP *model;
    void run();
    void setVin(const ModelServiseUDP *model);
    ~ClientUDP();
    ModelServiseUDP *readModel() const
    {
        return model;
    }
signals:
void modelChanged();

public slots:

protected:

private:
};

#endif // CLIENTUDP_H
