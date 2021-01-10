#include <QtCore>
#include <QtGui>

#include <QFileDialog>
#include <QMessageBox>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QStringListModel>

#include <QtConcurrent>

#include <mainwindow.h>
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindowWgt) {
    engine_.reset(new Engine(this));
    if (QMetaType::type("QList<QList<QString>>") == QMetaType::UnknownType)
        qRegisterMetaType<QList<QList<QString>>>("QList<QList<QString>>");
    QObject::connect(engine_.data(), &Engine::compareFinished, this, &MainWindow::onCompareFinished);

    if (QMetaType::type("QPair <int, int>") == QMetaType::UnknownType)
        qRegisterMetaType<QPair <int, int>>("QPair <int, int>");

    ui->setupUi(this);
    setupUI();
}


void MainWindow::onAddFolderBtn(eAddresType type) {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty()) {
        switch (type) {
        case MainWindow::eAddresType::first:
            this->ui->labelFirst->setText(dir);
            break;
        case MainWindow::eAddresType::second:
            this->ui->labelSecond->setText(dir);
            break;
        default:
            break;
        }
    }
}


void MainWindow::onSearchBtn() {
    this->ui->comparedView->setModel(new QStringListModel(QStringList()));
    QString first_dir = this->ui->labelFirst->text();
    QString second_dir = this->ui->labelSecond->text();
    if (!first_dir.isEmpty() && !second_dir.isEmpty() &&
        (first_dir != second_dir) && QDir(first_dir).exists()
        && QDir(second_dir).exists()) {

        QStringList fist_folder_list;
        QStringList second_folder_list;

        auto fist_working_thread = QtConcurrent::run([&]() {
            fist_folder_list = getFilePaths(first_dir); });

        auto second_working_thread = QtConcurrent::run([&]() {
            second_folder_list = getFilePaths(second_dir); });

        fist_working_thread.waitForFinished();
        second_working_thread.waitForFinished();

        QStringList    file_paths;
        file_paths << fist_folder_list << second_folder_list;

        this->ui->addedView->setModel(new QStringListModel(file_paths));

        QString adding_text = "founded " + QString::number(file_paths.size()) + " files";
        this->ui->addingLabel->setText(adding_text);
        QString progress_text = "progress " + QString::number(0) + " of " + QString::number(file_paths.size());
        this->ui->comparingLbl->setText(progress_text);

        engine_.data()->compareFiles(file_paths);
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Set the correct folder");
        msgBox.exec();
    }
}


void MainWindow::onCompareFinished(QList<QList<QString>> file_container) {
    QStringList result_list;
    this->ui->comparedView->setModel(new QStringListModel(result_list));
    QString separator(80, '-');
    for (auto hash_group_files : file_container) {
        result_list << separator;
        for (auto file_path : hash_group_files) {
            result_list << file_path;
        }
    }
  this->ui->comparedView->setModel(new QStringListModel(result_list));
}


void MainWindow::onStopBtn() {
    engine_.data()->stopWorkingThread();
    this->ui->comparedView->setModel(new QStringListModel(QStringList()));
    this->ui->comparingLbl->setText("");
}


QStringList MainWindow::getFilePaths(const QString& folder_path) {
    QStringList file_paths;
    QDirIterator it(folder_path, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
        file_paths << it.next();
    return file_paths;
}


void MainWindow::setupUI() {
    QObject::connect(this->ui->addFolderBtn1, &QPushButton::clicked, this, [this]() {
        onAddFolderBtn(eAddresType::first);});

    QObject::connect(this->ui->addFolderBtn2, &QPushButton::clicked, this, [this]() {
        onAddFolderBtn(eAddresType::second);});

    QObject::connect(this->ui->searchBtn, &QPushButton::clicked, this, &MainWindow::onSearchBtn);
    QObject::connect(this->ui->stopBtn, &QPushButton::clicked, this, &MainWindow::onStopBtn);

    QObject::connect(engine_.data(), &Engine::setProgress, this, [this](const QPair <int, int> curent_progress) {
        QString text = "progress " + QString::number(curent_progress.first) + " of " + QString::number(curent_progress.second);
        this->ui->comparingLbl->setText(text);
    });
}


MainWindow::~MainWindow() {
    delete ui;
}


