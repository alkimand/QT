#ifndef MAINFORM2_H
#define MAINFORM2_H
#define DATABASENAME "ForeSalers.dat"
//QStringList MAINheaders="";
//Company
#define FORMAT_DATE          "yyyy-MM-dd"

#define TABLE_Company_NAMETBL          "CompanyNames"
#define TABLE_Company_NAME_TITLE       "Title"
enum {
    Company_stasus_Id = 0,
    Company_Title = 1
};



//Maintable
#define TABLE_MAIN_NAMETBL             "MainTable"

#define TABLE_MAIN_NUMBER              "Number" //Companyname в integer="Companyname" без модели
#define TABLE_MAIN_SITY                "Sity"
#define TABLE_MAIN_SITY_HEADER         "Город"
#define TABLE_MAIN_STARTDATE           "Startdate"
#define TABLE_MAIN_STARTDATE_HEADER    "Дата"
#define TABLE_MAIN_ENDDATE             "Enddate"
#define TABLE_MAIN_REGION              "Region"
#define TABLE_MAIN_REGION_HEADER       "Регион"
#define TABLE_MAIN_ENDDATE_HEADER      "Дата повтора"
#define TABLE_MAIN_COMPNANYNAME        "Companyname"
#define TABLE_MAIN_COMPNANYNAME_HEADER "Название компании"
#define TABLE_MAIN_MARKS               "Marks"
#define TABLE_MAIN_MARKS_HEADER        "Отметки"
#define TABLE_MAIN_HREF                "Href"
#define TABLE_MAIN_HREF_HEADER         "Сайт"
#define DEFOLT                         "Не указано"

enum {
    MAIN_stasus_Id = 0,
    MAIN_Sity = 1,
    MAIN_Date1 = 2,
    MAIN_Date2 = 3,
    MAIN_Region = 4,
    MAIN_ComName = 5,
    MAIN_Marks = 6,
    MAIN_HrefSite = 7
};

//Contacts
#define TABLE_CONTACS_NAMETBL          "ContacsTable"

#define TABLE_CONTACS_NUMBER_COMP      "NumCompany"
#define TABLE_CONTACS_POST             "Post"
#define TABLE_CONTACS_POST_HEADER      "Должность"
#define TABLE_CONTACS_NameC            "NameofPeople"
#define TABLE_CONTACS_NameC_HEADER     "ФИО"
#define TABLE_CONTACS_TELEFON          "TelefonNumber"
#define TABLE_CONTACS_TELEFON_HEADER  "Номер телефона"
#define TABLE_CONTACS_MAIL             "Mail"
#define TABLE_CONTACS_MAIL_HEADER      "Почта"
#define TABLE_CONTACS_ROLE             "Role"
#define TABLE_CONTACS_ROLE_HEADER      "ЛПР"
#define TABLE_CONTACS_SOMETHING        "Something"
#define TABLE_CONTACS_SOMETHING_HEADER "Дополнительно"
#define TABLE_CONTACS_DATE             "Date"
#define TABLE_CONTACS_DATE_HEADER      "Дата рождения"

enum {
    Contacts_stasus_Id = 0,
    Contacts_Name_ofComp = 1,
    Contacts_Post = 2,
    Contacts_Mail = 5,
    Contacts_Checkbox = 6,
    Contacts_Something = 7,
    Contacts_DATE = 8
};

//Visits
#define TABLE_VISITS_NAMETBL          "VisitsTable"

#define TABLE_VISITS_TOCOMPANY         "CompNumber"
#define TABLE_VISITS_FIRSTDATE         "FirstDate"
#define TABLE_VISITS_FIRSTDATE_HEADER  "Начальная дата"
#define TABLE_VISITS_REASON            "Reason"
#define TABLE_VISITS_REASON_HEADER     "Причина"
#define TABLE_VISITS_RESULT            "Result"
#define TABLE_VISITS_RESULT_HEADER     "Результат"
#define TABLE_VISITS_OBJECT            "Object"
#define TABLE_VISITS_OBJECT_HEADER     "Объект"
#define TABLE_VISITS_LASTDATE          "LastDate"
#define TABLE_VISITS_LASTDATE_HEADER   "Следующая дата"
enum {
    Visits_stasus_Id = 0,
    Visits_Name_ofComp = 1,
    Visits_Date1 = 2,
    Visits_Date2 = 6
};

//Sity

#define TABLE_SITY_NAMETBL           "SityTable"
#define TABLE_SITY_Name              "Name"

enum {
    SITY_stasus_Id = 0,
    SITY_Name = 1

};

//State
#define TABLE_STATE_NAMETBL           "StateTable"
#define TABLE_STATE_STATE             "State"
enum {
    STATE_stasus_Id = 0,
    STATE_Name = 1
};

//Something
#define TABLE_SOMETHINGELSE_NAMETBL   "SomethingTable"

#define TABLE_SOMETHINGELSE_SOMETHING  "Something"







#endif // MAINFORM2_H
