/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowWgt
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QWidget *VerticalllabelWgt;
    QVBoxLayout *verticalLayout_5;
    QWidget *HorizontallabelWgt;
    QHBoxLayout *horizontalLayout_5;
    QLabel *addingLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *comparingLbl;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QListView *addedView;
    QWidget *verticalWidget_2;
    QVBoxLayout *buttonWgt;
    QSpacerItem *verticalSpacer_4;
    QPushButton *searchBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *compareBtn;
    QSpacerItem *verticalSpacer_2;
    QPushButton *stopBtn;
    QSpacerItem *verticalSpacer_3;
    QListView *comparedView;
    QWidget *HorizontalFolderWgt;
    QHBoxLayout *horizontalLayout_2;
    QWidget *VerticalFolderWgt;
    QVBoxLayout *verticalLayout_2;
    QWidget *addFolder1Wgt;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelFirst;
    QSpacerItem *horizontalSpacer;
    QPushButton *addFolderBtn1;
    QWidget *addFolder2Wgt;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelSecond;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addFolderBtn2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowWgt)
    {
        if (MainWindowWgt->objectName().isEmpty())
            MainWindowWgt->setObjectName(QString::fromUtf8("MainWindowWgt"));
        MainWindowWgt->resize(693, 678);
        centralWidget = new QWidget(MainWindowWgt);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalWidget = new QWidget(centralWidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, 3, 5);
        VerticalllabelWgt = new QWidget(verticalWidget);
        VerticalllabelWgt->setObjectName(QString::fromUtf8("VerticalllabelWgt"));
        verticalLayout_5 = new QVBoxLayout(VerticalllabelWgt);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 0, 5, 0);
        HorizontallabelWgt = new QWidget(VerticalllabelWgt);
        HorizontallabelWgt->setObjectName(QString::fromUtf8("HorizontallabelWgt"));
        horizontalLayout_5 = new QHBoxLayout(HorizontallabelWgt);
        horizontalLayout_5->setSpacing(7);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, 0);
        addingLabel = new QLabel(HorizontallabelWgt);
        addingLabel->setObjectName(QString::fromUtf8("addingLabel"));
        addingLabel->setStyleSheet(QString::fromUtf8("font: 17px \"Arial Black\";"));

        horizontalLayout_5->addWidget(addingLabel);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        comparingLbl = new QLabel(HorizontallabelWgt);
        comparingLbl->setObjectName(QString::fromUtf8("comparingLbl"));
        comparingLbl->setLayoutDirection(Qt::LeftToRight);
        comparingLbl->setStyleSheet(QString::fromUtf8("font: 17px \"Arial Black\";"));
        comparingLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(comparingLbl);


        verticalLayout_5->addWidget(HorizontallabelWgt);


        verticalLayout->addWidget(VerticalllabelWgt);

        horizontalWidget = new QWidget(verticalWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        addedView = new QListView(horizontalWidget);
        addedView->setObjectName(QString::fromUtf8("addedView"));

        horizontalLayout->addWidget(addedView);

        verticalWidget_2 = new QWidget(horizontalWidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        buttonWgt = new QVBoxLayout(verticalWidget_2);
        buttonWgt->setSpacing(6);
        buttonWgt->setContentsMargins(11, 11, 11, 11);
        buttonWgt->setObjectName(QString::fromUtf8("buttonWgt"));
        buttonWgt->setContentsMargins(10, -1, 10, -1);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        buttonWgt->addItem(verticalSpacer_4);

        searchBtn = new QPushButton(verticalWidget_2);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        searchBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
""));

        buttonWgt->addWidget(searchBtn);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        buttonWgt->addItem(verticalSpacer);

        compareBtn = new QPushButton(verticalWidget_2);
        compareBtn->setObjectName(QString::fromUtf8("compareBtn"));
        compareBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
""));

        buttonWgt->addWidget(compareBtn);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        buttonWgt->addItem(verticalSpacer_2);

        stopBtn = new QPushButton(verticalWidget_2);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        stopBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
