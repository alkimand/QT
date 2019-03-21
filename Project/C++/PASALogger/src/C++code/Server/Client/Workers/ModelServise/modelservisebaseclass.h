#ifndef MODELSERVISEBASECLASS_H
#define MODELSERVISEBASECLASS_H
#include "settingmap.h"
#include "workerbaseclass.h"

#include <QObject>
#include <QAbstractTableModel>


//Proxi model
//https://stackoverrun.com/ru/q/10878631
//https://doc.qt.io/qt-5/qtwidgets-itemviews-customsortfiltermodel-example.html
//https://doc.qt.io/archives/qt-4.8/qsortfilterproxyModel.html

//https://evileg.com/ru/forum/topic/785/
//class QDir;


class  ModelServiseBaseClass: public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit  ModelServiseBaseClass(WorkerBaseClass *, CLIENT_TYPE const &);
     WorkerBaseClass *worker;
     ModelServiseBaseClass *parent;
     ModelServiseBaseClass *child;

     virtual  void data_model_handler(QStringList &) = 0;
     virtual void clearDataPool();
     virtual void saveAs();
     virtual void save();
     virtual ~ModelServiseBaseClass();
     QString fileName;
     QString defoultFileName;
     void getSaveFileName();
     void saveData();
     void openInExplorer();
     //QDir dir;
//     enum Roles{
//         DataRole = Qt::UserRole + 1,
//         TimeStampRole,
//         CountRole,
//         ZoneIdRole,
//         ServiseNameRole,
//         FunctionRole,
//         LineNumberRole,
//         MessageRole
//     };
//     QStringList userRoleNames();
//       int rowCount(const QModelIndex & = QModelIndex()) const override
//       {
//           return 60;
//       }

//       int columnCount(const QModelIndex & = QModelIndex()) const override
//       {
//           return 8;
//       }

//       QVariant data(const QModelIndex &index, int role) const override
//       {
//            int columnId = role - Qt::UserRole - 1;
//            QModelIndex modelIndex = this->index(index.row(), columnId);
//           //return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);

//            switch (role)
//           {
//           case Qt::DisplayRole:
//           {
//               switch (index.column())
//               {
//               case 0:
//                   return QString("index.column()");
//                   break;
//               case 1:
//                   return QString(index.column());
//                   break;
//               case 2:
//                   return QString(index.column());
//                   break;

//               default:
//                   //return QString("%1, %2").arg(index.column()).arg(index.row());
//                   break;
//                   //if (index.column()==1) return QString("%1, %2").arg(index.column()).arg(index.row());
//               }
//               //return QString("%1, %2").arg(index.column()).arg(index.row());
//           }

//           case CountRole:

//               switch (index.column())
//               {
//               case 0:
//               case 1:
//               case 3:

//                   return QString( "index.column()");
//                   break;
//               }


//           default:
//               return QString("NO tittle");
//               break;

//           }

//           return QVariant();
//       }
//       //https://stackoverflow.com/questions/27230818/qml-tableview-with-dynamic-number-of-columns
//       QHash<int, QByteArray> roleNames() const override
//       {
//           // QHash<int, QByteArray> roles = QAbstractTableModel::roleNames ();
//           QHash<int, QByteArray> roles;
//           roles[DataRole] = "Date/time";
//           roles[CountRole] = "Count";
//           roles[ZoneIdRole] = "ZoneId";
//           roles[ServiseNameRole] = "ServiseName";
//           roles[FunctionRole] = "Function";
//           roles[LineNumberRole] = "LineNumber";
//           roles[MessageRole] = "Message";
//           //roles[Qt::DisplayRole] = "display";
//           //roles[SomeRole1] = "tittle";
//           return roles;
//           //return { {Qt::DisplayRole, "display"},{SomeRole1, "tittle"} } ;
//       }



//     //virtual  void data_parser_handler(QDataStream &) = 0;

// //    QVector <QStringList> getData();

//protected:
    CLIENT_TYPE type;
    QVector <QStringList> v_data;
//    //virtual void create_connect_to_worker() = 0;
//    //QString first_line;
//   // QString last_line;
//   // QStringList str_data_list;


//signals:

////void model_sendData(QStringList & );

private:


//   // virtual  QStringList sl_parse_line(QString ) = 0;
////CLIENT_TYPE type;
};



#endif // MODELSERVISEBASECLASS_H
