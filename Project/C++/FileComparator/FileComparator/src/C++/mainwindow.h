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
    void onCompareFinished(QList<QList<QString>> file_container);

private:
    void onAddFolderBtn(eAddresType);
    QStringList getFilePaths(const QString& folder_path);
    void setupUI();
signals:
    //void folderParsed(QStringList list);

private:
    Ui::MainWindowWgt* ui;
    QScopedPointer <Engine>   engine_;
    QStringList               file_paths_;
};

