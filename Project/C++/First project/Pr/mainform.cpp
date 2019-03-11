//#include <QtGui>
#include <QtSql>
#include <QtWidgets>

#include "mainform.h"
#include "mainform2.h"
#include "MainDelegate.h"
#include "VisitsDelegat.h"
#include "QlineEditDelegate.h"
#include "ContactsDelegate.h"
#include "ComboboxDelegate.h"
#include "ContactsCheckboxDelegate.h"
#include "stylehelper.h"
#include <QDesktopServices>

#include <QAxObject>
//#include <Qdebug>
//#include <QDebug>
#include <QGridLayout>
#include <QLineEdit>
#include <QDataWidgetMapper>
#include <QSqlDatabase>
#include <QSqlTableModel>

#include <QSqlRecord>
#include <QPixmap>
#include<QPalette>

//http://www.cyberforum.ru/qt/thread1366732.html празмеры таблицы
//https://stackoverflow.com/questions/22865201/qt-qtableview-implementing-toggle-button-and-checkbox-delegates чекбокс
MainForm::MainForm()
{
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowIcon(QPixmap(":/sourse/buttons/icon.png"));

    //bool existingData = QFile::exists(DATABASENAME);//Доделать проверку
    //if (!createion())
    this->createConnection();

    //Восстановление базы данных

    // this->DropTable();
    // this->createDatabase();
    //createFakeData();
    //this->createTruDate();
    SetupMainModel(TABLE_MAIN_NAMETBL ,     QStringList() << "id"
                   //<< trUtf8(TABLE_MAIN_NUMBER)
                   << TABLE_MAIN_SITY_HEADER
                   << TABLE_MAIN_STARTDATE_HEADER
                   << TABLE_MAIN_ENDDATE_HEADER
                   << TABLE_MAIN_REGION_HEADER
                   << TABLE_MAIN_COMPNANYNAME_HEADER
                   << TABLE_MAIN_MARKS_HEADER
                   << TABLE_MAIN_HREF_HEADER
                   );
    SetupContactsModel(TABLE_CONTACS_NAMETBL,     QStringList() << "id"
                       << ""
                       << TABLE_CONTACS_POST_HEADER
                       << TABLE_CONTACS_NameC_HEADER
                       << TABLE_CONTACS_TELEFON_HEADER
                       << TABLE_CONTACS_MAIL_HEADER
                       << TABLE_CONTACS_ROLE_HEADER
                       << TABLE_CONTACS_SOMETHING_HEADER
                       << TABLE_CONTACS_DATE_HEADER
                       );

    SetupVisitsModel(TABLE_VISITS_NAMETBL,     QStringList() << "id"
                     << ""
                     << TABLE_VISITS_FIRSTDATE_HEADER
                     << TABLE_VISITS_REASON_HEADER
                     << TABLE_VISITS_RESULT_HEADER
                     //<< trUtf8(TABLE_VISITS_OBJECT_HEADER)
                     << TABLE_VISITS_OBJECT_HEADER
                     << TABLE_VISITS_LASTDATE_HEADER
                     );
    SetupSityModel(TABLE_SITY_NAMETBL); //SityModel для пердачи не нулего значения в делегат MainPanel
    SetupStateModel(TABLE_STATE_NAMETBL);//STATE_Model для пердачи не нулего значения в делегат MainPanel
    SetupCompanyModel(TABLE_Company_NAMETBL);//TABLE_Company_NAMETBL для пердачи не нулего значения в делегат MainPanel
    CreateMainPanel();
    CreateContactsPanel();
    CreateVisitsPanel();
    rightSplitter = new QSplitter(Qt::Vertical,this);
    rightSplitter->addWidget(ContactsPanel);
    rightSplitter->addWidget(VisitsPanel);
    rightSplitter->setHandleWidth(5);

    // rightSplitter->setStretchFactor(1, 3);
    leftSplitter = new QSplitter(Qt::Vertical,this);
    leftSplitter->addWidget(MainPanel);

    //leftSplitter->setHandleWidth(5);
    //Можно вернуться к кнопкам
    //        buttonBox = new QDialogButtonBox;
    //        buttonBox->addButton(addButton, QDialogButtonBox::ActionRole);
    //        buttonBox->addButton(deleteButton, QDialogButtonBox::ActionRole);
    //         leftSplitter->addWidget( buttonBox);

    mainSplitter = new QSplitter(Qt::Horizontal,this);
    mainSplitter->addWidget(leftSplitter);
    mainSplitter->addWidget(rightSplitter);
    mainSplitter->setHandleWidth(5);
    //++Берем из Seting размеры
    //mainSplitter->setStretchFactor(0, 4);
    //mainSplitter->setStretchFactor(1, 3);
    //--

    // mainSplitter->setStretchFactor(2, 1);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(mainSplitter);
    setLayout(mainLayout);

    setWindowTitle(tr("Visits Manadger"));

    connect(MainView->selectionModel(),
            SIGNAL(currentRowChanged(const QModelIndex &,
                                     const QModelIndex &)),
            this, SLOT(updateVisitsPanel()));

    connect(MainView->selectionModel(),
            SIGNAL(currentRowChanged(const QModelIndex &,
                                     const QModelIndex &)),
            this, SLOT(updateContactsPanel()));

    connect(MainView->selectionModel(),
            SIGNAL(currentRowChanged(const QModelIndex &,
                                     const QModelIndex &)),
            this, SLOT(updateMapper(const QModelIndex &,
                                    const QModelIndex &)));
    connect(SityQLineEdit,
            SIGNAL(editingFinished()),
            this, SLOT(updateSityModel()));

    connect(RegionQLineEdit,
            SIGNAL(editingFinished()),
            this, SLOT(updateRegionModel()));

    connect(NameOfCompanyQLineEdit,
            SIGNAL(editingFinished()),
            this, SLOT(updateCompanyModel()));

    connect(VisitsModel,//вставка даны вниз
            SIGNAL(beforeUpdate(int,QSqlRecord&)),
            this, SLOT(ChengeDatafromVisitsPanel(int,QSqlRecord&)));

    connect(MainModel,
            SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)),
            this, SLOT(updateMapper(const QModelIndex &,
                                    const QModelIndex &)));

    connect(MainModel,
            SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)),
            this, SLOT(ChengeDataToVisitsPanel(QModelIndex,QModelIndex,QVector<int>)));

    //На будущее
    //    connect(MainView->horizontalHeader(),
    //            SIGNAL(geometriesChanged()),
    //            this, SLOT(Debug()));

    //    connect(MainView->horizontalHeader(),
    //         SIGNAL(sectionResized(int,int,int)),
    //            this, SLOT(test()));

    //    connect(leftSplitter,
    //            SIGNAL(splitterMoved(int,int)),
    //            this, SLOT(test()));
    //    connect(rightSplitter,
    //            SIGNAL(splitterMoved(int,int)),
    //            this, SLOT(test()));
    //    connect(mainSplitter,
    //            SIGNAL(splitterMoved(int,int)),
    //            this, SLOT(test()));


    //    connect(MainView->horizontalHeader(),
    //            SIGNAL(sectionResized(int,int,int)),
    //            this, SLOT(SetupSetting2()));//Debug
    //++

    //    QObject::disconnect(MainView->horizontalHeader(),
    //                        SIGNAL(sectionResized(int,int,int)),
    //                        this, SLOT(saveGeometrySlot()));
    //    QObject::disconnect(ContactsView->horizontalHeader(),
    //                        SIGNAL(sectionResized(int,int,int)),
    //                        this, SLOT(saveGeometrySlot()));
    //    QObject::disconnect(VisitsView->horizontalHeader(),
    //                        SIGNAL(sectionResized(int,int,int)),
    //                        this, SLOT(saveGeometrySlot()));

    connect(MainView->horizontalHeader(),
            SIGNAL(sectionResized(int,int,int)),
            this, SLOT(saveGeometrySlot()));

    connect(ContactsView->horizontalHeader(),
            SIGNAL(sectionResized(int,int,int)),
            this, SLOT(saveGeometrySlot()));

    connect(VisitsView->horizontalHeader(),
            SIGNAL(sectionResized(int,int,int)),
            this, SLOT(saveGeometrySlot()));

    // this->SetupSetting();//Делаю кнопками пока
    this->createToolBar();
    this->LoadSetting();

    //loadStyleSheet("coffee");//1
    //loadStyleSheet("pagefold");//2 - остановился на нем
    //CreateStyleHelper();//3
    MainView->setCurrentIndex(MainModel->index(0, 0));
}

MainForm::~MainForm()
{
    qDebug()<<"~MainForm() ";
  //  MainModel->deleteLater();
   // delete db2;
    delete MainModel;
    delete CompanyModel;
    delete ContactsModel;
    delete VisitsModel;
    delete SityModel;
    delete StateModel;
    //delete SomethingModel;
    delete MainPanel;
    delete ContactsPanel;
    delete VisitsPanel;
    delete MainView;
    delete ContactsView;
    delete VisitsView;
    delete splitter;
 qDebug()<<"~MainForm()2 ";
 QApplication::quit();


   // this->destroy(true,true);
}


void MainForm::addRowMainPanel()
{

    QSqlQuery query;
    QSqlQueryModel model;
    int id,i;
    int FinRowId;
    query.exec(QStringLiteral("INSERT INTO " TABLE_MAIN_NAMETBL  "(" TABLE_MAIN_SITY  ") VALUES ('1')"));
    // qDebug()<<"INSERT INTO " TABLE_MAIN_NAMETBL  "(" TABLE_MAIN_STARTDATE  ") VALUES ('" + now +  "')";
    QString str = QString(" SELECT MAX(id)   FROM " TABLE_MAIN_NAMETBL " ORDER BY id  DESC LIMIT 1");
    //qDebug()<<str;
    query.prepare(str);
    query.exec();
    query.next();
    if(query.value(0) != 0){
        id = query.value(0).toInt();
    }
    MainModel->select();
    for (i=0;i<=MainModel->rowCount();i++)
    {
        if (MainModel->data(MainModel->index(i,MAIN_stasus_Id), Qt::DisplayRole).toInt()==id)
        {
            FinRowId = i;
            break;
        }
    }
    QItemSelectionModel *selectionModel = MainView->selectionModel();
    selectionModel->clearSelection();
    QModelIndex topLeft;
    QModelIndex bottomRight;

    topLeft = MainModel->index(FinRowId, MAIN_Sity, QModelIndex());
    bottomRight = MainModel->index(FinRowId, MAIN_Marks, QModelIndex());
    QItemSelection selection(topLeft, bottomRight);
    selectionModel->select(selection, QItemSelectionModel::Select);
}

bool MainForm::createConnection()
{
    //https://evileg.com/ru/post/67/
    //this->db2 = new QSqlDatabase();
    qDebug()<< QSqlDatabase::drivers();

    this->db2 = QSqlDatabase::addDatabase("QSQLITE");
    //this->db2.addDatabase("QSQLITE");
    this->db2.setDatabaseName(DATABASENAME);
    this->db2.open();

    //qDebug()<< QSqlDatabase::drivers();
    //this->db  = & db;

    //        db = new QSqlDatabase();
    //        //db = QSqlDatabase::addDatabase("QSQLITE");
    //        db->addDatabase("QSQLITE");
    //        db->setDatabaseName(DATABASENAME);
    //        db->open();





    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //QSqlDatabase::database()

    //db.addDatabase("QSQLITE");
    //db->addDatabase("QSQLITE")

    //QSqlDatabase *db = &(QSqlDatabase::addDatabase("QSQLITE"));
    //this->db->setDatabaseName(DATABASENAME);
    //this->db.setDatabaseName(DATABASENAME);
    // db.setDatabaseName(DATABASENAME);
    //db.setHostName();
    //qDebug()<<"db.QSqlDatabase::connectOptions()" << db.QSqlDatabase::connectOptions();
    if (!db2.open()) {
        //    if (db.open()) {
        QMessageBox::warning(0, QObject::tr(DATABASENAME),
                             db2.lastError().text());
        //        return false;
        //    }
        //    return true;
    }
}
//https://evileg.com/ru/forum/topic/120/
//http://doc.qt.io/qt-5/qsqldatabase.html#open-1


void MainForm::DropTable()
{
    QSqlQuery query;
    query.exec("DROP TABLE " TABLE_Company_NAMETBL);
    query.exec("DROP TABLE " TABLE_MAIN_NAMETBL);
    query.exec("DROP TABLE " TABLE_CONTACS_NAMETBL);
    query.exec("DROP TABLE " TABLE_VISITS_NAMETBL);
    query.exec("DROP TABLE " TABLE_SITY_NAMETBL);
    query.exec("DROP TABLE " TABLE_STATE_NAMETBL);
    query.exec("DROP TABLE " TABLE_SOMETHINGELSE_NAMETBL);
    qApp->processEvents();
}

