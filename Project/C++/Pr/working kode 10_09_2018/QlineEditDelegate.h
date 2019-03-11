#ifndef MAINQLINEEDIT_H
#define MAINQLINEEDIT_H
#include <QDialog>
#include <QList>
#include <QItemDelegate>
#include <QHBoxLayout>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QLineEdit>
#include <Map>

class QDateEdit;
class QLineEdit;
class QDataWidgetMapper;
class QCheckBox;
class QComboBox;
class QSqlRelationalTableModel ;
class LineEditDelegate : public QItemDelegate
{
    Q_OBJECT

public://QSqlRelationalTableModel Model
    LineEditDelegate( QLineEdit *LineEdit,QString TableName, QString TableCulumnName,QSqlRelationalTableModel *Model, QObject *parent);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,//QLineEdit *MainQLineEdit,
               const QModelIndex &index) const;
    void drawBackground(QPainter *painter, const QStyleOptionViewItem &option,
                        const QModelIndex &index);
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private slots:
    void commitAndCloseEditor();
    void emitCommitData();

private:
    QString column;
    QLineEdit *DelegatLineEdit;
    QComboBox *comboBox;
    //QSqlRelationalTableModel &Model;
    QMultiMap <QString,int> map;
    QMultiMap <QString,int> *map2;//http://doc.qt.io/qt-5/qmultimap.html#detailsint
    QSqlRelationalTableModel *Model;
    //std::vector<std::string> Items;
    //QVector <QString> items;
    //QLineEdit *QLineEdit221;
    QString TableName;
    QString TableCulumnName;
    QLineEdit *LineEdit;
};

#endif
