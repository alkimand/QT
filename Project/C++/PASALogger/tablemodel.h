#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QAbstractTableModel>
#include <QObject>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    enum Roles{
        DataRole = Qt::UserRole + 1,
        TimeStampRole,
        CountRole,
        ZoneIdRole,
        ServiseNameRole,
        FunctionRole,
        LineNumberRole,
        MessageRole
    };






    QStringList userRoleNames();
    int rowCount(const QModelIndex & = QModelIndex()) const override
    {
        return 60;
    }

    int columnCount(const QModelIndex & = QModelIndex()) const override
    {
        return 8;
    }

    QVariant data(const QModelIndex &index, int role) const override
    {
         int columnId = role - Qt::UserRole - 1;
         QModelIndex modelIndex = this->index(index.row(), columnId);
        //return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);

         switch (role)
        {
        case Qt::DisplayRole:
        {
            switch (index.column())
            {
            case 0:
                return QString("index.column()");
                break;
            case 1:
                return QString(index.column());
                break;
            case 3:
                return QString(index.column());
                break;
            case 4:
                return QString(index.column() + "Column");
                break;
            case 5:
                return QString(index.column() + "Column");
                break;
            case 6:
                return QString(index.column() + "Column");
                break;
            case 7:
                return QString(index.column() + "Column");
                break;
            case 8:
                return QString(index.column() + "Column");
                break;

            default:
                return QString("%1, %2").arg(index.column()).arg(index.row());
                break;
                //if (index.column()==1) return QString("%1, %2").arg(index.column()).arg(index.row());
            }
            //return QString("%1, %2").arg(index.column()).arg(index.row());
        }

        case CountRole:

            switch (index.column())
            {
            case 0:
            case 1:
            case 3:

                return QString( "index.column()");
                break;
            }


        default:
            return QString("NO tittle");
            break;

        }

        return QVariant();
    }
    //https://stackoverflow.com/questions/27230818/qml-tableview-with-dynamic-number-of-columns
    QHash<int, QByteArray> roleNames() const override
    {
        // QHash<int, QByteArray> roles = QAbstractTableModel::roleNames ();
        QHash<int, QByteArray> roles;
        roles[DataRole] = "Date/time";
        roles[CountRole] = "Count";
        roles[ZoneIdRole] = "ZoneId";
        roles[ServiseNameRole] = "ServiseName";
        roles[FunctionRole] = "Function";
        roles[LineNumberRole] = "LineNumber";
        roles[MessageRole] = "Message";
        //roles[Qt::DisplayRole] = "display";
        //roles[SomeRole1] = "tittle";
        return roles;
        //return { {Qt::DisplayRole, "display"},{SomeRole1, "tittle"} } ;
    }
};

#endif // INFO_H