QString MainForm::getMainViewStyleSheet()
{
    return "QTableView { "
           "background-color: white; "
           "color: black; "
           "border: 1px solid #e2e2de;"
           "}"
           "QTableView::item:selected {"
           "background-color: #de8e37;"
           "}"
           "QHeaderView::section:horizintal {"
           "background-color: white;"
           "border-style: none;"
           "color: black; "
           "border: 1px solid #e2e2de; "
           "padding: 6px; "
           "}";
}

void MainForm::createDatabase()
{
    //http://www.w3big.com/ru/sql/sql-default.html

    {   //QProgressDialog progress;
        //    progress.setWindowModality(Qt::WindowModal);
        //    progress.setWindowTitle(QObject::tr("Staff Manager"));
        //    progress.setLabelText(QObject::tr("Creating database..."));
        //    progress.setMinimum(0);
        //    progress.setMaximum(NumberEn.count() + 6);
        //    progress.setValue(1);
    }
    QSqlQuery query;

    //1.0_____________________________Create TABLE_Company_NAMETBL   ****************************
    if(!query.exec( "CREATE TABLE " TABLE_Company_NAMETBL   " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_Company_NAME_TITLE     " VARCHAR(40) NOT NULL"
                    " )"
                    )) //условие при невыполнении
    {
        qDebug() << "DataBase: error of create - " << TABLE_Company_NAMETBL;
        qDebug() << query.lastError().text();
    }

    qApp->processEvents();
    QString CurrentDate=QDate::currentDate().toString("yyyy-MM-dd");
    //QString now=("2015-15-10");//"2000-01-28"
    // qDebug()<<now;

    //"//DEFAULT " //+ now +" ,"
    //1.1_____________________________Create TABLE_MAIN_NAMETBL  ****************************
    if(!query.exec( "CREATE TABLE " TABLE_MAIN_NAMETBL   " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    //TABLE_MAIN_NUMBER      " INTEGER NOT NULL,"
                    TABLE_MAIN_SITY          " INTEGER  NULL DEFAULT '1',"
                    //TABLE_MAIN_SITY        " VARCHAR(40) NOT NULL,"
                    TABLE_MAIN_STARTDATE     " DATE NULL DEFAULT '"  + CurrentDate + "',"

                    TABLE_MAIN_ENDDATE       " DATE NULL DEFAULT '"  + CurrentDate + "',"
                    TABLE_MAIN_REGION        " INTEGER  NULL DEFAULT '1',"
                    //TABLE_MAIN_COMPNANYNAME" VARCHAR(40) DEFAULT 'p2'"
                    TABLE_MAIN_COMPNANYNAME  " INTEGER  NULL DEFAULT '1',"
                    TABLE_MAIN_MARKS         " VARCHAR(40) DEFAULT '" DEFOLT "',"
                    TABLE_MAIN_HREF          " VARCHAR(40) "
                    // "FOREIGN KEY (" TABLE_MAIN_SITY ") REFERENCES" TABLE_SITY_NAMETBL")"));
                    " )"
                    )) //условие при невыполнении
    {

        qDebug() << "DataBase: error of create - " << TABLE_MAIN_NAMETBL;
        qDebug() << query.lastError().text();
    }
    qApp->processEvents();


    //1.2_____________________________Create TABLE_CONTACS_NAMETBL  ****************************
    if(!query.exec( "CREATE TABLE " TABLE_CONTACS_NAMETBL   " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_CONTACS_NUMBER_COMP        " INTEGER NOT NULL DEFAULT 1 ,"
                    TABLE_CONTACS_POST               " VARCHAR(40)  NULL,"
                    TABLE_CONTACS_NameC              " VARCHAR(40)  NULL,"
                    TABLE_CONTACS_TELEFON            " INTEGER  NULL,"
                    TABLE_CONTACS_MAIL               " VARCHAR(40) NULL,"
                    TABLE_CONTACS_ROLE               " VARCHAR(40)  NULL,"
                    TABLE_CONTACS_SOMETHING          " VARCHAR(40)  NULL,"
                    TABLE_CONTACS_DATE               " DATE  NULL"
                    " )"
                    )) //условие при невыполнении
    {
        qDebug() << "DataBase: error of create - " << TABLE_CONTACS_NAMETBL;
        qDebug() << query.lastError().text();
    }

    qApp->processEvents();

    //1.3_____________________________Create TABLE_VISITS_NAMETBL  ****************************
    if(!query.exec( "CREATE TABLE " TABLE_VISITS_NAMETBL   " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_VISITS_TOCOMPANY              " INTEGER NOT NULL DEFAULT 1 ,"
                    TABLE_VISITS_FIRSTDATE              " DATE  NULL, "
                    TABLE_VISITS_REASON                 " VARCHAR(40)  NULL,"
                    TABLE_VISITS_RESULT                 " VARCHAR(40) NULL,"
                    TABLE_VISITS_OBJECT                 " INTEGER  NULL,"
                    TABLE_VISITS_LASTDATE               " DATE NULL"
                    " )"
                    )) //условие при невыполнении
    {
        qDebug() << "DataBase: error of create - " << TABLE_VISITS_NAMETBL;
        qDebug() << query.lastError().text();
    }
    qApp->processEvents();


    //1.4_____________________________Create TABLE_SITY_NAMETBL   ****************************
    if(!query.exec( "CREATE TABLE " TABLE_SITY_NAMETBL    " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_SITY_Name                 " VARCHAR(40) NOT NULL"
                    " )"
                    )) //условие при невыполнении
    {
        qDebug() << "DataBase: error of create - " << TABLE_SITY_NAMETBL;
        qDebug() << query.lastError().text();
    }
    qApp->processEvents();

    //1.5_____________________________Create TABLE_STATE_NAMETBL   ****************************
    if(!query.exec( "CREATE TABLE " TABLE_STATE_NAMETBL    " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_STATE_STATE                 " VARCHAR(40) NOT NULL"
                    " )"
                    )) //условие при невыполнении
    {
        qDebug() << "DataBase: error of create - " << TABLE_STATE_NAMETBL;
        qDebug() << query.lastError().text();
    }

    qApp->processEvents();
    //1.6_____________________________TABLE_SOMETHINGELSE_NAMETBL   ****************************
    if(!query.exec( "CREATE TABLE " TABLE_SOMETHINGELSE_NAMETBL    " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_SOMETHINGELSE_SOMETHING     " VARCHAR(40) NOT NULL"
                    " )"
                    )) //условие при невыполнении
    {
        qDebug() << "DataBase: error of create - " << TABLE_SOMETHINGELSE_NAMETBL;
        qDebug() << query.lastError().text();
    }
}

void MainForm::SetupMainModel(const QString &tableName, const QStringList &headers)
{
    MainModel = new QSqlRelationalTableModel(this);
    MainModel->setTable(tableName);

    //MainModel->select();
    MainModel->setRelation(MAIN_Sity,QSqlRelation(TABLE_SITY_NAMETBL, "id", TABLE_SITY_Name));
    MainModel->setRelation(MAIN_Region,QSqlRelation(TABLE_STATE_NAMETBL, "id", TABLE_STATE_STATE));
    MainModel->setRelation(MAIN_ComName,QSqlRelation(TABLE_Company_NAMETBL, "id", TABLE_Company_NAME_TITLE));
    //  MainModel->setSort(0, Qt::AscendingOrder);
    MainModel->setEditStrategy(QSqlTableModel:: OnFieldChange);
    MainModel->select();
    // MainModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    for(int i = 0, j = 0; i < MainModel->columnCount(); i++, j++){
        MainModel->setHeaderData(i,Qt::Horizontal,headers[j]);
        //qDebug()<< (MainModel->data(MainModel->index(0,i), Qt::DisplayRole).toString());
    }

}

void MainForm::SetupCompanyModel(const QString &tableName)
{
    CompanyModel= new QSqlRelationalTableModel(this);
    CompanyModel->setTable(tableName);
    CompanyModel->select();
    CompanyModel->setEditStrategy(QSqlTableModel::OnFieldChange);
}

void MainForm:: SetupContactsModel(const QString &tableName, const QStringList &headers)
{
    // ContactsModel = new QSqlRelationalTableModel(this);
    ContactsModel= new QSqlRelContactsModel(this);
    ContactsModel->setTable(tableName);
    ContactsModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    ContactsModel->select();
    for(int i = 0, j = 0; i < ContactsModel->columnCount(); i++, j++){
        ContactsModel->setHeaderData(i,Qt::Horizontal,headers[j]);
        //qDebug()<< (ContactsModel->data(ContactsModel->index(1,i), Qt::DisplayRole).toString());
    }

}

void MainForm:: SetupVisitsModel(const QString &tableName, const QStringList &headers)
{
    VisitsModel= new QSqlRelationalTableModel(this);
    VisitsModel->setTable(tableName);
    VisitsModel->select();

    VisitsModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    for(int i = 0, j = 0; i < VisitsModel->columnCount(); i++, j++){
        VisitsModel->setHeaderData(i,Qt::Horizontal,headers[j]);
    }

}//model->submitAll()

void MainForm:: SetupSityModel(const QString &tableName)
{
    SityModel= new QSqlRelationalTableModel(this);
    SityModel->setTable(tableName);
    SityModel->select();
    SityModel->setEditStrategy(QSqlTableModel::OnFieldChange);
}

void MainForm::SetupStateModel(const QString &tableName)
{
    StateModel= new QSqlRelationalTableModel(this);
    StateModel->setTable(tableName);
    StateModel->select();
    StateModel->setEditStrategy(QSqlTableModel::OnFieldChange);
}

void MainForm::CreateStyleHelper()
{
    MainView->setStyleSheet(StyleHelper:: getQTableViewSheet()+
                            StyleHelper::getQComboboxSheet()+
                            StyleHelper::getQLineEditTableWiewSheet()+
                            StyleHelper::getQDateEditTableWiewSheet());
    ContactsView->setStyleSheet(StyleHelper:: getQTableViewSheet()+
                                StyleHelper::getQComboboxSheet()+
                                StyleHelper::getQLineEditTableWiewSheet()+
                                StyleHelper::getQDateEditTableWiewSheet());
    VisitsView->setStyleSheet(StyleHelper:: getQTableViewSheet()+
                              StyleHelper::getQComboboxSheet()+
                              StyleHelper::getQLineEditTableWiewSheet()+
                              StyleHelper::getQDateEditTableWiewSheet());


    // MainPanel->setStyleSheet(StyleHelper::getWindowStyleSheet());

    leftSplitter->setHandleWidth(50);
    mainSplitter->setStyleSheet (StyleHelper:: getQSplitterSheet());
    rightSplitter->setStyleSheet (StyleHelper:: getQSplitterSheet());

    //    //
    SityQLineEdit->setStyleSheet(StyleHelper::getQLineEditSheet());
    RegionQLineEdit->setStyleSheet(StyleHelper::getQLineEditSheet());
    NameOfCompanyQLineEdit->setStyleSheet(StyleHelper::getQLineEditSheet());
    MarksQLineEdit->setStyleSheet(StyleHelper::getQLineEditSheet());
    Date1QLineEdit->setStyleSheet(StyleHelper::getQDateEditSheet());
    Date2QLineEdit->setStyleSheet(StyleHelper::getQDateEditSheet());


    SityLabel->setStyleSheet(StyleHelper::StyleHelper::getLabelStyleSheet());
    Date1->setStyleSheet(StyleHelper::StyleHelper::getLabelStyleSheet());
    Date2->setStyleSheet(StyleHelper::StyleHelper::getLabelStyleSheet());
    Region->setStyleSheet(StyleHelper::StyleHelper::getLabelStyleSheet());
    NameOfCompany->setStyleSheet(StyleHelper::StyleHelper::getLabelStyleSheet());
    Marks->setStyleSheet(StyleHelper::StyleHelper::getLabelStyleSheet());

    //https://stackoverflow.com/questions/14703899/qwidget-background-image-fit
    MainPanel->setStyleSheet(StyleHelper::getMainPanelStyleSheet());
    ContactsPanel->setStyleSheet(StyleHelper::getContactsPanelStyleSheet());
    VisitsPanel->setStyleSheet(StyleHelper::getVisitsPanelStyleSheet());
}

