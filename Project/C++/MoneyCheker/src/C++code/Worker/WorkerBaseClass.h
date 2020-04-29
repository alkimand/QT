#ifndef WORKERBASECLASS_H
#define WORKERBASECLASS_H

#include <QObject>
#include <QVector>
#include <QStringList>
#include <QAbstractTableModel>
#include <QHash>
#include "MortageModelController.h"

#include "CalculatorArea_Model_1.h"

#include "props.h"
#include <QVector>

//class DataLoaderBaseClass;

//#include "dataloaderbaseclass.h"
//#include "dateloaderudp.h"
//#include "dateloadertext.h"
//#include "modelservisebaseclass.h"
//#include "proximodelservisebaseclass.h"



class IWorkerBaseClass: public QObject
{
    Q_OBJECT
public:
    //ClientBase *
    explicit IWorkerBaseClass( ItemEnums::EClientType client_type);
    virtual void test();
    virtual void initModel();
    virtual void refreshModel();
    void changeCurrentDateIndex(int index);
    p_model getModel(int index);
    virtual ~IWorkerBaseClass();
   // virtual ~IWorkerBaseClass();

protected:


public slots:
  //  void receive_data_loader_slot(QByteArray  const &);
   // void receive_data_parser_slot(QStringList  &);

protected:
//    ClientBase *client;
     ItemEnums::EClientType client_type_;
     IWorkerBaseClass *parentWorker= nullptr;
     IWorkerBaseClass *childWorker= nullptr;

     QVector <p_model> data_models_;

     //QVector <p_model> ui_proxi_models_;
     QHash <int, p_model> ui_proxi_models_;

     int            curent_index_model = 0;

     IModelControllerBase *model_controller_ = nullptr;


//    DataLoaderBaseClass *dataloader;
//    ParseServiceBaseClass *parser;

private:

};

#endif // WORKERBASECLASS_H
