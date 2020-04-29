#ifndef CLIENMORTAGE_H
#define CLIENMORTAGE_H
#include "ClientBase.h"
#include <QObject>


//#include "modelserviseudp.h"
//#include "proximodelserviseudp.h"

//https://habr.com/ru/post/140899/
//https://www.qtcentre.org/threads/48479-QAbstractListModel-does-not-update-QML-ListView
//https://yandex.ru/search/?text=emit%20dataChanged()%20qml&&lr=47



class MortageLoanClient: public ClientBase
{
    Q_OBJECT
    Q_PROPERTY(QAbstractTableModel* calculator_model_ READ getCalculatorModel WRITE setCalculatorModel NOTIFY CalculatorModelChanged)
public:
    explicit MortageLoanClient(ItemEnums::EClientType client_type); //no const

    // void instance();
    //    void setVin(const ModelServiseUDP *model);
    //    void setproximodel(const ProxiModelServiseUDP *proximodel);
    //    ModelServiseUDP *readModel() const;
    //    ProxiModelServiseUDP *readproxiModel() const;

    QAbstractTableModel *getCalculatorModel() const;
    void setCalculatorModel(const QAbstractTableModel *model);

    ~MortageLoanClient();



    QAbstractTableModel* calculator_model_;

protected:
    //ModelServiseUDP *model;
    //ProxiModelServiseUDP *proximodel;



signals:
    void CalculatorModelChanged();
    //void proxiModelChanged();

public slots:

    int getText();

protected:

private:
};

#endif // CLIENMORTAGE_H
