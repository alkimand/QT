//-Отдельное -целое окно в MDI area
#ifndef TOOLWIDGET_H
#define TOOLWIDGET_H

#include <constantlist.h> //для типа product
#include <firstwidget.h>
#include <QWidget>
#include <QMap>
class QDialogButtonBox;
class QLabel;
class QDateEdit;
class QModelIndex;
class QPushButton;
class QSplitter;
class QSqlRelationalTableModel;
class QTableView;
class QSqlDatabase;
class QLineEdit;
class QDataWidgetMapper;
class QSqlRelContactsModel;
class QToolBar;
class QTabWidget;
class GeneralProduct;
class ToolWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ToolWidget(QWidget *parent = nullptr);

    void newFile();
    bool save();
    bool saveAs();
    QSize sizeHint() const;
    QAction *windowMenuAction() const { return action; }

    static  ToolWidget *open(QWidget *parent = nullptr);
    static  ToolWidget *openFile(const QString &fileName,
                            QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void documentWasModified();
    void setProductType(const QString & );//ловить сигнал от FirstWidget и записывать в поле ProductType
    void test();
    setasktemplate();

private:
    bool okToContinue();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    bool readFile(const QString &fileName);
    bool writeFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    void createGeneralWidget();//My
    void createGeneralProduct();//My
    void createMapProduct();//My
    void LCreateKTPWidget();
    void LCreateControlWidget();
    //работа с шаблоном
    bool checktemplate(const QString &fileName);//проверяем есть ли шаблон по указанному пути
    void loadtemplate(const QString &fileName);

    QString curFile;
    bool isUntitled;
    QAction *action;
    QTabWidget *tabwidget;

    FirstWidget *GeneralWidget;//--
    GeneralProduct *Product;
    GeneralToolWidget *InfoWidget;//--

    QMap <QString, Enum_Type> Type_Map;
    QString ProductType;

    QList <GeneralToolWidget*> GeneralListOfWidget;//большие вижджеты внутри ToolWidget
    bool asktemplate;

};

#endif // TOOLWIDGET_H