void MainForm::createFakeData(){
    QSqlQuery query;
    // progress.setValue(5);
    qApp->processEvents();
    //************************  stasus  ****************
    //    QAxObject* excel = new QAxObject("Excel.Application", 0);
    //    excel->dynamicCall( "SetVisible(bool)", TRUE ); //делаем его видимым
    //    QAxObject* workbooks = excel->querySubObject("Workbooks");
    //    QAxObject* workbook = workbooks->querySubObject("Open(const QString&)", "D:\\doc.xlsx");
    //    QAxObject* sheets = workbook->querySubObject("Worksheets");
    //    QAxObject* sheet = sheets->querySubObject("Item(int)", 1);
    //sheets->property("Count").toInt();

    query.exec("INSERT INTO " TABLE_SITY_NAMETBL "(" TABLE_SITY_Name ") VALUES ("
                                                                     "'Не указано')");
    query.exec("INSERT INTO " TABLE_SITY_NAMETBL "(" TABLE_SITY_Name ") VALUES ("
                                                                     "'Дзержинск')");
    query.exec("INSERT INTO " TABLE_SITY_NAMETBL "(" TABLE_SITY_Name ") VALUES ("
                                                                     "'Балахна')");

    query.exec("INSERT INTO " TABLE_STATE_NAMETBL "(" TABLE_STATE_STATE ") VALUES ("
                                                                        "'Не указано')");

    query.exec("INSERT INTO " TABLE_STATE_NAMETBL "(" TABLE_STATE_STATE ") VALUES ("
                                                                        "'Нижегородская')");
    query.exec("INSERT INTO " TABLE_STATE_NAMETBL "(" TABLE_STATE_STATE ") VALUES ("
                                                                        "'Балахна')");

    query.exec("INSERT INTO " TABLE_MAIN_NAMETBL  "(" TABLE_MAIN_SITY "," TABLE_MAIN_COMPNANYNAME ") VALUES ("
                                                                                                  "'1', '2' )");

    query.exec("INSERT INTO " TABLE_MAIN_NAMETBL  "(" TABLE_MAIN_SITY "," TABLE_MAIN_COMPNANYNAME ") VALUES ("
                                                                                                  "'1', '3' )");


    query.exec(QStringLiteral("INSERT INTO " TABLE_Company_NAMETBL  "(" TABLE_Company_NAME_TITLE  ") VALUES ("
                                                                                                  "'Не указано')"));
    query.exec(QStringLiteral("INSERT INTO " TABLE_Company_NAMETBL  "(" TABLE_Company_NAME_TITLE  ") VALUES ("
                                                                                                  "'Энергопром')"));
    query.exec(QStringLiteral("INSERT INTO " TABLE_Company_NAMETBL  "(" TABLE_Company_NAME_TITLE  ") VALUES ("
                                                                                                  "'Альтаир')"));

    query.exec("INSERT INTO " TABLE_CONTACS_NAMETBL  "(" TABLE_CONTACS_NameC  "," TABLE_CONTACS_NUMBER_COMP ") VALUES ("
                                                                                                            "'11',1)");
    query.exec("INSERT INTO " TABLE_CONTACS_NAMETBL  "(" TABLE_CONTACS_NameC "," TABLE_CONTACS_NUMBER_COMP ") VALUES ("
                                                                                                           "'12',2)");
    query.exec("INSERT INTO " TABLE_CONTACS_NAMETBL  "(" TABLE_CONTACS_NameC "," TABLE_CONTACS_NUMBER_COMP ") VALUES ("
                                                                                                           "'13',3)");

    query.exec("INSERT INTO " TABLE_VISITS_NAMETBL  "(" TABLE_VISITS_TOCOMPANY  "," TABLE_VISITS_REASON ") VALUES ("
                                                                                                        "'1',123)");
    query.exec("INSERT INTO " TABLE_VISITS_NAMETBL  "(" TABLE_VISITS_TOCOMPANY  "," TABLE_VISITS_REASON ") VALUES ("
                                                                                                        "'2',234)");
    query.exec("INSERT INTO " TABLE_VISITS_NAMETBL  "(" TABLE_VISITS_TOCOMPANY  "," TABLE_VISITS_REASON ") VALUES ("
                                                                                                        "'1',567)");
    query.exec("INSERT INTO " TABLE_VISITS_NAMETBL  "(" TABLE_VISITS_TOCOMPANY  "," TABLE_VISITS_REASON ") VALUES ("
                                                                                                        "'2',525)");
}

void MainForm::createTruDate()
{
    QSqlQuery query;
    QStringList list;
    QAxObject* excel = new QAxObject( "Excel.Application", this );
    QAxBase* workbooks2 = excel->querySubObject( "Workbooks" );
    QAxBase* workbook2 = workbooks2->querySubObject( "Open(const QString&)", "D:\\doc.xls" );//D:\\doc.xls
    QAxObject* sheets3 = workbook2->querySubObject("Worksheets");//База Хлебников А_v1.3.xls
    QAxObject* sheet = sheets3->querySubObject("Item(int)", 12);//++
    //qDebug()<<sheets3->property("Name").toInt();
    QAxObject* usedRange = sheet->querySubObject("UsedRange");
    QAxObject* rows = usedRange->querySubObject("Rows");
    int countRows = rows->property("Count").toInt();
    QAxObject* columns = usedRange->querySubObject("Columns");
    int countCols = columns->property("Count").toInt();
    for ( int row = 0; row < countRows; row++ ) {
        for ( int column = 0; column < countCols; column++ ){
            QAxObject* cell = sheet->querySubObject("Cells(int,int)", row + 1, column + 1);//column
            QVariant value = cell->property("Value");

            //qDebug()<<value.toString();
            list.append(value.toString());
        }

        query.exec("INSERT INTO " TABLE_Company_NAMETBL  "(" TABLE_MAIN_SITY "," TABLE_MAIN_COMPNANYNAME ") VALUES ("

                                                                                                         "'1', '3' )");
    }
}

void MainForm::createToolBar()
{
    this->Visits_ContactToolBar = new QToolBar("Linker ToolBar",this);
    Visits_ContactToolBar->addSeparator();
    Visits_ContactToolBar->setMovable(true);
    Visits_ContactToolBar->addAction(QPixmap(":/sourse/buttons/new_folder.png"),"Добавить",this,SLOT(AddToolContVisitsBarSlot()));
    Visits_ContactToolBar->addAction(QPixmap(":/sourse/buttons/delete.png"),"Удалить",this,SLOT(DeleteContVisitsToolBarSlot()));
    Visits_ContactToolBar->addSeparator();
    Visits_ContactToolBar->addSeparator();
    Visits_ContactToolBar->addSeparator();
    Visits_ContactToolBar->addAction(QPixmap(":/sourse/buttons/coffee.png"),"Coffe",this,SLOT(loadStyleCoffee()));
    Visits_ContactToolBar->addAction(QPixmap(":/sourse/buttons/pagefold.jpg"),"Pagefold",this,SLOT(loadStylePagefold()));
    Visits_ContactToolBar->addAction(QPixmap(":/sourse/buttons/Default.jpg"),"Defolt",this,SLOT(loadStyleDefault()));
    // Visits_ContactToolBar->addAction(QPixmap(":/sourse/buttons/Alien_Swarm.png"),"Stellaris",this, SLOT(loadStyleStyleHelper()));
    Visits_ContactToolBar->addAction(QPixmap(":/sourse/buttons/refresh3.png"),"Refresh",this,SLOT(SetupSetting2slot()));
    Visits_ContactToolBar->setCursor(Qt::PointingHandCursor);//&http://doc.qt.io/qt-5/qt.html#CursorShape-enum
}

void MainForm::AddToolContVisitsBarSlot()
{
    if (QApplication::focusWidget()==ContactsView)
    {
        this->addNewRowContactsPanel();
        //qDebug()<<"ContactsView->hasFocus";
    }//
    else if (QApplication::focusWidget()==VisitsView)
    {
        this-> addRowVisitsPanel();
        //qDebug()<<"VisitsPanel->hasFocus";
    }
    else if (QApplication::focusWidget()==MainView)
    {
        this-> addRowMainPanel();
        // qDebug()<<"MainView->hasFocus";
    }

    // else qDebug()<<"No Focus"<<QApplication::focusWidget()<<" vs "<< ContactsView;
}

void MainForm::DeleteContVisitsToolBarSlot()
{
    if (QApplication::focusWidget()==ContactsView)
    {
        this->DeleteRowContactsPanel();
        //qDebug()<<"ContactsView->hasFocus";
    }
    else if (QApplication::focusWidget()==VisitsView)
    {
        this-> DeleteRowVisitsPanel();
        // qDebug()<<"VisitsPanel->hasFocus";
    }
    else if (QApplication::focusWidget()==MainView)
    {
        this-> DeleteRowMainPanel();
        // qDebug()<<"MainView->hasFocus";
    }
}

void MainForm::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED( event)

    saveGeometry();//включить

}

void MainForm::closeEvent(QCloseEvent *)
{
    Q_CLEANUP_RESOURCE(qrc);
    qDebug() << "closeEvent";
    //QSqlQuery query;
    // this->db->close();
    //this->db.close();
    qDebug() << "db2.close()";
    this->db2.close();
    qDebug() << "db2.isOpen() = " << db2.isOpen();
    db2.lastError();

    qDebug() << " db2.lastError(); = " << db2.lastError();


    this->destroy(true,true);
    //Qt::WM_CLOSE
    // QProcess process=QProcess :
    //QProcess::terminate();
    //QProcess::kill();
    //qrc
    //http://doc.crossplatform.ru/qt/4.6.x/qdir.html#Q_CLEANUP_RESOURCE
    //qApp->closeAllWindows();
    //qApp->quit()










    qDebug() << " this->close(); = "<< this->close();


}

//void MainPanel::paintEvent(QPaintEvent *p2)

//{    //Q_UNUSED(p2)
//            qDebug()<<"MainPanel paintEvent  ";

//            QPainter painter ( this );
//              painter.setRenderHint ( QPainter :: Antialiasing, true );


//               painter.setPen (Qt::blue );
//               painter.drawText ( rect(), Qt::AlignCenter, "The Text" );
//draw ( &painter )
//}





//    const QString fname(":/sourse/stellaris/ContactsPanel.png");
//    QPixmap pix;
//    if(QPixmapCache::find(fname, &pix) == false) {
//        pix.load(fname);
//        if(pix.isNull() == false) {
//            QRect dst_rc = rect();

//            if(dst_rc.width() > dst_rc.height())
//                pix = pix.scaledToHeight(dst_rc.height());
//            else if(dst_rc.height() > dst_rc.width())
//                pix = pix.scaledToWidth(dst_rc.width());

//            QPixmapCache::insert(fname, pix);
//        }
//    }
//    if(pix.isNull() == false) {
//        QRect dst_rc = pix.rect();
//        dst_rc.moveCenter(rect().center());

//        QPainter painter(this);
//        painter.drawPixmap(dst_rc, pix);

//    }
//++
//    QPixmap pix(":/sourse/stellaris/MainPanel.png");
//    QImage img(":/sourse/stellaris/MainPanel.png");
//    QLabel *label = new QLabel(this);
//    label->setPixmap(QPixmap::fromImage(img));
//    QRect dst_rc = this->rect();
//    if(dst_rc.width() > dst_rc.height())
//                pix = pix.scaledToHeight(dst_rc.height());
//    else if(dst_rc.height() > dst_rc.width())
//        pix = pix.scaledToWidth(dst_rc.width());
//    dst_rc = pix.rect();
//    dst_rc.moveCenter(this->rect().center());
//    QPainter painter(this);
//    painter.drawPixmap(dst_rc, pix);

//--

// this->setAttribute(Qt::WA_NoSystemBackground);
//this->setWindowOpacity(0.0);
//label->setAttribute(Qt::WA_NoSystemBackground);
//label->setAttribute(Qt::WA_PaintOnScreen);
//label->setAttribute(Qt::WA_PaintOnScreen);

//setAttribute(Qt::WA_PaintOnScreen);
//setAttribute(Qt::WA_OpaquePaintEvent);
//setAttribute(Qt::WA_NoSystemBackground);
//qDebug()<<"MainPanel::paintEvent";



void MainPanel::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
}

