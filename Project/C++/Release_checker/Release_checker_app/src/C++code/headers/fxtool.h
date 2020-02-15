#pragma once

#include <QtWidgets/QMainWindow>

//#include <str/tstring.h>
//#include <fs/cfg_editor.h>

#include "ui_fxtool.h"

class FXTool : public QMainWindow
{
    Q_OBJECT

public:
    FXTool(QWidget *parent = Q_NULLPTR);
    //void readFile(const tstring& path);

protected:
  //  void keyPressEvent(QKeyEvent *event);

private:
    Ui::FXToolClass ui;
    //fs::CConfig cfg_;

private slots:
   // void saveButtonClicked();
   // void openFileClicked();
};
