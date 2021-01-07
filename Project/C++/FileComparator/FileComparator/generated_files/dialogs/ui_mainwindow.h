/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QListView *addedView;
    QWidget *verticalWidget_2;
    QVBoxLayout *buttonWgt;
    QSpacerItem *verticalSpacer_4;
    QPushButton *searchBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *compareBtn;
    QSpacerItem *verticalSpacer_3;
    QListView *comparedView;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelFirst;
    QSpacerItem *horizontalSpacer;
    QPushButton *addFolderBtn1;
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
            MainWindowWgt->setObjectName(QStringLiteral("MainWindowWgt"));
        MainWindowWgt->resize(712, 642);
        centralWidget = new QWidget(MainWindowWgt);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalWidget = new QWidget(centralWidget);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalWidget = new QWidget(verticalWidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addedView = new QListView(horizontalWidget);
        addedView->setObjectName(QStringLiteral("addedView"));

        horizontalLayout->addWidget(addedView);

        verticalWidget_2 = new QWidget(horizontalWidget);
        verticalWidget_2->setObjectName(QStringLiteral("verticalWidget_2"));
        buttonWgt = new QVBoxLayout(verticalWidget_2);
        buttonWgt->setSpacing(6);
        buttonWgt->setContentsMargins(11, 11, 11, 11);
        buttonWgt->setObjectName(QStringLiteral("buttonWgt"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        buttonWgt->addItem(verticalSpacer_4);

        searchBtn = new QPushButton(verticalWidget_2);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        searchBtn->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
""));

        buttonWgt->addWidget(searchBtn);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        buttonWgt->addItem(verticalSpacer);

        compareBtn = new QPushButton(verticalWidget_2);
        compareBtn->setObjectName(QStringLiteral("compareBtn"));
        compareBtn->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
""));

        buttonWgt->addWidget(compareBtn);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        buttonWgt->addItem(verticalSpacer_3);


        horizontalLayout->addWidget(verticalWidget_2);

        comparedView = new QListView(horizontalWidget);
        comparedView->setObjectName(QStringLiteral("comparedView"));

        horizontalLayout->addWidget(comparedView);


        verticalLayout->addWidget(horizontalWidget);


        gridLayout->addWidget(verticalWidget, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelFirst = new QLabel(centralWidget);
        labelFirst->setObjectName(QStringLiteral("labelFirst"));
        labelFirst->setMinimumSize(QSize(100, 0));
        labelFirst->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(labelFirst);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        addFolderBtn1 = new QPushButton(centralWidget);
        addFolderBtn1->setObjectName(QStringLiteral("addFolderBtn1"));
        addFolderBtn1->setMaximumSize(QSize(100, 16777215));
        addFolderBtn1->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_3->addWidget(addFolderBtn1);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelSecond = new QLabel(centralWidget);
        labelSecond->setObjectName(QStringLiteral("labelSecond"));
        labelSecond->setMinimumSize(QSize(100, 0));
        labelSecond->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        labelSecond->setScaledContents(false);
        labelSecond->setWordWrap(false);

        horizontalLayout_4->addWidget(labelSecond);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        addFolderBtn2 = new QPushButton(centralWidget);
        addFolderBtn2->setObjectName(QStringLiteral("addFolderBtn2"));
        addFolderBtn2->setMinimumSize(QSize(0, 0));
        addFolderBtn2->setMaximumSize(QSize(100, 100));
        addFolderBtn2->setStyleSheet(QLatin1String("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_4->addWidget(addFolderBtn2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        MainWindowWgt->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowWgt);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 712, 21));
        MainWindowWgt->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowWgt);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowWgt->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowWgt);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowWgt->setStatusBar(statusBar);

        retranslateUi(MainWindowWgt);

        QMetaObject::connectSlotsByName(MainWindowWgt);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowWgt)
    {
        MainWindowWgt->setWindowTitle(QApplication::translate("MainWindowWgt", "QtWidgetsApplication1", 0));
        searchBtn->setText(QApplication::translate("MainWindowWgt", "Search File", 0));
        compareBtn->setText(QApplication::translate("MainWindowWgt", "Compare", 0));
        labelFirst->setText(QApplication::translate("MainWindowWgt", "C:/Users/serg/Desktop/temp/1", 0));
        addFolderBtn1->setText(QApplication::translate("MainWindowWgt", "Add 1 Folder", 0));
        labelSecond->setText(QApplication::translate("MainWindowWgt", "C:/Users/serg/Desktop/temp/2", 0));
        addFolderBtn2->setText(QApplication::translate("MainWindowWgt", "Add 2 Folder", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowWgt: public Ui_MainWindowWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