void MainForm::CreateMainPanel(){
    MainPanel = new QWidget(this);
    MainView = new QTableView(this);
    MainView->setItemDelegate(new QSqlRelationalDelegate(this));//!!!!!!!!!!!!!!!!!!!!!!!
    MainView ->setModel(MainModel);
    MainView->setSelectionMode(
                QAbstractItemView::SingleSelection);
    MainView->setColumnHidden(MAIN_stasus_Id, true);
    //   MainView->setf
    MainView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //MainView->resizeColumnsToContents();
    MainView->horizontalHeader()->setStretchLastSection(true);
    MainView->setSortingEnabled(true);
    //MainView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //connect(MainView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditRecord(QModelIndex)));

    //QGridLayout * grid = new QGridLayout(this);

    //grid->addWidget(MainView, 0,0,5,6);

    this->SityLabel=new QLabel(tr("Город"), this);
    this->Date1=new QLabel(tr("Дата"), this);
    this->Date2=new QLabel(tr("Дата повтора"), this);
    this->Region=new QLabel(tr("Регион"), this) ;
    this->NameOfCompany=new QLabel(tr("Название компании"), this);
    this->Marks=new QLabel(tr("Отметки"), this);

    //++QHBoxLayout
    //    QHBoxLayout *Hlayout = new QHBoxLayout;
    //    Hlayout->addWidget(this->SityLabel, Qt::AlignHCenter);
    //    Hlayout->addWidget(this->Date1,Qt::AlignHCenter);
    //    Hlayout->addWidget(this->Date2,Qt::AlignHCenter);
    //    Hlayout->addWidget(this->Region,Qt::AlignHCenter);
    //    Hlayout->addWidget(this->NameOfCompany,Qt::AlignHCenter);
    //    Hlayout->addWidget(this->Marks,Qt::AlignHCenter);//AlignRight
    //--QHBoxLayout


    this->SityQLineEdit=new QLineEdit(this);
    this->Date1QLineEdit=new QDateEdit(this);
    this->Date1QLineEdit->setCalendarPopup(true);
    this->Date2QLineEdit=new QDateEdit(this);
    Date2QLineEdit->setCalendarPopup(true);
    this->RegionQLineEdit=new QLineEdit(this);
    this->NameOfCompanyQLineEdit=new QLineEdit(this);
    this->MarksQLineEdit=new QLineEdit(this);

    //    QVBoxLayout *Vlayout1 = new QVBoxLayout;
    //    Vlayout1->addWidget(SityLabel);
    //    Vlayout1->addWidget(SityQLineEdit);

    //    QVBoxLayout *Vlayout2 = new QVBoxLayout;
    //    Vlayout2->addWidget(Date1);
    //    Vlayout2->addWidget(Date1QLineEdit);

    //    QVBoxLayout *Vlayout3 = new QVBoxLayout;
    //    Vlayout2->addWidget(Date2);
    //    Vlayout2->addWidget(Date2QLineEdit);

    //    QVBoxLayout *Vlayout4 = new QVBoxLayout;
    //    Vlayout2->addWidget(Region);
    //    Vlayout2->addWidget(RegionQLineEdit);

    //    QVBoxLayout *Vlayout5 = new QVBoxLayout;
    //    Vlayout2->addWidget(NameOfCompany);
    //    Vlayout2->addWidget(NameOfCompanyQLineEdit);

    //    QVBoxLayout *Vlayout6 = new QVBoxLayout;
    //    Vlayout2->addWidget(Marks);
    //    Vlayout2->addWidget(MarksQLineEdit);

    QGridLayout *GridLayout = new QGridLayout;
    GridLayout->addWidget(SityLabel,0,0,1,1);
    GridLayout->addWidget(SityQLineEdit,1,0,1,1);
    GridLayout->addWidget(Date1,0,1,1,1);
    GridLayout->addWidget(Date1QLineEdit,1,1,1,1);
    GridLayout->addWidget(Date2,0,2,1,1);
    GridLayout->addWidget(Date2QLineEdit,1,2,1,1);
    GridLayout->addWidget(Region,0,3,1,1);
    GridLayout->addWidget(RegionQLineEdit,1,3,1,1);
    GridLayout->addWidget(NameOfCompany,0,4,1,1);
    GridLayout->addWidget(NameOfCompanyQLineEdit,1,4,1,1);
    GridLayout->addWidget(Marks,0,5,1,1);
    GridLayout->addWidget(MarksQLineEdit,1,5,1,1);
    // QDate today2 = this->Date1QLineEdit->date();
    //this->Date2QLineEdit->setDateRange(today2, today.addDays(1));
    //QDate today = QDate::currentDate();
    // this->Date1QLineEdit->setDateRange(today.addDays(-100), today.addDays(100));
    //    QHBoxLayout *Hlayout = new QHBoxLayout;
    //    Hlayout->addLayout(Vlayout1);
    //    Hlayout->addLayout(Vlayout2);
    //    Hlayout->addLayout(Vlayout3);
    //    Hlayout->addLayout(Vlayout4);
    //    Hlayout->addLayout(Vlayout5);
    //    Hlayout->addLayout(Vlayout6);

    //++QHBoxLayout
    //    QHBoxLayout *Hlayout2 = new QHBoxLayout;
    //    Hlayout2->addWidget(this->SityQLineEdit, Qt::AlignHCenter);
    //    Hlayout2->addWidget(this->Date1QLineEdit,Qt::AlignHCenter);
    //    Hlayout2->addWidget(this->Date2QLineEdit,Qt::AlignHCenter);
    //    Hlayout2->addWidget(this->RegionQLineEdit,Qt::AlignHCenter);
    //    Hlayout2->addWidget(this->NameOfCompanyQLineEdit,Qt::AlignHCenter);
    //    Hlayout2->addWidget(this->MarksQLineEdit,Qt::AlignRight);
    //--QHBoxLayout

    QVBoxLayout *Vlayout = new QVBoxLayout;
    Vlayout->addWidget(MainView);
    Vlayout->addLayout(GridLayout);
    //Vlayout->addLayout(Hlayout2);
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    mapper->setModel(this->MainModel);
    //mapper->setItemDelegate(new QSqlRelationalDelegate(this));//http://doc.qt.io/qt-5/qsqlrelationaldelegate.html
    mapper->addMapping(this->SityQLineEdit, MAIN_Sity);
    mapper->addMapping(this->Date1QLineEdit, MAIN_Date1);
    mapper->addMapping(this->Date2QLineEdit, MAIN_Date2);
    mapper->addMapping(this->RegionQLineEdit,MAIN_Region);
    mapper->addMapping(this->NameOfCompanyQLineEdit, MAIN_ComName);
    mapper->addMapping(this->MarksQLineEdit, MAIN_Marks);
    mapper->toFirst();
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    MainView->setItemDelegate(new QSqlRelationalDelegate(this));//!!?
    QList <int> MainList;
    MainList << MAIN_Date1 << MAIN_Date2;
    DateDelegate *DateComboBox1 = new DateDelegate(MainList,this);
    MainView->setItemDelegate(DateComboBox1);
    ComboboxDelegate *ComboboxDel1 = new ComboboxDelegate(SityQLineEdit,TABLE_SITY_NAMETBL,TABLE_SITY_Name, SityModel, this);
    ComboboxDelegate *ComboboxDel2 = new ComboboxDelegate(RegionQLineEdit,TABLE_STATE_NAMETBL,TABLE_STATE_STATE, StateModel, this);
    //    MainView->setItemDelegateForColumn
    //            (1,new ComboboxDelegate(SityQLineEdit,TABLE_SITY_NAMETBL,TABLE_SITY_Name, SityModel, this));
    //    MainView->setItemDelegateForColumn
    //            (4,new ComboboxDelegate(RegionQLineEdit,TABLE_STATE_NAMETBL,TABLE_STATE_STATE, StateModel, this));
    MainView->setItemDelegateForColumn
            (5,new LineEditDelegate(NameOfCompanyQLineEdit,TABLE_Company_NAMETBL,TABLE_Company_NAME_TITLE, CompanyModel, this));

    MainView->setItemDelegateForColumn(1, ComboboxDel1);
    MainView->setItemDelegateForColumn(4, ComboboxDel2);
    MainView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(MainView, SIGNAL(customContextMenuRequested(QPoint)), this,SLOT (slotCustomMenuRequestedMain(QPoint)) );

    //+восстановить
    //    QPalette MainViewPalette = MainView->palette();
    //    MainViewPalette.setColor(QPalette::Text, Qt::red);
    //    MainViewPalette.setColor(QPalette::Highlight, Qt::red) ;
    //    MainViewPalette.setColor(QPalette::WindowText, Qt::red);
    //    MainViewPalette.setColor(QPalette::HighlightedText, Qt::blue) ;
    //    MainViewPalette.setColor(QPalette::BrightText, Qt::green) ;
    //   MainView->setPalette(MainViewPalette);
    //-восстановить
    MainPanel->setLayout(Vlayout);
}
void MainForm::CreateContactsPanel(){
    ContactsPanel = new QWidget(this);
    ContactsView = new QTableView(this);
    ContactsView->setItemDelegate(new QSqlRelationalDelegate(this));
    QList <int> List;
    List << Contacts_DATE;
    ContactsDateDelegate *DateComboBox=new ContactsDateDelegate(List,this);
    //ContactsView->setItemDelegate(DateComboBox);
    ContactsView->setItemDelegateForColumn(Contacts_DATE, DateComboBox);
    QList <int> List2;
    List2 << Contacts_Checkbox;
    //  CheckBoxDelegate *Checkbox=


    CheckBoxDelegate(List2,this);
    // ContactsView->setItemDelegate(Checkbox);
    //ContactsView->setItemDelegateForColumn(6, new CChecBox_Delegate);
    //CChecBox_Delegate
    //http://www.prog.org.ru/topic_10428_0.html


    //   QVariant ContactsModel::data(const QModelIndex &index,int role) const
    //   {
    //           QVariant value = QSqlTableModel::data(index, role);
    //           switch (role)
    //           {
    //           . . .
    //              case Qt::CheckStateRole:
    //                if (index.column() == 3)
    //                   return (QSqlTableModel::data(index).toInt() != 0) ? Qt::Checked : Qt::Unchecked;
    //                           else
    //                             return value;
    //           . . .
    //           }
    //           return value;
    //   }
    //Контестное меню
    //https://evileg.com/ru/post/76/

    ContactsView ->setModel(ContactsModel);
    ContactsView->setSelectionMode(QAbstractItemView::SingleSelection);
    ContactsView->setColumnHidden(Contacts_stasus_Id, true);
    ContactsView->setColumnHidden(Contacts_Name_ofComp, true);
    //ContactsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ContactsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ContactsView->resizeColumnsToContents();
    //ContactsView->verticalHeader()->setVisible(false);
    ContactsView->horizontalHeader()->setVisible(true);
    ContactsView->horizontalHeader()->setStretchLastSection(true);
    //ContactsView->verticalHeader()->setStretchLastSection(true);
    //mainSplitter = new QSplitter(Qt::Horizontal);
    //ontactsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ContactsView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ContactsView, SIGNAL(customContextMenuRequested(QPoint)), this,SLOT (slotCustomMenuRequestedContactV(QPoint)) );
    QVBoxLayout *layout = new QVBoxLayout;
    //    addButtonContactsPanel = new QPushButton(tr("&Добавить"));
    //    deleteButtonContactsPanel = new QPushButton(tr("&Удалить"));
    //    buttonBoxContactsPanel = new QDialogButtonBox;
    //    buttonBoxContactsPanel->addButton(addButtonContactsPanel, QDialogButtonBox::ActionRole);
    //    buttonBoxContactsPanel->addButton(deleteButtonContactsPanel, QDialogButtonBox::ActionRole);
    layout->addWidget(ContactsView);
    // layout->addWidget(buttonBoxContactsPanel);
    // ContactsPanel->setLayout(layout);

    //    for( int i=0; i<ContactsModel->rowCount(); i++ )
    //        {
    //            QWidget *widget = new QWidget();
    //            QCheckBox *chBox = new QCheckBox();
    //
    //            layout->setMargin(0);
    //            layout->setSpacing(0);
    //            layout->addWidget(chBox);
    //            layout->setAlignment( Qt::AlignCenter );
    //            widget->setLayout( layout );
    //             //ContactsView->setIndexWidget(ContactsModel->index(i, 6), widget );
    //ContactsView->setIndexWidget(ContactsModel->index(i, 6),widget);
    //            if( ContactsModel->data( ContactsModel->index(i, 6) ).toBool() )
    //                chBox->setChecked( true );
    //            else
    //                chBox->setChecked( false );

    //            //connect( chBox, SIGNAL(clicked(bool)), this, SLOT(onCheckBoxChecked(bool)) );

    //Button++
    //    addButtonContactsPanel = new QPushButton(tr("&Add "));
    //    deleteButtonContactsPanel = new QPushButton(tr("&Delete"));
    //    buttonBoxContactsPanel = new QDialogButtonBox;
    //    buttonBoxContactsPanel->addButton(addButtonContactsPanel, QDialogButtonBox::ActionRole);
    //    buttonBoxContactsPanel->addButton(deleteButtonContactsPanel, QDialogButtonBox::ActionRole);
    //    // QHBoxLayout *layout = new QHBoxLayout;
    //    layout->addWidget(buttonBoxContactsPanel);
    //Button--
    ContactsPanel->setLayout( layout );

    // ContactsView->setIndexWidget(ContactsModel());


}

