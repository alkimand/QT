/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *NewpushButton;
    QPushButton *DelpushButton;
    QDial *dial;
    QPushButton *SavepushButton;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pathPushButton;
    QLineEdit *folderlineEdit;
    QPushButton *CopyPushButton;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QCalendarWidget *calendarWidget;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(768, 528);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setMargin(4);

        verticalLayout_4->addWidget(label_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        NewpushButton = new QPushButton(centralWidget);
        NewpushButton->setObjectName(QStringLiteral("NewpushButton"));
        NewpushButton->setFont(font);

        verticalLayout_2->addWidget(NewpushButton);

        DelpushButton = new QPushButton(centralWidget);
        DelpushButton->setObjectName(QStringLiteral("DelpushButton"));
        DelpushButton->setFont(font);

        verticalLayout_2->addWidget(DelpushButton);

        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setMaximum(10);
        dial->setPageStep(1);
        dial->setValue(5);
        dial->setSliderPosition(5);
        dial->setTracking(true);
        dial->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(dial);

        SavepushButton = new QPushButton(centralWidget);
        SavepushButton->setObjectName(QStringLiteral("SavepushButton"));
        SavepushButton->setFont(font);

        verticalLayout_2->addWidget(SavepushButton);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setLineWidth(0);
        lcdNumber->setMidLineWidth(0);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(28));
        lcdNumber->setProperty("intValue", QVariant(28));

        verticalLayout->addWidget(lcdNumber);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        pathPushButton = new QPushButton(centralWidget);
        pathPushButton->setObjectName(QStringLiteral("pathPushButton"));
        pathPushButton->setFont(font);

        verticalLayout->addWidget(pathPushButton);

        folderlineEdit = new QLineEdit(centralWidget);
        folderlineEdit->setObjectName(QStringLiteral("folderlineEdit"));

        verticalLayout->addWidget(folderlineEdit);

        CopyPushButton = new QPushButton(centralWidget);
        CopyPushButton->setObjectName(QStringLiteral("CopyPushButton"));
        CopyPushButton->setFont(font);

        verticalLayout->addWidget(CopyPushButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setMargin(4);

        verticalLayout_5->addWidget(label_3);

        listWidget = new QListWidget(centralWidget);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setCheckState(Qt::Checked);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_5->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(4);

        verticalLayout_6->addWidget(label_2);

        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(true);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::ISOWeekNumbers);

        verticalLayout_6->addWidget(calendarWidget);


        horizontalLayout->addLayout(verticalLayout_6);


        verticalLayout_8->addLayout(horizontalLayout);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_7->addWidget(textEdit);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMouseTracking(false);
        progressBar->setTabletTracking(false);
        progressBar->setFocusPolicy(Qt::NoFocus);
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setAutoFillBackground(false);
        progressBar->setValue(15);

        verticalLayout_7->addWidget(progressBar);


        verticalLayout_8->addLayout(verticalLayout_7);


        gridLayout->addLayout(verticalLayout_8, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 768, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        NewpushButton->setText(QApplication::translate("MainWindow", "+ New", nullptr));
        DelpushButton->setText(QApplication::translate("MainWindow", "-  Delite", nullptr));
        SavepushButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262", nullptr));
        pathPushButton->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \320\277\320\260\320\277\320\272\320\265 \320\276\321\202\321\207\320\265\321\202\320\276\320\262", nullptr));
        CopyPushButton->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\276\321\202\321\207\320\265\321\202", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\276\321\202\321\207\320\265\321\202\320\276\320\262 \320\275\320\260 \320\264\320\260\321\202\321\203", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\207\320\265\321\202 22.10.2018", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\207\320\265\321\202 19.10.2018", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\265\320\275\320\264\320\260\321\200\321\214", nullptr));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\236\321\202\321\207\320\265\321\202 \320\276\321\202 \321\202\320\260\320\272\320\276\320\263\320\276 \321\202\320\276 \321\207\320\270\321\201\320\273\320\260</p></body></html>", nullptr));
        progressBar->setFormat(QApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\273\320\276\321\201\321\214 \320\264\320\275\320\265\320\271 %p", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
