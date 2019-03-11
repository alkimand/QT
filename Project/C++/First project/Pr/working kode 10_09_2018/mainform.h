#ifndef MAINFORM_H
#define MAINFORM_H
//#include <QtSql>
#include <QWidget>
#include <QModelIndex>
#include <QSqlRelationalTableModel>
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
class MainForm : public QWidget

{
    Q_OBJECT

public:
    MainForm();

    void paintEvent(QPaintEvent *p2);

private slots:
    //https://evileg.com/ru/post/71/
    //void slotEditRecord(QModelIndex index);
    void addRowMainPanel();//Добавление строки с новой начальной датой
    void addRowVisitsPanel();//Добавление строки с новой начальной датой


    void saveGeometrySlot();
    void SetupSetting2slot();
    void test();

    void DeleteRowVisitsPanel();//удаление ненужной строки без обновление MainView
    void DeleteRowContactsPanel();
    void DeleteRowMainPanel();
    void ChengeDatafromVisitsPanel(int,QSqlRecord&); // изменение дат в MainView
    void ChengeDataToVisitsPanel(QModelIndex index1,QModelIndex index2 ,QVector<int> vect);//изменение даты в VisitsModel от сигнала в  MainModel
    void BugTracker();//выделение MainModel
    void BugTracker2();//выделение MainModel
    //void onCheckBoxChecked(bool isChecked);
    void updateVisitsPanel();
    void updateSityQLineEdit();//--
    void updateContactsPanel();

    void updateCompanyModel();
    void Debug();//+-
    //void updateRegionPanel();//--?
    void updateMapper(const QModelIndex &, const QModelIndex &);
    void updateSityModel();
    void updateRegionModel();

    //void updateMainDatabase();//обновление из полй даты и прочее в базу данных Mainmodel
    //void deleteDepartment();
    bool createConnection();
    void createFakeData();
    void createTruDate();//Дописать 15.08-дописано-отдельным проектом дописано, не вставил здесь (лучше отдельно)
    void createToolBar();
    void AddToolContVisitsBarSlot();//команда добавления из 3 виджетов сразу
    void DeleteContVisitsToolBarSlot();//команда удаления из 3 виджетов сразу
    void addNewRowContactsPanel();//Добавление новой строки Maintable
    void loadStyleCoffee();
    void loadStylePagefold();
    void loadStyleDefault();
    void loadStyleStyleHelper();
    void slotCustomMenuRequestedContactV(QPoint pos);
    void slotCustomMenuRequested(QPoint pos);
    void slotCustomMenuRequestedMain(QPoint pos);
    void goToHrefMainView();
    void goToMailContactsView();
protected:
    virtual void
    resizeEvent(QResizeEvent *event);//включить
    void closeEvent(QCloseEvent *);
    //void paintEvent( QPaintEvent *event );//https://forum.qt.io/topic/40151/solved-scaled-background-image-using-stylesheet/10

private:
    QMap <QString, double> OpenSetting(QString filename);
    //void SaveSetting(QMap <QString, double> , QString filename);
    //void SetupMainSetting();
    void loadStyleSheet(const QString &sheetName);

    void SetupSetting();
    void LoadSetting();
    void SetupSetting2();
    void saveGeometry();
    //Добавить копирование базы при старте и запись новой

    void CreateMainPanel();
    void CreateContactsPanel();
    //bool chekDataSQL(const QString &tableName,int column);//--?
    void CreateVisitsPanel();

    void createDatabase();//создание таблиц
    void SetupMainModel(const QString &tableName, const QStringList &headers);
    void SetupCompanyModel(const QString &tableName);
    void SetupContactsModel(const QString &tableName, const QStringList &headers);
    void SetupVisitsModel(const QString &tableName, const QStringList &headers);
    void SetupSityModel(const QString &tableName);
    void SetupStateModel(const QString &tableName);
    void CreateStyleHelper();


    void DropTable();


    QString getMainViewStyleSheet();
    void  draw ( QPainter *painter );


    //QSqlDatabase *db;
    QSqlDatabase  db2;
    QSqlRelationalTableModel *MainModel;
    QSqlRelationalTableModel *CompanyModel;
    QSqlRelContactsModel *ContactsModel;
    QSqlRelationalTableModel *VisitsModel;
    QSqlRelationalTableModel *SityModel;
    QSqlRelationalTableModel *StateModel;
    QSqlRelationalTableModel *SomethingModel;

    QWidget *MainPanel;
    QWidget *ContactsPanel;
    QWidget *VisitsPanel;
    QTableView *MainView;
    QTableView *ContactsView;
    QTableView *VisitsView;
    QSplitter *splitter;
    //++Можно вернуться к кнопкам
    //QDialogButtonBox *buttonBoxVisitsPanel;
    //QPushButton *addButtonVisitsPanel;
    //QPushButton *deleteButtonVisitsPanel;

    //QDialogButtonBox *buttonBoxContactsPanel;
    //QPushButton *addButtonContactsPanel;
    //QPushButton *deleteButtonContactsPanel;

    //QDialogButtonBox *buttonMainPanel;
    //QPushButton *addButtonMainPanel;
    //QPushButton *deleteMainPanel;

    //QDialogButtonBox *buttonBox;
    //QPushButton *addButton;
    // QPushButton *deleteButton;
    // QPushButton *editButton;
    //QPushButton *quitButton;
    //--
    QLabel *SityLabel;
    QLabel *Date1;
    QLabel *Date2;
    QLabel *Region;
    QLabel *NameOfCompany;
    QLabel *Marks;

    QLabel *label;//удалить

    QLineEdit *SityQLineEdit;
    QDateEdit *Date1QLineEdit;
    QDateEdit *Date2QLineEdit;
    QLineEdit *RegionQLineEdit;
    QLineEdit *NameOfCompanyQLineEdit;
    QLineEdit *MarksQLineEdit;
    QDataWidgetMapper *mapper;

    QToolBar *Visits_ContactToolBar;//http://qt-doc.ru/panel-instrumentov-qtoolbar-v-qt.html
    QSplitter *mainSplitter;
    QSplitter *rightSplitter;
    QSplitter *leftSplitter;
    //int SelectedID;//--
};


class  QSqlRelContactsModel : public QSqlRelationalTableModel
{
    Q_OBJECT
private slots:
    // void addNewRowContactsPanel();
    // void DeleteRowContactsPanel();


public:
    QSqlRelContactsModel(QObject *parent);
    //QSqlRelContactsModel(QObject *parent = 0);
    virtual  Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual QVariant data(const QModelIndex &item, int role) const;
    virtual bool setData(const QModelIndex &item, const QVariant &value, int role);
    // virtual
};


class MainPanel: public QWidget
{
    Q_OBJECT

public:
    MainPanel();
    //void paintEvent(QPaintEvent *p2);

public slots:
    //void saveGeometry();

protected:

    virtual void
    resizeEvent(QResizeEvent *event);
};
#endif