//bool MainForm::chekDataSQL( const QString &tableName, int column)//? need
//{
//    Q_UNUSED(tableName)
//    //QString  str;
//    //str="Дзержинск2";
//    QSqlQuery query;
//    //qDebug()<< SityQLineEdit->text();
//    //qDebug()<< MainModel->data(MainModel->index(mapper->currentIndex(),column), Qt::DisplayRole).toString();
//    QString str = QString("SELECT EXISTS (SELECT id FROM " TABLE_SITY_NAMETBL " WHERE (  NAME = '%1' )  AND id NOT LIKE '%2' )")
//            .arg(SityQLineEdit->text(),
//                 MainModel->data(MainModel->index(mapper->currentIndex(),column), Qt::DisplayRole).toString());
//    // " WHERE (  NAME = '%1' )  AND id NOT LIKE '%2' )")

//    //qDebug()<< str;
//    query.prepare(str);
//    query.exec();
//    query.next();
//    if(query.value(0) != 0){
//        qDebug()<< "query.value(0) != 0 - TRUE";
//        //        QMessageBox::information(this, trUtf8("Ошибка хоста"),
//        //                                 trUtf8("Хост с таким именем или IP-адресом уже существует"));
//        /* В противном случае производится вставка новых данных в таблицу
//             * и диалог завершается с передачей сигнала для обновления
//        // mapper->submit();
//        // model->submitAll();
//             * таблицы в главном окне
//             * */
//    } else {
//        qDebug()<<"query.value(0) != 0 - FALSE";
//        // emit signalReady();
//        // this->close();
//    }
//    return false;
//}

void MainForm::CreateVisitsPanel()
{
    VisitsPanel = new QWidget(this);
    VisitsView = new QTableView(this);
    VisitsView->setItemDelegate(new QSqlRelationalDelegate(this));
    QList <int> List2;
    List2 << Visits_Date1 << Visits_Date2;
    VisitsDateDelegate *DateComboBox2=new VisitsDateDelegate(List2,this);
    VisitsView->setItemDelegate(DateComboBox2);
    VisitsView ->setModel(VisitsModel);
    //https://forum.qt.io/topic/5172/qtreewidget-indicator-area-background-color

    VisitsView->setSelectionMode(
                QAbstractItemView::SingleSelection);
    VisitsView->setColumnHidden(Visits_stasus_Id, true);
    VisitsView->setColumnHidden(Visits_Name_ofComp, true);
    VisitsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    VisitsView->resizeColumnsToContents();
    VisitsView->resizeRowsToContents();
    VisitsView->horizontalHeader()->setStretchLastSection(true);
    //VisitsView->verticalHeader()->setVisible(false);
    //VisitsView->verticalHeader()->setStretchLastSection(true);
    VisitsView->horizontalHeader()->setVisible(true);
    VisitsView->setBackgroundRole(QPalette::Background);
    VisitsView->setAttribute(Qt::WA_MacShowFocusRect, false);

    VisitsView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(VisitsView, SIGNAL(customContextMenuRequested(QPoint)), this,SLOT (slotCustomMenuRequested(QPoint)) );
    //  VisitsPanel->setStyleSheet("QWidget"
    //  "{ border: 0px; padding-bottom: -10px; margin-bottom: 0px;} ");
    QVBoxLayout *layout = new QVBoxLayout(this);
    createToolBar();
    layout->addWidget(Visits_ContactToolBar);
    //OpenSetting
    layout->addWidget(VisitsView);
    //Button++
    //buttonBoxVisitsPanel = new QDialogButtonBox;
    // addButtonVisitsPanel = new QPushButton(tr("&Add "));
    // deleteButtonVisitsPanel = new QPushButton(tr("&Delete"));
    // editButton = new QPushButton(tr("&Edit"));
    // buttonBoxVisitsPanel->addButton(addButtonVisitsPanel, QDialogButtonBox::ActionRole);
    //buttonBoxVisitsPanel->addButton(deleteButtonVisitsPanel, QDialogButtonBox::ActionRole);
    // buttonBoxVisitsPanel->addButton(editButton, QDialogButtonBox::ActionRole);
    // layout->addWidget(buttonBoxVisitsPanel);
    //Button--
    //Visits_ContactToolBar->addActions((":/sourse/buttons/new_folder.png"), "1", this, SLOT(Debug()));
    VisitsPanel->setLayout(layout);
}

void MainForm::updateVisitsPanel()
{
    QModelIndex index = MainView->currentIndex();
    if (index.isValid()) {
        QSqlRecord record = MainModel->record(index.row());
        int id = record.value("id").toInt();
        VisitsModel->setFilter(QString( TABLE_VISITS_TOCOMPANY " = %1").arg(id));
    } else {
        VisitsModel->setFilter(TABLE_VISITS_TOCOMPANY" = -1");
    }
    VisitsModel->select();
    VisitsView->horizontalHeader()->setVisible(
                VisitsModel->rowCount() > 0);
}

void MainForm::updateContactsPanel()
{
    QModelIndex index = MainView->currentIndex();
    if (index.isValid()) {
        QSqlRecord record = MainModel->record(index.row());
        int id = record.value("id").toInt();
        ContactsModel->setFilter(QString( TABLE_CONTACS_NUMBER_COMP " = %1").arg(id));
    } else {
        ContactsModel->setFilter(TABLE_CONTACS_NUMBER_COMP" = -1");
    }
    ContactsModel->select();
    ContactsView->horizontalHeader()->setVisible(
                ContactsModel->rowCount() > 0);
}

void MainForm::Debug()
{
    qDebug()<<"start Debug";
    saveGeometry();
    qDebug()<<"MainPanel->width()"<<MainPanel->width();
    qDebug()<<"MainView->width()"<<MainView->width();
    qDebug()<<"leftSplitter->width()"<<leftSplitter->width();
    qDebug()<<"rightSplitter->width()"<<rightSplitter->width();
    qDebug()<<"mainSplitter->width()"<<mainSplitter->width();
    //QPaintEvent *p2;
    //paintEvent(p2);
    // VisitsModel->select();
    //    QModelIndex rv = VisitsView->selectionModel()->currentIndex();
    //    emit dataChanged(rv, rv);
}

void MainForm::addRowVisitsPanel()
{
    //qDebug()<<"addRowVisitsPanel";
    QSqlQuery query;
    int row;
    QModelIndex index = VisitsModel->index(0,0, QModelIndex());
    int id;
    QModelIndex indexMainView;
    QSqlRecord record;
    QString date;
    QString str;
    if (index.isValid())
    {
        indexMainView = MainView->currentIndex();
        row=indexMainView.row();
        record = MainModel->record(indexMainView.row());
        id = record.value("id").toInt();
        //        if (id )   SelectedID=id;
        //        else SelectedID=1;

        index = VisitsModel->index(VisitsModel->rowCount()-1,Visits_Date2, QModelIndex());
        date = VisitsModel->data(index,Qt::DisplayRole).toDate().toString("yyyy-MM-dd");
        //       query.exec("INSERT INTO " TABLE_VISITS_NAMETBL
        //                  "(" TABLE_VISITS_TOCOMPANY "," TABLE_VISITS_FIRSTDATE ") VALUES ("  + QString::number(id) + ",'"   + date + "')");
        //       str = QString("UPDATE "  TABLE_MAIN_NAMETBL" SET " TABLE_MAIN_STARTDATE  " = '%1'  WHERE id = '%2'")
        //               .arg(date).arg(id);

    }
    else {
        indexMainView = MainView->currentIndex();
        row=indexMainView.row();
        record = MainModel->record(indexMainView.row());
        id = record.value("id").toInt();
        date= QDate::currentDate().toString("yyyy-MM-dd");
        //    str = QString("UPDATE "  TABLE_MAIN_NAMETBL" SET " TABLE_MAIN_STARTDATE  " = '%1'  WHERE id = '%2'")
        //            .arg(date).arg(id);

    }
    if (indexMainView.isValid()) {
        query.exec("INSERT INTO " TABLE_VISITS_NAMETBL
                   "(" TABLE_VISITS_TOCOMPANY "," TABLE_VISITS_FIRSTDATE ") VALUES ("  + QString::number(id) + ",'"   + date + "')");
        str = QString("UPDATE "  TABLE_MAIN_NAMETBL" SET " TABLE_MAIN_STARTDATE  " = '%1'  WHERE id = '%2'")
                .arg(date).arg(id);
        query.prepare(str);
        query.exec();
        VisitsModel->select();
        MainModel->select();
    }
    MainView->selectRow(row);


    QItemSelectionModel *selectionModel = VisitsView->selectionModel();
    QModelIndex topLeft;
    QModelIndex bottomRight;

    topLeft = VisitsModel->index(0, 0, QModelIndex());
    bottomRight = VisitsModel->index(0, 0, QModelIndex());
    QItemSelection selection(topLeft, bottomRight);
    selectionModel->select(selection, QItemSelectionModel::Select);
}

void MainForm::addNewRowContactsPanel()
{
    //Debug();

    QSqlQuery query;
    QModelIndex index = MainView->selectionModel()->currentIndex();
    //int row=index.row();
    // MainView->selectionModel()->currentIndex()
    QSqlRecord record = MainModel->record(index.row());
    int id = record.value("id").toInt();
    //qDebug()<<id;
    query.exec("INSERT INTO " TABLE_CONTACS_NAMETBL  "(" TABLE_CONTACS_NUMBER_COMP "," TABLE_CONTACS_ROLE ") VALUES ("  + QString::number(id) + ",'Нет')");
    ContactsModel->select();

    QItemSelectionModel *selectionModel = ContactsView->selectionModel();
    selectionModel->clearSelection();
    QModelIndex topLeft;
    QModelIndex bottomRight;

    topLeft = ContactsModel->index(ContactsModel->rowCount()-1, Contacts_Name_ofComp, QModelIndex());
    bottomRight = ContactsModel->index(ContactsModel->rowCount()-1,  Contacts_DATE, QModelIndex());
    QItemSelection selection(topLeft, bottomRight);
    selectionModel->select(selection, QItemSelectionModel::Select);
}

void MainForm::loadStyleCoffee()
{
    loadStyleSheet("coffee");
    SetupSetting2();
    //доделать
    //  QHeaderView* header = MainView->verticalHeader();
    //    header->setSectionResizeMode(QHeaderView::Stretch);
    //   QHeaderView* header2 = MainView->horizontalHeader();
    //   header2->setSectionResizeMode(QHeaderView::Stretch); //http://doc.qt.io/qt-5/qheaderview.html#sectionSize
}
void MainForm::loadStylePagefold()
{
    loadStyleSheet("pagefold");
    SetupSetting2();



}
void MainForm::loadStyleDefault()
{
    loadStyleSheet("default");
    SetupSetting2();
    //ContactsView->horizontalHeader()->repaint();
    // MainView->horizontalHeader()->repaint();
    //ContactsView->horizontalHeader()->setStretchLastSection(true);
    //MainView->horizontalHeader()->setStretchLastSection(true);




}

void MainForm::loadStyleStyleHelper()
{
    CreateStyleHelper();
}

void MainForm::slotCustomMenuRequestedContactV(QPoint pos)
{
    QTableView* View = (QTableView*)sender();
    QModelIndex index = ContactsView->selectionModel()->currentIndex();
    QMenu * menu = new QMenu(this);
    QAction * addDevice = new QAction(trUtf8("Добавить"), this);
    QAction * deleteDevice = new QAction(trUtf8("Удалить"), this);
    //qDebug() <<"index.column() = "<<index.column();
    if (index.column()==Contacts_Mail)
    {
        QAction * hrefDevice = new QAction(trUtf8("Отправить почту"), this);
        menu->addAction(hrefDevice);
        connect(hrefDevice, SIGNAL(triggered()), this, SLOT(goToMailContactsView()));
    }
    //    else if (index.column()==Contacts_Something)
    //    {
    //        QAction * hrefDevice = new QAction(trUtf8("Перейти на сайт"), this);
    //        menu->addAction(hrefDevice);
    //        connect(hrefDevice, SIGNAL(triggered()), this, SLOT(goToHrefMainView()));
    //    }
    menu->addAction(addDevice);
    menu->addAction(deleteDevice);
    menu->popup(View->viewport()->mapToGlobal(pos));
    connect(addDevice, SIGNAL(triggered()), this, SLOT(AddToolContVisitsBarSlot()));
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(DeleteContVisitsToolBarSlot()));
}

