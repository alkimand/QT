#include "clienttext.h"
#include "workertext.h"
#include "modelservistext.h"

#include <QDebug>
#include <QQmlEngine>
#include <QQuickView>

ClientText::ClientText() : ClientBase()
{
    qDebug()<< "create ClientText";
    this->child = this;
    this->type = TXT_CLIENT_TYPE;
    //qmlRegisterType <ModelServiseUDP> ("ModuleName", 1, 0, "ModelServiseUDP");
}




