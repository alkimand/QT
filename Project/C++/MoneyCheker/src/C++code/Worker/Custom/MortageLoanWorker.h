#ifndef WORKERMORTAGE_H
#define WORKERMORTAGE_H
#include "WorkerBaseClass.h"
#include <QObject>


class MortageLoanWorker: public IWorkerBaseClass
{

    Q_OBJECT

public:
    explicit MortageLoanWorker(ItemEnums::EClientType client_type);
    ~MortageLoanWorker();

    void initModel();
    //void changeCurrentDateIndex(int index);
   //void initWorker();

protected:


private:


};

#endif // WORKERMORTAGE_H