void MainForm::slotCustomMenuRequested(QPoint pos)
{
    QTableView* View = (QTableView*)sender();
    QModelIndex index = ContactsView->selectionModel()->currentIndex();
    QMenu * menu = new QMenu(this);
    if (View==MainView && index.column()==MAIN_HrefSite)
    {
        QAction * hrefDevice = new QAction(trUtf8("Перейти на сайт"), this);
        menu->addAction(hrefDevice);
        connect(hrefDevice, SIGNAL(triggered()), this, SLOT(goToHrefMainView()));
    }
    QAction * addDevice = new QAction(trUtf8("Добавить"), this);
    QAction * deleteDevice = new QAction(trUtf8("Удалить"), this);
    menu->addAction(addDevice);
    menu->addAction(deleteDevice);
    menu->popup(View->viewport()->mapToGlobal(pos));
    connect(addDevice, SIGNAL(triggered()), this, SLOT(AddToolContVisitsBarSlot()));
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(DeleteContVisitsToolBarSlot()));
}


void MainForm::slotCustomMenuRequestedMain(QPoint pos)
{
    QTableView* View = (QTableView*)sender();
    QModelIndex index = MainView->selectionModel()->currentIndex();
    QMenu * menu = new QMenu(this);
    //qDebug()<<"index.column()= " <<index.column();
    //qDebug()<<"MAIN_HrefSite = " <<MAIN_HrefSite;
    if (index.column()==MAIN_HrefSite)
    {
        QAction * hrefDevice = new QAction(trUtf8("Перейти на сайт"), this);
        menu->addAction(hrefDevice);
        connect(hrefDevice, SIGNAL(triggered()), this, SLOT(goToHrefMainView()));
    }
    QAction * addDevice = new QAction(trUtf8("Добавить"), this);
    QAction * deleteDevice = new QAction(trUtf8("Удалить"), this);
    menu->addAction(addDevice);
    menu->addAction(deleteDevice);
    menu->popup(View->viewport()->mapToGlobal(pos));
    connect(addDevice, SIGNAL(triggered()), this, SLOT(AddToolContVisitsBarSlot()));
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(DeleteContVisitsToolBarSlot()));
}


void MainForm::goToHrefMainView()
{
    QModelIndex index = MainView->selectionModel()->currentIndex();
    QString Url = index.model()->data(index,Qt::DisplayRole).toString();
    QDesktopServices::openUrl(QUrl(Url, QUrl::TolerantMode));
}
//http://www.prog.org.ru/topic_7216_0.html
void MainForm::goToMailContactsView()
{
    QModelIndex index = ContactsView->selectionModel()->currentIndex();
    QString Url = "mailto:" + index.model()->data(index,Qt::DisplayRole).toString() + "?subject=ООО Энергопром&body=Добрый день!";
    //qDebug()<<Url;
    QDesktopServices::openUrl(QUrl(Url, QUrl::TolerantMode));
    //mailto:user@foo.com?subject=Test&body=Just a test

}

void MainForm::DeleteRowContactsPanel()
{
    QModelIndex index = ContactsView->selectionModel()->currentIndex();
    QSqlRecord record = ContactsModel->record(index.row());
    //qDebug()<<"currentIndex.row = "<<index.row();
    int id = record.value("id").toInt();
    //qDebug()<<"id = "<<id;
    QSqlQuery query;
    //if (selectionModel->currentIndex().row()!=0){
    //int Row=index.row();

    //qDebug()<<("DELETE FROM " TABLE_CONTACS_NAMETBL " WHERE id = '" + QString::number(id) +"'");
    query.exec("DELETE FROM " TABLE_CONTACS_NAMETBL " WHERE id = '" + QString::number(id) +"'");
    ContactsModel->select();

    //    QModelIndex topLeft;
    //    QModelIndex bottomRight;
    //    QItemSelectionModel *selectionModel = ContactsView->selectionModel();
    //   selectionModel->clearSelection();
    //    topLeft = ContactsModel->index(2, 2, QModelIndex());//Contacts_Name_ofComp
    //    bottomRight = ContactsModel->index(2,  2, QModelIndex());//Contacts_DATE
    //    QItemSelection selection(topLeft, bottomRight);
    //    selectionModel->select(selection, QItemSelectionModel::Select);

    //ContactsView->repaint();
    //}
    // else qDebug()<<"selectionModel->currentIndex().row()==0";

}

void MainForm::DeleteRowMainPanel()
{

    QSqlQuery query;
    QModelIndex index = MainView->selectionModel()->currentIndex();
    QSqlRecord record = MainModel->record(index.row());
    int id = record.value(MAIN_stasus_Id).toInt();
    QString Company_name = record.value(MAIN_ComName).toString();

    int r = QMessageBox::warning(this, tr("Запрос на удаление компании"),
                                 tr("Удалить компанию < %1 > ?")
                                 .arg(Company_name),
                                 QMessageBox::Yes | QMessageBox::No);
    if (r == QMessageBox::Yes) {


        //qDebug()<<"id = "<<id;
        //qDebug()<<"Company_name = "<<Company_name;
        query.exec("DELETE FROM " TABLE_CONTACS_NAMETBL " WHERE NumCompany  = '" + QString::number(id) +"'");
        query.exec("DELETE FROM " TABLE_VISITS_NAMETBL " WHERE CompNumber = '" + QString::number(id) +"'");
        if (Company_name!="Не указано")
        {
            query.exec("DELETE FROM " TABLE_Company_NAMETBL  " WHERE Title = '" + Company_name +"'");
        }
        query.exec("DELETE FROM " TABLE_MAIN_NAMETBL  " WHERE id = '" + QString::number(id) +"'");
        MainModel->select();
        ContactsModel->select();
        VisitsModel->select();
    }
}

void MainForm::saveGeometrySlot()
{
    //qDebug()<<"saveGeometrySlot";
    this->saveGeometry();
}

void MainForm::SetupSetting2slot()
{
    SetupSetting2();
}
//http://qaru.site/questions/735085/how-do-i-resize-qtableview-so-that-the-area-is-not-scrolled-anymore
void MainForm::test()
{
    qDebug()<<"test";
    //ContactsPanel->setStyleSheet(StyleHelper::getContactsPanelStyleSheet());
    //    QModelIndex index = ContactsView->selectionModel()->currentIndex();
    //    QSqlRecord record = ContactsModel->record(index.row());
    //    qDebug()<<"currentIndex.row = "<<index.row();
    //    int id = record.value("id").toInt();
    //    qDebug()<<"id = "<<id;
    //SetupSetting();
    CreateStyleHelper();


    //    QItemSelectionModel *selectionModel = VisitsView->selectionModel();
    //    QModelIndex topLeft;
    //    QModelIndex bottomRight;
    //selectionModel->clearSelection();
    //    topLeft = VisitsModel->index(0, 1, QModelIndex());

    //    bottomRight = VisitsModel->index(1, 1, QModelIndex());
    //    QItemSelection selection(topLeft, bottomRight);

    //    selectionModel->select(selection, QItemSelectionModel::Select);



    //    QItemSelectionModel *selectionModel2 = MainView->selectionModel();
    //    selectionModel2->clearSelection();
    //    QModelIndex topLeft2;
    //    QModelIndex bottomRight2;

    //    topLeft2 = MainModel->index(1, 1, QModelIndex());
    //    bottomRight2 = MainModel->index(1, MainModel->columnCount()-1, QModelIndex());
    //    QItemSelection selection2(topLeft2, bottomRight2);
    //    selectionModel2->select(selection2, QItemSelectionModel::Select);
}

QMap<QString, double> MainForm::OpenSetting(QString filename)
{

    //QStringList NamesParam;
    QMultiMap <QString, double> Param;
    //переменные MainVeiw
    int MainViewWidth;
    int ContactsViewWidth;
    int VisitsViewWidth;
    double value;
    QFile file (filename);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString str;

        while (!stream.atEnd())
        {
            str = stream.readLine().simplified();
            //   bool yt=str.contains("//",Qt::CaseInsensitive);
            if (str.isEmpty() || str.contains("//",Qt::CaseInsensitive)){}
            else {
                QStringList list=str.split('-');
                int i=0;
                QString str1=list[i].simplified();
                QString str2=list[i+1].simplified();

                if (str1.contains("MainViewWidth",Qt::CaseInsensitive)){
                    MainViewWidth=str2.toInt();
                    value=str2.toDouble();
                }
                else if (str1.contains("MainViewColumn_",Qt::CaseInsensitive))
                {
                    value=str2.toDouble()/MainViewWidth;
                }
                else if (str1.contains("ContactsViewWidth",Qt::CaseInsensitive))
                {
                    ContactsViewWidth=str2.toInt();
                    value=str2.toDouble();
                }
                else if (str1.contains("ContactsViewColumn_",Qt::CaseInsensitive))
                {
                    value=str2.toDouble()/ContactsViewWidth;
                }
                else if (str1.contains("VisitsViewWidth",Qt::CaseInsensitive))
                {
                    VisitsViewWidth=str2.toInt();
                    value=str2.toDouble();
                }
                else if (str1.contains("VisitsViewColumn_",Qt::CaseInsensitive))
                {
                    value=str2.toDouble()/VisitsViewWidth;
                }
                else  value=str2.toDouble();
                Param.insert(str1,value);
                //qDebug() << list[i];
                // qDebug() << "QMap.key" <<str1<<"QMap.value" <<value;
            }
            if(stream.status()!= QTextStream::Ok)
            {
                //qDebug() << "No file";
            }
            file.close();
        }
    }
    //file.close();
    else {
        //дописать вставку файла с нулевыми значениями
        //file.close();
    }
    return Param;
    file.close();
}

