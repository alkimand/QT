#include "fxtool.h"

#include <QFileDialog>
#include <QKeyEvent>

//#include <appfx/appfx_utils.h>
//#include <string/qs_utils.h>


FXTool::FXTool(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);

    //connect(ui.saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
   // connect(ui.openButton, SIGNAL(clicked()), this, SLOT(openFileClicked()));
}


//void FXTool::keyPressEvent(QKeyEvent *event) {
//    if (event->key() == Qt::Key_S && event->modifiers() == Qt::CTRL) {
//        saveButtonClicked();
//    }
//    else if (event->key() == Qt::Key_O && event->modifiers() == Qt::CTRL) {
//        openFileClicked();
//    }
//    else if (event->key() == Qt::Key_Escape) {
//        this->close();
//    }
//}


//void FXTool::readFile(const tstring& path) {
//    cfg_.initFx(path);
//    cfg_.read();
//    auto values = cfg_.getCopyValueMap();
//    std::string serializedValues = serialize(values);
//    ui.valuesEdit->setText(serializedValues.c_str());
//}
//
//
//void FXTool::openFileClicked() {
//    ui.valuesEdit->setText("");
//    std::wstring folder_path = digi::getAppSpecificFolder(fs::EAppSpecificFolder::eConfig);
//    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), WS2Q(folder_path), tr("*.fx"));
//    if (!path.isEmpty())
//        readFile(path.toStdWString());
//}
//
//
//void FXTool::saveButtonClicked() {
//    std::map<std::string, std::string> key_value_map;
//    deserialize(
//        QS2S(ui.valuesEdit->toPlainText()),
//        key_value_map);
//
//    cfg_.clear();
//
//    for (const auto &value : key_value_map)
//        cfg_.setString(value.first, value.second);
//
//    cfg_.save();
//}
