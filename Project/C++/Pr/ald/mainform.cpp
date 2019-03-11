//#include <QtGui>
#include <QtSql>
#include <QtWidgets>
//#include "employeeform.h"
#include "mainform.h"
#include "mainform2.h"
//#include <Qdebug>
#include <QDebug>
#include <QGridLayout>
MainForm::MainForm()
{
    bool existingData = QFile::exists(DATABASENAME);
    //if (!createConnection())
    createConnection();
    DropTable();
    createDatabase();
    createFakeData();
    SetupMainModel(TABLE_MAIN_NAMETBL ,     QStringList() << trUtf8("id")
                   //<< trUtf8(TABLE_MAIN_NUMBER)
                   << trUtf8(TABLE_MAIN_SITY_HEADER)
                   << trUtf8(TABLE_MAIN_STARTDATE_HEADER)
                   << trUtf8(TABLE_MAIN_ENDDATE_HEADER)
                   << trUtf8(TABLE_MAIN_REGION_HEADER)
                   << trUtf8(TABLE_MAIN_COMPNANYNAME_HEADER)
                   << trUtf8(TABLE_MAIN_MARKS_HEADER)
);
//    SetupContactsModel(TABLE_MAIN_NAMETBL,     QStringList() << trUtf8("id")
//                   << trUtf8("")
//                   << trUtf8(TABLE_CONTACS_POST_HEADER)
//                   << trUtf8(TABLE_CONTACS_NameC_HEADER)
//                   << trUtf8(TABLE_CONTACS_TELEFON_HEADER)
//                   << trUtf8(TABLE_CONTACS_MAIL_HEADER)
//                   << trUtf8(TABLE_CONTACS_ROLE_HEADER)
//                   << trUtf8(TABLE_CONTACS_SOMETHING_HEADER)
//                   << trUtf8(TABLE_CONTACS_DATE_HEADER)
//);

    SetupSityModel(TABLE_SITY_NAMETBL,     QStringList() << trUtf8("id")
                   << trUtf8("")
                   << trUtf8(TABLE_CONTACS_POST_HEADER)
                   << trUtf8(TABLE_CONTACS_NameC_HEADER)
                   << trUtf8(TABLE_CONTACS_TELEFON_HEADER)
                   << trUtf8(TABLE_CONTACS_MAIL_HEADER)
                   << trUtf8(TABLE_CONTACS_ROLE_HEADER)
                   << trUtf8(TABLE_CONTACS_SOMETHING_HEADER)
                   << trUtf8(TABLE_CONTACS_DATE_HEADER)
);








    //TABLE_CONTACS_NAMETBL

//    SetupVisitsModel(TABLE_VISITS_NAMETBL,     QStringList() << trUtf8("id")
//                   << trUtf8("")
//                   << trUtf8(TABLE_VISITS_FIRSTDATE_HEADER)
//                   << trUtf8(TABLE_VISITS_REASON_HEADER)
//                   << trUtf8(TABLE_VISITS_RESULT_HEADER)
//                   << trUtf8(TABLE_VISITS_OBJECT_HEADER)
//                   << trUtf8(TABLE_VISITS_LASTDATE_HEADER)
//);





    CreateMainPanel();
    //CreateContactsPanel2();
   // СreateVisitsPanel();
    //qDebug()<<"Hello world!";
    //  qDebug() <<"Не верно";
        mainSplitter = new QSplitter(Qt::Horizontal);
        mainSplitter->addWidget(MainPanel);
       // mainSplitter->addWidget(ContactsPanel);
       // mainSplitter->addWidget(VisitsPanel);
       // mainSplitter->setStretchFactor(0, 2);
       // mainSplitter->setStretchFactor(1, 1);
       // mainSplitter->setStretchFactor(2, 1);
       // setCentralWidget(mainSplitter);


        //splitter = new QSplitter(Qt::Vertical);
       // mainSplitter = new QSplitter(Qt::Horizontal);


        //splitter->setFrameStyle(QFrame::StyledPanel);
    //    //StyledPanel
    //    //VLine
    //    //Panel
       // splitter->addWidget(MainPanel);
       // splitter->addWidget(ContactsPanel);

        addButton = new QPushButton(tr("&Add Dept."));
        deleteButton = new QPushButton(tr("&Delete Dept."));
        editButton = new QPushButton(tr("&Edit Employees..."));
        quitButton = new QPushButton(tr("&Quit"));

        buttonBox = new QDialogButtonBox;
        buttonBox->addButton(addButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(deleteButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(editButton, QDialogButtonBox::ActionRole);
        buttonBox->addButton(quitButton, QDialogButtonBox::AcceptRole);

    //    connect(addButton, SIGNAL(clicked()), this, SLOT(addDepartment()));
    //    connect(deleteButton, SIGNAL(clicked()),
    //            this, SLOT(deleteDepartment()));
    //    connect(editButton, SIGNAL(clicked()), this, SLOT(editEmployees()));
    //    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

        //QVBoxLayout *mainLayout = new QVBoxLayout;
        QGridLayout *mainLayout = new QGridLayout;
        mainLayout->addWidget(mainSplitter);
        mainLayout->addWidget(buttonBox);
        setLayout(mainLayout);

       setWindowTitle(tr("To Salers"));
      // MainView->setCurrentIndex(MainModel->index(0, 0));
}

void MainForm::updateEmployeeView()
{
//    QModelIndex index = CompanyView->currentIndex();
//    if (index.isValid()) {
//        QSqlRecord record = CompanyModel->record(index.row());
//        int id = record.value("id").toInt();
//        employeeModel->setFilter(QString("departmentid = %1").arg(id));
//        employeeLabel->setText(tr("E&mployees in the %1 Department")
//                               .arg(record.value("name").toString()));
//    } else {
//        employeeModel->setFilter("departmentid = -1");
//        employeeLabel->setText(tr("E&mployees"));
//    }
//    employeeModel->select();
//    employeeView->horizontalHeader()->setVisible(
//                employeeModel->rowCount() > 0);
}

void MainForm::addDepartment()
{
//    int row = CompanyModel->rowCount();
//    CompanyModel->insertRow(row);
//    QModelIndex index = CompanyModel->index(row, Department_Name);
//    CompanyView->setCurrentIndex(index);
//    CompanyView->edit(index);
}

void MainForm::deleteDepartment()
{
//    QModelIndex index = CompanyView->currentIndex();
//    if (!index.isValid())
//        return;

//    QSqlDatabase::database().transaction();
//    QSqlRecord record = CompanyModel->record(index.row());
//    int id = record.value(stasus_Id).toInt();
//    int numEmployees = 0;

//    QSqlQuery query(QString("SELECT COUNT(*) FROM employee "
//                            "WHERE departmentid = %1").arg(id));
//    if (query.next())
//        numEmployees = query.value(0).toInt();
//    if (numEmployees > 0) {
//        int r = QMessageBox::warning(this, tr("Delete Department"),
//                                     tr("Delete %1 and all its employees?")
//                                     .arg(record.value(Department_Name).toString()),
//                                     QMessageBox::Yes | QMessageBox::No);
//        if (r == QMessageBox::No) {
//            QSqlDatabase::database().rollback();
//            return;
//        }

//        query.exec(QString("DELETE FROM employee "
//                           "WHERE departmentid = %1").arg(id));
//    }

//    CompanyModel->removeRow(index.row());
//    CompanyModel->submitAll();
//    QSqlDatabase::database().commit();

//    updateEmployeeView();
//    CompanyView->setFocus();
}

void MainForm::editEmployees(){}

bool MainForm::createConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASENAME);
    if (!db.open()) {
        QMessageBox::warning(0, QObject::tr(DATABASENAME),
                             db.lastError().text());
        return false;
    }
    return true;
}

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
    //1.1_____________________________Create TABLE_MAIN_NAMETBL  ****************************
    if(!query.exec( "CREATE TABLE " TABLE_MAIN_NAMETBL   " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    //TABLE_MAIN_NUMBER      " INTEGER NOT NULL,"
                    TABLE_MAIN_SITY          " INTEGER  NULL DEFAULT '0',"
                    //TABLE_MAIN_SITY        " VARCHAR(40) NOT NULL,"
                    TABLE_MAIN_STARTDATE     " DATE NULL,"
                    TABLE_MAIN_ENDDATE       " DATE NULL,"
                    TABLE_MAIN_REGION        " INTEGER  NULL DEFAULT '1',"
                    //TABLE_MAIN_COMPNANYNAME" VARCHAR(40) DEFAULT 'p2'"
                    TABLE_MAIN_COMPNANYNAME  " INTEGER  NULL DEFAULT '1',"
                    TABLE_MAIN_MARKS         " VARCHAR(40) DEFAULT '" DEFOLT "'"
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
    MainModel->setRelation(MAIN_Sity,QSqlRelation(TABLE_SITY_NAMETBL, "id", TABLE_SITY_Name));
    MainModel->setRelation(MAIN_Region,QSqlRelation(TABLE_STATE_NAMETBL, "id", TABLE_STATE_STATE));
    MainModel->setRelation(MAIN_ComName,QSqlRelation(TABLE_Company_NAMETBL, "id", TABLE_Company_NAME_TITLE));

}

void MainForm::SetupSityModel(const QString &tableName, const QStringList &headers)
{

    SityModel = new QSqlRelationalTableModel(this);
    SityModel->setTable(tableName);
//    MainModel->setRelation(MAIN_Sity,QSqlRelation(TABLE_SITY_NAMETBL, "id", TABLE_SITY_Name));
//    MainModel->setRelation(MAIN_Region,QSqlRelation(TABLE_STATE_NAMETBL, "id", TABLE_STATE_STATE));
//    MainModel->setRelation(MAIN_ComName,QSqlRelation(TABLE_Company_NAMETBL, "id", TABLE_Company_NAME_TITLE));
//    for(int i = 0, j = 0; i < MainModel->columnCount(); i++, j++){
//        SityModel->setHeaderData(i,Qt::Horizontal,headers[j]);
//    }
    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    //SityModel>setSort(0,Qt::AscendingOrder);
   // SityModel->select();






}

void MainForm::SetupVisitsModel(const QString &tableName, const QStringList &headers)
{
    VisitsModel = new QSqlRelationalTableModel(this);
    VisitsModel->setTable(tableName);
    for(int i = 0, j = 0; i < VisitsModel->columnCount(); i++, j++){
        MainModel->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
}


void MainForm::createFakeData()

{
    QSqlQuery query;
    // progress.setValue(5);
    qApp->processEvents();
    //************************  stasus  ****************
   // qDebug()<<"INSERT INTO " TABLE_CONTACS_NAMETBL  "(" TABLE_CONTACS_TELEFON  ") VALUES ('1')");
    //qDebug( )<< "INSERT INTO " TABLE_CONTACS_NAMETBL  "(" TABLE_CONTACS_NUMBER_COMP  ") VALUES ('1')";
    query.exec("INSERT INTO " TABLE_CONTACS_NAMETBL  "(" TABLE_CONTACS_POST  ") VALUES ("
               "'1')");
    query.exec("INSERT INTO " TABLE_CONTACS_NAMETBL  "(" TABLE_CONTACS_POST  ") VALUES ("
               "'2')");



    query.exec("INSERT INTO " TABLE_SITY_NAMETBL "(" TABLE_SITY_Name ") VALUES ("
               "'Не указано')");
    query.exec("INSERT INTO " TABLE_SITY_NAMETBL "(" TABLE_SITY_Name ") VALUES ("
               "'Дзержинск')");
    query.exec("INSERT INTO " TABLE_SITY_NAMETBL "(" TABLE_SITY_Name ") VALUES ("
               "'Балахна')");
    query.exec("INSERT INTO " TABLE_STATE_NAMETBL "(" TABLE_STATE_STATE ") VALUES ("
               "'Нижегородская')");
    query.exec("INSERT INTO " TABLE_STATE_NAMETBL "(" TABLE_STATE_STATE ") VALUES ("
               "'Балахна')");
    query.exec("INSERT INTO " TABLE_MAIN_NAMETBL  "("TABLE_MAIN_SITY  ") VALUES ("
               "'1')");
    query.exec("INSERT INTO " TABLE_MAIN_NAMETBL  "("TABLE_MAIN_SITY  ") VALUES ("
               "'2')");
    query.exec("INSERT INTO " TABLE_Company_NAMETBL  "("TABLE_Company_NAME_TITLE  ") VALUES ("
               "'Не указано')");
    query.exec("INSERT INTO " TABLE_Company_NAMETBL  "("TABLE_Company_NAME_TITLE  ") VALUES ("
               "'Энергопром')");
    query.exec("INSERT INTO " TABLE_Company_NAMETBL  "("TABLE_Company_NAME_TITLE  ") VALUES ("
               "'Альтаир')");

    query.exec("INSERT INTO " TABLE_VISITS_NAMETBL  "(" TABLE_VISITS_TOCOMPANY  ") VALUES ("
               "'2')");
    query.exec("INSERT INTO " TABLE_VISITS_NAMETBL  "(" TABLE_VISITS_TOCOMPANY  ") VALUES ("
               "'3')");

}

void MainForm::CreateMainPanel(){
    MainPanel = new QWidget;
    MainView = new QTableView;
    MainView->setItemDelegate(new QSqlRelationalDelegate(this));
    MainView ->setModel(MainModel);
    MainView->setSelectionMode(
            QAbstractItemView::SingleSelection);
    MainView->setColumnHidden(MAIN_stasus_Id, true);

    MainView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //MainView->setColumnHidden(Department_Id, true);
    MainView->resizeColumnsToContents();
    MainView->horizontalHeader()->setStretchLastSection(true);
    QVBoxLayout *layout = new QVBoxLayout;
   // QGridLayout *layout = new QGridLayout;
    layout->addWidget(MainView);
    MainPanel->setLayout(layout);
    //resize(800, 800);
}


void MainForm::CreateContactsPanel2(){
    ContactsPanel = new QWidget;
    ContactsView = new QTableView;
    ContactsView->setItemDelegate(new QSqlRelationalDelegate(this));
    //ContactsView ->setModel(MainModel);
    ContactsView ->setModel(SityModel);
    ContactsView->setSelectionMode(
            QAbstractItemView::SingleSelection);
   // ContactsView->setColumnHidden(MAIN_stasus_Id, true);

    ContactsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //MainView->setColumnHidden(Department_Id, true);
    ContactsView->resizeColumnsToContents();
    ContactsView->horizontalHeader()->setStretchLastSection(true);
    QVBoxLayout *layout = new QVBoxLayout;
   // QGridLayout *layout = new QGridLayout;
    layout->addWidget(ContactsView);
   ContactsPanel->setLayout(layout);
    //resize(800, 800);
}





void MainForm::CreateContactsPanel(){
    ContactsPanel = new QWidget;
    ContactsView = new QTableView;
    //ContactsView->setItemDelegate(new QSqlRelationalDelegate(this));
    ContactsView ->setModel(ContactsModel);
    // ContactsView ->setModel(MainModel);
    ContactsView->setSelectionMode(
            QAbstractItemView::SingleSelection);
//    ContactsView->setColumnHidden(Contacts_stasus_Id, true);
//    ContactsView->setColumnHidden(Contacts_Name_ofComp, true);
    ContactsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ContactsView->resizeColumnsToContents();
    ContactsView->horizontalHeader()->setStretchLastSection(true);
    QVBoxLayout *layout = new QVBoxLayout;
    //QGridLayout *layout = new QGridLayout;
    layout->addWidget(ContactsView);
    ContactsPanel->setLayout(layout);
}


//void MainForm::СreateVisitsPanel()
//{
////    VisitsPanel = new QWidget;
////    VisitsPanel = new QTableView;
////    VisitsView->setItemDelegate(new QSqlRelationalDelegate(this));
////    VisitsView ->setModel(VisitsModel);
////    VisitsView->setSelectionMode(
////            QAbstractItemView::SingleSelection);
////   VisitsView->setColumnHidden(Visits_stasus_Id, true);
////   VisitsView->setColumnHidden(Visits_Name_ofComp, true);
////   VisitsView->setSelectionBehavior(QAbstractItemView::SelectRows);
////   VisitsView->resizeColumnsToContents();
////   VisitsView->horizontalHeader()->setStretchLastSection(true);
////   QVBoxLayout *layout = new QVBoxLayout;
////   //QGridLayout *layout = new QGridLayout;
////   layout->addWidget(VisitsView);
////   ContactsPanel->setLayout(layout);
//}