""));

        buttonWgt->addWidget(stopBtn);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        buttonWgt->addItem(verticalSpacer_3);


        horizontalLayout->addWidget(verticalWidget_2);

        comparedView = new QListView(horizontalWidget);
        comparedView->setObjectName(QString::fromUtf8("comparedView"));

        horizontalLayout->addWidget(comparedView);


        verticalLayout->addWidget(horizontalWidget);


        gridLayout->addWidget(verticalWidget, 1, 0, 1, 1);

        HorizontalFolderWgt = new QWidget(centralWidget);
        HorizontalFolderWgt->setObjectName(QString::fromUtf8("HorizontalFolderWgt"));
        horizontalLayout_2 = new QHBoxLayout(HorizontalFolderWgt);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        VerticalFolderWgt = new QWidget(HorizontalFolderWgt);
        VerticalFolderWgt->setObjectName(QString::fromUtf8("VerticalFolderWgt"));
        verticalLayout_2 = new QVBoxLayout(VerticalFolderWgt);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        addFolder1Wgt = new QWidget(VerticalFolderWgt);
        addFolder1Wgt->setObjectName(QString::fromUtf8("addFolder1Wgt"));
        horizontalLayout_3 = new QHBoxLayout(addFolder1Wgt);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelFirst = new QLabel(addFolder1Wgt);
        labelFirst->setObjectName(QString::fromUtf8("labelFirst"));
        labelFirst->setMinimumSize(QSize(100, 0));
        labelFirst->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(labelFirst);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        addFolderBtn1 = new QPushButton(addFolder1Wgt);
        addFolderBtn1->setObjectName(QString::fromUtf8("addFolderBtn1"));
        addFolderBtn1->setMaximumSize(QSize(100, 16777215));
        addFolderBtn1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_3->addWidget(addFolderBtn1);


        verticalLayout_2->addWidget(addFolder1Wgt);

        addFolder2Wgt = new QWidget(VerticalFolderWgt);
        addFolder2Wgt->setObjectName(QString::fromUtf8("addFolder2Wgt"));
        horizontalLayout_4 = new QHBoxLayout(addFolder2Wgt);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelSecond = new QLabel(addFolder2Wgt);
        labelSecond->setObjectName(QString::fromUtf8("labelSecond"));
        labelSecond->setMinimumSize(QSize(100, 0));
        labelSecond->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelSecond->setScaledContents(false);
        labelSecond->setWordWrap(false);

        horizontalLayout_4->addWidget(labelSecond);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        addFolderBtn2 = new QPushButton(addFolder2Wgt);
        addFolderBtn2->setObjectName(QString::fromUtf8("addFolderBtn2"));
        addFolderBtn2->setMinimumSize(QSize(0, 0));
        addFolderBtn2->setMaximumSize(QSize(100, 100));
        addFolderBtn2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_4->addWidget(addFolderBtn2);


        verticalLayout_2->addWidget(addFolder2Wgt);


        horizontalLayout_2->addWidget(VerticalFolderWgt);


        gridLayout->addWidget(HorizontalFolderWgt, 0, 0, 1, 1);

        MainWindowWgt->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowWgt);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 693, 21));
        MainWindowWgt->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowWgt);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowWgt->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowWgt);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowWgt->setStatusBar(statusBar);

        retranslateUi(MainWindowWgt);

        QMetaObject::connectSlotsByName(MainWindowWgt);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowWgt)
    {
        MainWindowWgt->setWindowTitle(QCoreApplication::translate("MainWindowWgt", "QtWidgetsApplication1", nullptr));
        addingLabel->setText(QString());
        comparingLbl->setText(QString());
        searchBtn->setText(QCoreApplication::translate("MainWindowWgt", "Search File", nullptr));
        compareBtn->setText(QCoreApplication::translate("MainWindowWgt", "Compare", nullptr));
        stopBtn->setText(QCoreApplication::translate("MainWindowWgt", "Stop", nullptr));
        labelFirst->setText(QString());
        addFolderBtn1->setText(QCoreApplication::translate("MainWindowWgt", "Add 1 Folder", nullptr));
        labelSecond->setText(QString());
        addFolderBtn2->setText(QCoreApplication::translate("MainWindowWgt", "Add 2 Folder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowWgt: public Ui_MainWindowWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
