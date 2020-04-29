#include "MortageLoanWorker.h"

#include <QDebug>

MortageLoanWorker::MortageLoanWorker(ItemEnums::EClientType client_type):IWorkerBaseClass(client_type)
{
    childWorker = this;
    qDebug()<< "create MortageLoanWorker";

    model_controller_ = static_cast<IModelControllerBase*>(new MortageModelController(ItemEnums::EClientType::kMortageLoanCalculator));


    initModel();

    //initWorker();
    //    this-> child = this;
    //    this->parser = new ParseServiceText (this, type);
    //    this->model = new ModelServiseText (this, type);
    //    this->proximodel = new ProxiModelServiseUDP (this, type);
    //    this->dataloader = new DateLoaderText (this, type);
}

void MortageLoanWorker::initModel(){

    qDebug()<< "MortageLoanWorker initModel+";

    //ui_proxi_models_
    IWidgetModelBase *calc_area = static_cast<IWidgetModelBase*>(new CalculatorWidgetModel(ItemEnums::EModelType::Calculator));
    p_model  p_calc(static_cast<QAbstractTableModel*>(calc_area));
    ui_proxi_models_.insert(int(ItemEnums::EModelType::Calculator),p_calc);
}



MortageLoanWorker::~MortageLoanWorker()
{
    qDebug()<< "~MortageLoanWorker" ;
}

