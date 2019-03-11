#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

class QDialogButtonBox;
class QLabel;
class QModelIndex;
class QPushButton;
class QSplitter;
class QSqlRelationalTableModel;
class QTableView;


class MainForm : public QWidget
{
    Q_OBJECT

public:
    MainForm();

private slots:
    void updateEmployeeView();
    void addDepartment();
    void deleteDepartment();
    void editEmployees();
    bool createConnection();
    void createFakeData();

private:
    void CreateMainPanel();
    void CreateContactsPanel();
     void CreateContactsPanel2();
    //void СreateVisitsPanel();

    void createDatabase();
    void SetupMainModel(const QString &tableName, const QStringList &headers);
    void SetupCompanyModel(const QString &tableName, const QStringList &headers);
    void SetupContactsModel(const QString &tableName, const QStringList &headers);
    void SetupVisitsModel(const QString &tableName, const QStringList &headers);
    void SetupSityModel(const QString &tableName, const QStringList &headers);




    void DropTable();
    QSqlRelationalTableModel *MainModel;
    QSqlRelationalTableModel *CompanyModel;
    QSqlRelationalTableModel *ContactsModel;
    QSqlRelationalTableModel *VisitsModel;
    QSqlRelationalTableModel *SityModel;
    QSqlRelationalTableModel *StateModel;
    QSqlRelationalTableModel *SomethingModel;

    QSqlRelationalTableModel *employeeModel;//----------
    QWidget *MainPanel;
    QWidget *ContactsPanel;
    QWidget *VisitsPanel;
    QWidget *ResultPanel;//----------
    QWidget *employeePanel;//----------
    QLabel *CompanyLabel;
    QLabel *employeeLabel;
    QTableView *MainView;
    QTableView *ContactsView;
    QTableView *VisitsView;
    QTableView *employeeView;//----------
    QSplitter *splitter;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QSplitter *mainSplitter;
    QSplitter *rightSplitter;
};

#endif

