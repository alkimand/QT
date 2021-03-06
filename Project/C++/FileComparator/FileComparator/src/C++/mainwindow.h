#pragma once

#include <QMainWindow>
#include <QSharedPointer>
#include <QScopedPointer>

#include <QList>
#include <QStringList>
#include <QtWidgets/QMainWindow>

#include <ui_mainwindow.h>
#include <engine.h>

class MainWindow : public QMainWindow {
    Q_OBJECT
        enum class eAddresType {
        first = 0,
        second = 1
    };

public:
    MainWindow(QWidget* parent = Q_NULLPTR);

    ~MainWindow();
private slots:
    void onSearchBtn();
    void onCompareBtn();
    void onCompareFinished(QList<QList<QString>> file_container);
    void onStopBtn();
private:
    void onAddFolderBtn(eAddresType);
    QStringList getFilePaths(const QString& folder_path);
    void setupUI();
    bool checkDirectory();
signals:

private:
    Ui::MainWindowWgt* ui;
    QScopedPointer <Engine>   engine_;
    QStringList               files_;
};