void MainForm::loadStyleSheet(const QString &sheetName)
{
    QFile file(":/sourse/stylesheet/qss/" + sheetName.toLower() + ".qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());
    qApp->setStyleSheet(styleSheet);
    file.close();
}

void MainForm::SetupSetting()//At start not all
{
    // qDebug()<<"SetupSetting()";
    QObject::disconnect(MainView->horizontalHeader(),
                        SIGNAL(sectionResized(int,int,int)),
                        this, SLOT(saveGeometrySlot()));
    QObject::disconnect(ContactsView->horizontalHeader(),
                        SIGNAL(sectionResized(int,int,int)),
                        this, SLOT(saveGeometrySlot()));
    QObject::disconnect(VisitsView->horizontalHeader(),
                        SIGNAL(sectionResized(int,int,int)),
                        this, SLOT(saveGeometrySlot()));
    QString path = QDir::currentPath();
    QString FolderPath = "/sourse/";
    QString FilePath = "Setting.txt";
    int i;
    QMultiMap <QString, double> ::iterator it1;
    QMultiMap <QString, double> ::iterator it2;
    QMap <QString, double> SettingMap = OpenSetting(path +FolderPath + FilePath);
    it1 = SettingMap.find("MainFormWidth");
    it2= SettingMap.find("MainFormheight");
    int MainViewWidth=SettingMap.find("MainViewWidth").value();
    int ContactsViewWidth=SettingMap.find("ContactsViewWidth").value();
    int VisitsViewWidth=SettingMap.find("VisitsViewWidth").value();

    // MainView->resize(MainPanel->width(), MainView->height());
    //MainViewWidth=MainView->width();
    for (i=1;i<6;i++){
        it1 = SettingMap.find("MainViewColumn_"+ QString::number(i) + "_Width");
        MainView->setColumnWidth(i,it1.value() * MainViewWidth * 1.02);
    }
    for (i=2;i<8;i++){
        it1 = SettingMap.find("ContactsViewColumn_"+ QString::number(i) + "_Width");
        ContactsView->setColumnWidth(i,it1.value() * ContactsViewWidth * 1.02);

    }
    for (i=2;i<6;i++){
        it1 = SettingMap.find("VisitsViewColumn_"+ QString::number(i) + "_Width");
        VisitsView->setColumnWidth(i, it1.value() * VisitsViewWidth * 1.02);
    }
    connect(MainView->horizontalHeader(),
            SIGNAL(sectionResized(int,int,int)),
            this, SLOT(saveGeometrySlot()));

    connect(ContactsView->horizontalHeader(),
            SIGNAL(sectionResized(int,int,int)),
            this, SLOT(saveGeometrySlot()));

    connect(VisitsView->horizontalHeader(),
            SIGNAL(sectionResized(int,int,int)),
            this, SLOT(saveGeometrySlot()));
}

void MainForm::LoadSetting()
{
    //qDebug()<<"LoadSetting()";
    QObject::disconnect(MainView->horizontalHeader(),
                        SIGNAL(sectionResized(int,int,int)),
                        this, SLOT(saveGeometrySlot()));
    QObject::disconnect(ContactsView->horizontalHeader(),
                        SIGNAL(sectionResized(int,int,int)),
                        this, SLOT(saveGeometrySlot()));
    QObject::disconnect(VisitsView->horizontalHeader(),
                        SIGNAL(sectionResized(int,int,int)),
                        this, SLOT(saveGeometrySlot()));

    QString path = QDir::currentPath();
    QString FolderPath = "/sourse/";
    QString FilePath = "Setting.txt";
    QMultiMap <QString, double> ::iterator it1;
    QMultiMap <QString, double> ::iterator it2;
    QMultiMap <QString, double> ::iterator it3;
    QMultiMap <QString, double> ::iterator it4;
    QMap <QString, double> SettingMap = OpenSetting(path +FolderPath + FilePath);
    it1 = SettingMap.find("MainFormWidth");
    it2= SettingMap.find("MainFormheight");
    it3= SettingMap.find("leftSplitter_Width");
    it4= SettingMap.find("rightSplitter_Width");


    this->resize(it1.value(), it2.value());
    //this->SetupSetting();
    int i;
    int MainViewWidth = SettingMap.find("MainViewWidth").value();
    int ContactsViewWidth=SettingMap.find("ContactsViewWidth").value();
    int VisitsViewWidth=SettingMap.find("VisitsViewWidth").value();

    //qDebug()<<"MainView->width() = "<<MainView->width();
    //qDebug()<<"MainViewWidth = "<< MainViewWidth;

    for (i=1;i<6;i++){
        it1 = SettingMap.find("MainViewColumn_"+ QString::number(i)+ "_Width");
        MainView->setColumnWidth(i,it1.value() * MainViewWidth);
        // qDebug()<<"it1.value * MainViewWidth = " << it1.value() * MainViewWidth;
    }
    for (i=2;i<8;i++){
        it1 = SettingMap.find("ContactsViewColumn_"+ QString::number(i)+ "_Width");
        ContactsView->setColumnWidth(i,it1.value() * ContactsViewWidth);

    }
    for (i=2;i<6;i++){
        it1 = SettingMap.find("VisitsViewColumn_"+ QString::number(i)+ "_Width");
        VisitsView->setColumnWidth(i, it1.value() * VisitsViewWidth);
    }
    leftSplitter->resize(it3.value(),leftSplitter->height());
    rightSplitter->resize(it4.value(),rightSplitter->height());
    connect(MainView->horizontalHeader(),
            SIGNAL(sectionResized(int,int,int)),
            this, SLOT(saveGeometrySlot()));

    connect(ContactsView->horizontalHeader(),
            SIGNAL(sectionResized(int,int,int)),
            this, SLOT(saveGeometrySlot()));

    connect(VisitsView->horizontalHeader(),
            SIGNAL(sectionResized(int,int,int)),
            this, SLOT(saveGeometrySlot()));
}

void MainForm::SetupSetting2()
{
    int i;
    //qDebug()<<"SetupSetting2";
    // MainView->resize(MainPanel->width(), MainView->height());

    if (QApplication::focusWidget()==ContactsView)
    {
        for (i=2;i<3;i++){
            ContactsView->resizeColumnToContents(7);
            for (i=2;i<8;i++){
                ContactsView->resizeColumnToContents(i);
            }
        }
    }//
    else if (QApplication::focusWidget()==VisitsView)
    {
        VisitsView->resizeColumnToContents(6);

        for (i=5;i<6;i++){
            VisitsView->resizeColumnToContents(i);
        }
        VisitsView->resizeRowsToContents();
    }
    else if (QApplication::focusWidget()==MainView)
    {
        MainView->setColumnWidth(6,50);
        for (i=0;i<6;i++){
            MainView->resizeColumnToContents(i);
        }
    }
}
void MainForm::saveGeometry()//to file
{
    //qDebug()<<"saveGeometry()";
    //QMultiMap <QString, double> Param;
    QString path = QDir::currentPath();
    QString FolderPath = "/sourse/";
    QString FilePath = "Setting.txt";
    //qDebug()<<path;
    QDir dir;
    QFile file (path +FolderPath + FilePath);
    //qDebug()<<file.fileName();
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate |  QIODevice::ReadWrite)) {
        //file.open(QIODevice::Truncate);
        file.close();
    }
    else if (!dir.exists(path + FolderPath))
    {
        //qDebug()<<"dir.exists";
        dir.mkpath(path + FolderPath);
        //qDebug()<<" directory "<< path +"/sourse/" <<" now exists";
        if ( file.open(QIODevice::ReadWrite) )
        {
            //qDebug()<<"file now exists";
        }
    }
    //else qDebug()<<"dir  "<< path <<" exists";
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    int MainViewWidth=this->width();
    int MainViewHeight=this->height();

    out<< "//MainFormWidth "<< "\r\n";
    out<< "MainFormWidth - " << MainViewWidth << "\r\n";
    out<< "MainFormheight - " << MainViewHeight << "\r\n";
    out<< ""<< "\r\n";

    out<< "//MainView "<< "\r\n";
    out<< "MainViewWidth - " << MainView->width()<< "\r\n";
    out<< "MainViewColumn_1_Width - " << MainView->columnWidth(1)<< "\r\n";
    out<< "MainViewColumn_2_Width - " << MainView->columnWidth(2)<< "\r\n";
    out<< "MainViewColumn_3_Width - " << MainView->columnWidth(3)<< "\r\n";
    out<< "MainViewColumn_4_Width - " << MainView->columnWidth(4)<< "\r\n";
    out<< "MainViewColumn_5_Width - " << MainView->columnWidth(5)<< "\r\n";
    out<< "MainViewColumn_6_Width - " << MainView->columnWidth(6)<< "\r\n";

    out<< ""<< "\r\n";
    out<< "//ContactsView "<< "\r\n";
    out<< "ContactsViewWidth - " << ContactsView->width()<< "\r\n";
    out<< "ContactsViewColumn_2_Width - " << ContactsView->columnWidth(2)<< "\r\n";
    out<< "ContactsViewColumn_3_Width - " << ContactsView->columnWidth(3)<< "\r\n";
    out<< "ContactsViewColumn_4_Width - " << ContactsView->columnWidth(4)<< "\r\n";
    out<< "ContactsViewColumn_5_Width - " << ContactsView->columnWidth(5)<< "\r\n";
    out<< "ContactsViewColumn_6_Width - " << ContactsView->columnWidth(6)<< "\r\n";
    out<< "ContactsViewColumn_7_Width - " << ContactsView->columnWidth(7)<< "\r\n";
    out<< "ContactsViewColumn_8_Width - " << ContactsView->columnWidth(8)<< "\r\n";

    out<< ""<< "\r\n";
    out<< "//VisitsView "<< "\r\n";
    out<< "VisitsViewWidth - " << VisitsView->width()<< "\r\n";
    out<< "VisitsViewColumn_2_Width - " << VisitsView->columnWidth(2)<< "\r\n";
    out<< "VisitsViewColumn_3_Width - " << VisitsView->columnWidth(3)<< "\r\n";
    out<< "VisitsViewColumn_4_Width - " << VisitsView->columnWidth(4)<< "\r\n";
    out<< "VisitsViewColumn_5_Width - " << VisitsView->columnWidth(5)<< "\r\n";
    out<< "VisitsViewColumn_6_Width - " << VisitsView->columnWidth(6)<< "\r\n";

    out<< ""<< "\r\n";
    out<< "//leftSplitter "<< "\r\n";
    out<< "leftSplitter_Width - " << leftSplitter->width()<< "\r\n";

    out<< ""<< "\r\n";
    out<< "//rightSplitter "<< "\r\n";
    out<< "rightSplitter_Width - " << rightSplitter->width()<< "\r\n";
    file.close();
}

void MainForm::DeleteRowVisitsPanel()
{
    QModelIndex index = VisitsView->selectionModel()->currentIndex();
    QSqlRecord record = VisitsModel->record(index.row());
    int id = record.value("id").toInt();
    QSqlQuery query;
    // qDebug()<<("DELETE FROM " TABLE_VISITS_NAMETBL " WHERE " TABLE_VISITS_TOCOMPANY  " = '" + QString::number(id) +"'");
    query.exec("DELETE FROM " TABLE_VISITS_NAMETBL " WHERE id "  " = '" + QString::number(id) +"'");
    VisitsModel->select();
    // QItemSelection selection(ContactsModel->index(ContactsModel->rowCount(),1), ContactsModel->index(ContactsModel->rowCount(),2));
    // ContactsView->selectionModel()->select(selection,QItemSelectionModel::Select);

}

void MainForm::ChengeDatafromVisitsPanel(int i,QSqlRecord&rd)
{
    Q_UNUSED(i)
    int RowManModel=(MainView->selectionModel()->currentIndex()).row();
    QString date1=rd.value(TABLE_VISITS_FIRSTDATE).toDate().toString(FORMAT_DATE);
    QString date2=rd.value(TABLE_VISITS_LASTDATE).toDate().toString(FORMAT_DATE);
    QModelIndex MainModelindex1 = MainModel->index(RowManModel,MAIN_Date1,QModelIndex());
    QModelIndex MainModelindex2 = MainModel->index(RowManModel,MAIN_Date2,QModelIndex());
    MainModel->setData(MainModelindex1,date1,Qt::EditRole);
    MainModel->setData(MainModelindex2,date2,Qt::EditRole);
}

void MainForm::ChengeDataToVisitsPanel(QModelIndex index1,QModelIndex index2 ,QVector<int> vect)
{
    Q_UNUSED(index2)
    Q_UNUSED(vect)
    //int RowManModel=index1.row();
    QSqlRecord record = MainModel->record(index1.row());
    QString date;
    QModelIndex index;

    //addRowVisitsPanel()

    switch (index1.column()) {
    case MAIN_Date1:
    {
        date=record.value(TABLE_MAIN_STARTDATE).toDate().toString(FORMAT_DATE);
        index = VisitsModel->index(VisitsModel->rowCount()-1,Visits_Date1, QModelIndex());
        // qDebug()<<VisitsModel->data(index,Qt::DisplayRole);
        if (VisitsModel->data(index,Qt::DisplayRole)!=date && VisitsModel->data(index,Qt::DisplayRole)!="") addRowVisitsPanel();
        index = VisitsModel->index(VisitsModel->rowCount()-1,Visits_Date1, QModelIndex());
        VisitsModel->setData(index,date,Qt::EditRole);
    }
        break;
    case MAIN_Date2:
        date=record.value(TABLE_MAIN_ENDDATE ).toDate().toString(FORMAT_DATE);
        index = VisitsModel->index(VisitsModel->rowCount()-1,Visits_Date2, QModelIndex());
        //qDebug()<<index1.column();
        break;
    default:
        break;
    }
    VisitsModel->setData(index,date,Qt::EditRole);
}

void MainForm::BugTracker()
{

    MainView->resizeColumnToContents(6);
    //saveGeometry();
    //   double fl;
    //    qDebug()<<"MainPanel->width() = "<<MainPanel->width();
    //    qDebug()<<"MainView->width() = "<<MainView->width();
    //    qDebug()<<"leftSplitter->width() = "<< leftSplitter->width();
    //    qDebug()<<"QMainView->columnWidth(1) = "<<MainView->columnWidth(1);
    //    fl=MainView->columnWidth(1)+MainView->columnWidth(2)+MainView->columnWidth(3)+MainView->columnWidth(4)+MainView->columnWidth(5)+MainView->columnWidth(6);
    //    qDebug()<<"QMainView->columnWidth(5) = "<<MainView->columnWidth(5);
    //    qDebug()<<"QMainView->columnWidth(6) = "<<MainView->columnWidth(6);
    //    qDebug()<<"QMainView->columnWidth(+) = "<<(fl);

    //MainView->repaint();
    //leftSplitter->width()
}

void MainForm::BugTracker2()
{

}

void MainForm::updateMapper(const QModelIndex &index,
                            const QModelIndex &)
{
    Q_UNUSED(index)

    //qDebug()<< index.model()->index(index.row(),5,QModelIndex()).data(Qt::DisplayRole);
    //index.data(Qt::DisplayRole);
    mapper->setCurrentModelIndex(MainView->selectionModel()->currentIndex());
    // NameOfCompanyQLineEdit->setText();
    mapper->submit();

}

