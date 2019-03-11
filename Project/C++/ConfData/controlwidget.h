#ifndef CONTROL_WIDGET_H
#define CONTROL_WIDGET_H
#include <QMap>
#include <QWidget>
#include "generaltoolwidget.h"
#include <QProgressBar>

class QLabel;
class QLineEdit;
class QDateEdit;
class QComboBox;
class GeneralProduct;
//class QProgressBar;
class QListWidget;
class QStackedLayout;
class QPushButton;
class QTableView;
class QListWidget;
class Control_Widget : public GeneralToolWidget
{
    Q_OBJECT
public:
     explicit Control_Widget(QWidget *parent = nullptr);
private :
    QLineEdit *FolderChoiceLineEdit;
    QLineEdit *TemplateFolderChoiceLineEdit;

    QPushButton *FolderChoicePushButton;
    QPushButton *TemplateFolderChoiceButton;
    QPushButton *TemplateChoiceButton;
    QPushButton *TemplateCopyToFolderButton;
    QPushButton *TemplateReWrriteFilerButton;

    QProgressBar *FolderChoiceProgressBar;
    QProgressBar *TemplateFolderProgressBar;
    QProgressBar *TemplateChoiceProgressBar;
    QProgressBar *TemplateCopyToFolderProgressBar;
    QProgressBar *TemplateReWrriteProgressBar;

    QTableView *AllTemplateTableView;
    QTableView *ChoiseTemplateTableView;
    QListWidget *TemplateQListWidget;
    QString getfilename();

//    QLabel *FolderChoiceLabel;
//    QLabel *TemplateFolderChoiceLabel;//для файлов с заменой
//    //QLabel *TemplateFolderLabel;//для
//    QLabel *StatusCopyTemplateLabel;
//    QLabel *StartReWriteAllLabel;
//    QLabel *SaveAsTemplateLabel;

//    QStackedLayout *stackedLayout;

//    QListWidget *ChoiceFolderWidget;//для выбора всех путей
//    QListWidget *ChoiceTemplatFileWidget;//для лист шаблонов и выбора каких файлов
//    QListWidget *StatusAfterMakeWidget;//для статусбары и итог




    QString pagename;
    QString getpagename();
    void initpage(){};

    QString filename;
    QString TemplateFoldername;//папка
    QStringList Templatefilenames;//лист с файлами шаблонов - полные пути
    QStringList filenames; //only names of file + extension
    signals:
    private slots:
    void getProductFolder();
    void getTemplateFolder();
    void createTemplateFileList();
    void copyTemplateTofolder();

};

#endif // CONTROL_WIDGET_H
