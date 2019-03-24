#ifndef CLIENTUDP_H
#define CLIENTUDP_H
#include "clientbase.h"
#include <QObject>
#include "modelserviseudp.h"



class ClientUDP: public ClientBase
{
    Q_OBJECT
    Q_PROPERTY(ModelServiseUDP * model READ readModel WRITE setVin NOTIFY modelChanged)
    Q_PROPERTY(ProxiModelServiseUDP * proximodel READ readproxiModel WRITE setproximodel NOTIFY proxiModelChanged)

public:
    explicit ClientUDP(); //no const
    void run();
    void setVin(const ModelServiseUDP *model);

    ModelServiseUDP *readModel() const;
    ProxiModelServiseUDP *readproxiModel() const;
    void setproximodel(const ProxiModelServiseUDP *proximodel);
    ~ClientUDP();


protected:
    ModelServiseUDP *model;
    ProxiModelServiseUDP *proximodel;
signals:
    void modelChanged();
    void proxiModelChanged();
public slots:

protected:

private:
};

#endif // CLIENTUDP_H