void MainForm::updateCompanyModel()
{
    QString ModelString = NameOfCompanyQLineEdit->text();
    if (ModelString.isEmpty() ) ModelString="Не указано";
    int id;
    QSqlQueryModel model;
    QSqlQuery query;
    QString str = QString("SELECT EXISTS (SELECT id FROM " TABLE_Company_NAMETBL " WHERE (  Title = '%1' )  AND id NOT LIKE '%2' )")
            .arg(ModelString,
                 MainModel->data(MainModel->index(mapper->currentIndex(),Company_Title), Qt::DisplayRole).toString());

    query.prepare(str);
    query.exec();
    query.next();

    str = QString("SELECT id FROM " TABLE_Company_NAMETBL " WHERE Title = '%1' ")
            .arg(ModelString);
    if(query.value(0) != 0){
        //qDebug()<< "query.value(0) != 0 - TRUE";
        model.setQuery(str);
        id = model.record(0).value("id").toInt();
    } else {
        //qDebug()<<"query.value(0) != 0 - FALSE";
        query.prepare("INSERT INTO " TABLE_Company_NAMETBL " ( " TABLE_Company_NAME_TITLE ") VALUES (:Title )");
        query.bindValue(":Title",    ModelString);
        query.exec();
        model.setQuery(str);
        id = model.record(0).value("id").toInt();
    }
    //qDebug()<<"id="<<id;
    str = QString("UPDATE "  TABLE_MAIN_NAMETBL" SET " TABLE_MAIN_COMPNANYNAME " = '%1'  WHERE id = '%2'")
            .arg(id).arg((MainModel->data(MainModel->index(mapper->currentIndex(),MAIN_stasus_Id), Qt::DisplayRole).toString()));
    query.prepare(str);
    query.exec();
    // MainModel->setRelation(MAIN_ComName,QSqlRelation(TABLE_Company_NAMETBL, "id", TABLE_Company_NAME_TITLE));
    int row = MainModel->index(mapper->currentIndex(),MAIN_stasus_Id).row();
    MainModel->select();
    MainView->selectRow(row);
}
void MainForm::updateSityModel()//https://habr.com/post/51650/
//http://tradebenefit.ru/art?id=47
{

    QString SityString = SityQLineEdit->text();
    if (SityString.isEmpty() ) SityString="Не указано";
    int id;QString str;
    QSqlQueryModel model;
    QSqlQuery query;
    query.next();
    str = QString("SELECT id FROM " TABLE_SITY_NAMETBL " WHERE Name = '%1' ")
            .arg(SityString);
    query.prepare(str);
    query.exec();
    query.next();
    if(query.value(0).isValid()){
        // qDebug()<< "query.value(0).isValid";
        // qDebug()<< "query.value(0).toInt()="<<query.value(0).toInt();
        //id = model.record(0).value("id").toInt();
        id = query.value(0).toInt();
        // qDebug()<< "id="<<id;
    } else {
        // qDebug()<< "query.value(0).is not Valid";
        query.next();
        //qDebug()<<"query.value(0) != 0 - FALSE";
        query.prepare("INSERT INTO " TABLE_SITY_NAMETBL " ( " TABLE_SITY_Name ") VALUES (:Name )");
        query.bindValue(":Name",    SityString);
        query.exec();
        model.setQuery(str);
        id = model.record(0).value("id").toInt();
    }
    //qDebug()<<"id="<<id;
    str = QString("UPDATE "  TABLE_MAIN_NAMETBL" SET " TABLE_MAIN_SITY " = '%1'  WHERE id = '%2'")
            .arg(id).arg((MainModel->data(MainModel->index(mapper->currentIndex(),MAIN_stasus_Id), Qt::DisplayRole).toString()));
    query.next();
    query.prepare(str);
    query.exec();
    int row = MainModel->index(mapper->currentIndex(),MAIN_stasus_Id).row();
    MainModel->select();
    MainView->selectRow(row);
}
void MainForm::updateRegionModel()
{
    QString RegionString = RegionQLineEdit->text();
    if (RegionString.isEmpty() ) RegionString="Не указано";
    int id;QString str;
    QSqlQueryModel model;
    QSqlQuery query;
    query.next();
    //    str = QString("SELECT EXISTS (SELECT id FROM " TABLE_STATE_NAMETBL " WHERE (  State = '%1' )  AND id NOT LIKE '%2' )")
    //            .arg(RegionString,
    //                 MainModel->data(MainModel->index(mapper->currentIndex(),STATE_Name), Qt::DisplayRole).toString());

    str = QString("SELECT id FROM " TABLE_STATE_NAMETBL " WHERE State = '%1' ")
            .arg(RegionString);

    query.prepare(str);
    query.exec();
    query.next();
    if(query.value(0).isValid()){
        //qDebug()<< "query.value(0) != 0 - TRUE";
        // model.setQuery(str);
        id = query.value(0).toInt();
        //id = model.record(0).value("id").toInt();
    } else {
        //qDebug()<<"query.value(0) != 0 - FALSE";
        query.next();
        query.prepare("INSERT INTO " TABLE_STATE_NAMETBL " ( " TABLE_STATE_STATE ") VALUES (:State )");
        query.bindValue(":State",    RegionString);
        query.exec();
        model.setQuery(str);
        id = model.record(0).value("id").toInt();
    }
    //qDebug()<<"id="<<id;
    str = QString("UPDATE "  TABLE_MAIN_NAMETBL" SET " TABLE_MAIN_REGION " = '%1'  WHERE id = '%2'")
            .arg(id).arg((MainModel->data(MainModel->index(mapper->currentIndex(),MAIN_stasus_Id), Qt::DisplayRole).toString()));
    query.prepare(str);
    query.exec();
    //query.next();
    MainModel->setRelation(MAIN_Region,QSqlRelation(TABLE_STATE_NAMETBL, "id", TABLE_STATE_STATE));
    int row = MainModel->index(mapper->currentIndex(),MAIN_stasus_Id).row();
    MainModel->select();
    MainView->selectRow(row);
}

void MainForm::updateSityQLineEdit()//не нужно
{
    //qDebug()<< (MainModel->data(MainModel->index(1,SITY_Name), Qt::DisplayRole).toString());
    //qDebug()<< "kjjjjjjjjjjjjj";
}



//void MainForm::onCheckBoxChecked(bool isChecked)
//{
//    Q_UNUSED(isChecked)
//    //    QCheckBox *widget = qobject_cast<QCheckBox*>(sender());

//    //    for( int i=0; i<ContactsModel->rowCount(); i++ )
//    //    {
//    //        if( ContactsView->indexWidget(ContactsModel->index(i, 3)) != NULL )
//    //        {
//    //            QWidget *cellWidget = qobject_cast<QWidget*>(ContactsView->indexWidget(ContactsModel->index(i, 3)))->layout()->itemAt(0)->widget();

//    //            if( widget == qobject_cast<QCheckBox*>(cellWidget) )
//    //            {
//    //                if( isChecked )
//    //                    ContactsModel->setData( ContactsModel->index(i, 3), true );
//    //                else
//    //                    ContactsModel->setData( ContactsModel->index(i, 3), false );

//    //                ContactsModel->submitAll();
//    //            }
//    //        }
//    //    }
//}

QSqlRelContactsModel::QSqlRelContactsModel(QObject *parent)
{
    Q_UNUSED( parent)
}
Qt::ItemFlags QSqlRelContactsModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QSqlTableModel::flags(index);
    // if (index.isValid())
    {
        if (index.column() ==  Contacts_Checkbox)
        {
            flags |= Qt::ItemIsUserCheckable;
        }
        else  flags |= Qt::ItemIsEditable;

        //  if (index.column() > 0 && index.column() < 6 && index.column() < 9)
        //  flags |= Qt::ItemIsEditable;
        // if (index.column() == 3)
        //  flags |= Qt::ItemIsUserCheckable;

    }
    return flags;
}
//http://www.cyberforum.ru/qt/thread2235543.html
//https://ru.opensuse.org/QT_%D0%B8_%D0%91%D0%B0%D0%B7%D1%8B_%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D1%85
QVariant QSqlRelContactsModel::data(const QModelIndex &index, int role) const
{
    QVariant value=QSqlTableModel::data(index, role);
    //  QVariant data=QSqlTableModel::data(index);
    switch (role)
    {
    case Qt::EditRole:
    {
        if(index.column() == Contacts_Checkbox){
            // qDebug()<<"value =8";
            // return value.toInt() != 0 ? tr("Да") : tr("Нет");}
            return value;}
        //return value ="8";}
        else return value;
    }break;

    case Qt::CheckStateRole:
    {
        if(index.column() == Contacts_Checkbox)
            return (QSqlTableModel::data(index) == "Да") ?
                        Qt::Checked : Qt::Unchecked;
        else
            return value;
    }break;

    case Qt::SizeHintRole:
    {
        if (index.column() == Contacts_Checkbox) return QSize(60, 10);
        else  return QSize(110, 10);
    }break;

    case Qt::TextAlignmentRole:
    {
        if (index.column() == Contacts_Checkbox)
            return int(Qt::AlignHCenter | Qt::AlignVCenter);
    }    break;
    default:return value;break;
    }
    return value;
}

bool QSqlRelContactsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool result=false;
    //    if (!index.isValid())
    //        return false;
    //    if((Qt::CheckStateRole == role) && (index.column() == 6) && (Qt::Checked == (Qt::CheckState)value.toInt()))
    //        return true;
    //    return false;
    switch (role){

    case Qt::CheckStateRole:
    {
        if(index.column() == Contacts_Checkbox){
            QModelIndex primaryKeyIndex = QSqlTableModel::index(index.row(), 0);
            int id = QSqlTableModel::data(primaryKeyIndex).toInt();
            //qDebug()<<id<<"_";
            bool ok;
            QSqlQuery query;


            if (index.column() == Contacts_Checkbox){
                query.prepare("update ContacsTable set Role = ? where id = ?");
                if (value.toBool()) query.addBindValue("Да");
                else query.addBindValue("Нет");
                query.addBindValue(id);
            }
            //qDebug()<<value.toBool()<<"_";
            ok = query.exec();
            this->select();

            //  refresh();
            return ok;
        }
    }break;
    case Qt::EditRole:
    {
        QSqlTableModel::setData(index,value,Qt::EditRole);break;
    }
    default:return  QSqlTableModel::setData(index,value,Qt::EditRole);
    }
    //    if ((index.column() == 6) && index.isValid() && (role == Qt::CheckStateRole))
    //    {
    //        if(Qt::Checked == value) // на выключенных чекбоксах
    //        {
    //            qWarning() << "checked";
    //            //index.model()->setData(index,true,);
    //            //index.model()->index()

    //            //index.model()->setData(index, true);
    //            result = true;
    //        }
    //        else // на включенных чекбоксах
    //        {
    //            qWarning() << "unchecked";
    //          //  index.model()->setData(index,0,Qt::EditRole);
    //            result = false;
    //        }
    //        QSqlQueryModel::setData (index, result);

    //        emit dataChanged(index, index);

    return result;
}
// return false;

//}
//http://ahmadferdous.blogspot.com/2009/05/qt-set-background-image-of-custom.html
void MainForm::paintEvent(QPaintEvent *p2)
{
    Q_UNUSED(p2)
    //qDebug()<<"MainForm paintEvent  ";

    //++
    //    QPixmap pix(":/sourse/stellaris/MainPanel.png");
    //    QImage img(":/sourse/stellaris/MainPanel.png");
    //    QLabel *label = new QLabel(this);
    //    label->setPixmap(QPixmap::fromImage(img));
    //    QRect dst_rc = this->rect();
    //    if(dst_rc.width() > dst_rc.height())
    //                pix = pix.scaledToHeight(dst_rc.height());
    //    else if(dst_rc.height() > dst_rc.width())
    //        pix = pix.scaledToWidth(dst_rc.width());
    //    dst_rc = pix.rect();
    //    dst_rc.moveCenter(this->rect().center());
    //    QPainter painter(this);
    //    painter.drawPixmap(dst_rc, pix);
    //    label->setAttribute(Qt::WA_PaintOnScreen);
    //    //setAttribute(Qt::WA_PaintOnScreen);
    //    //setAttribute(Qt::WA_OpaquePaintEvent);
    //    //setAttribute(Qt::WA_NoSystemBackground);
    //    qDebug()<<"MainForm::paintEvent";
    //--
    //this->setWindowOpacity(0.5);
    // label->backgroundRole();
    //label->setBackgroundRole(QPalette::Window);
    //label->setBackgroundRole(QPalette::WindowText);
    //label->setBackgroundRole(QPalette::Base);
    // MainView->setBackgroundRole(QPalette::Window);
    // MainView->setAttribute(Qt::WA_OpaquePaintEvent);
    // MainPanel->setAttribute(Qt::WA_OpaquePaintEvent);
    //    label->setAttribute(Qt::WA_OpaquePaintEvent);

    //label->setBackgroundRole(QPalette::WindowText);

    //--
    //    qDebug()<<"this->backgroundRole()"<<this->backgroundRole();
    // QPixmap img;
    // img.load(":/sourse/stellaris/MainPanel.jpg");
    //qDebug()<<"painter  ";
    //    QPainter painter ( this );
    //      painter.setRenderHint ( QPainter :: Antialiasing, true );

    //       painter.setPen (Qt::red );
    //       painter.drawText ( rect(), Qt::AlignCenter, "The Text" );

    //      draw ( &painter );

}
void MainForm :: draw ( QPainter *painter )
{
    QPen pen ( palette().foreground(), 0.5 );
    QColor color ( 128,128,128 );

    painter->setPen ( pen );
    painter->setBrush ( palette().foreground() );

    painter->drawLine ( 1,1, 50,50 );
}
