#ifndef MODELSERVISETEXT_H
#define MODELSERVISETEXT_H
#include "modelservisebaseclass.h"

#include <QObject>

class ModelServiseText : public ModelServiseBaseClass
{
    enum Roles
        {
            DATE, TIME, COUNT, ZONE, SERVICENAME, FUNCTIONNAME, LINENUMBER, MESSAGE
        };

Q_OBJECT


public:
    explicit  ModelServiseText(WorkerBaseClass *, CLIENT_TYPE const &);
    void data_model_handler(QStringList &);
    ~ ModelServiseText();

    void clearDataPool();
    void saveAsSlot();

    int rowCount(const QModelIndex &parent = QModelIndex()) const {
      Q_UNUSED(parent); return v_data.length();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const {
      Q_UNUSED(parent); return 8;
    }
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
   // Q_INVOKABLE void setAllChecked(bool value);
   // Q_INVOKABLE void setRowChecked(int row, bool value);

signals:

public slots:

private:
    void fillModel();

};

#endif // MODELSERVISEUDP_H
