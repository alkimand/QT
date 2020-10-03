#ifndef APP_DATA_PROVIDER_H
#define APP_DATA_PROVIDER_H

#include "Item.h"
#include <QAbstractTableModel>
#include <QSharedPointer>
#include <QObject>
#include <QVector>

#include <QDesktopServices>
#include <QDebug>

#include <QQmlEngine>
#include <QQmlContext>

#include "AppModel.h"

class QStringList;

class AppDataProvider: public QObject {
    Q_OBJECT
    Q_PROPERTY(AppModel * model READ getModel  NOTIFY modelChanged)

public:
    AppDataProvider(QObject *parent = nullptr);
    void Init();
    ~AppDataProvider();

    //QML
public:
    AppModel *getModel() ;
    //qml
signals:
    void itemParsed(QString item_id, int view_id = -1);
    void modelChanged();

private:
    AppModel  *model_;

private:


public slots:
    void appStart();
    void parseItem(QString id, int view_id = -1);

    void openFile(const QString file_path);
    void saveFile(const QString file_path, const QString id);

    void deleteModel(const QString id);
    //AbstractTableItemData* getModelByID(const QString id);

//QML Layer
    //QString getFileTitleByID(const QString id);
    //QString getFilePathByID(const QString id);

    QString getDefaultDir();
};

#endif // APP_DATA_PROVIDER_H

