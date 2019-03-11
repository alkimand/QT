#include "mainwindow.h"
#include "toolwidget.h"
#include <QDebug>

//constantlist.h
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mdiArea = new QMdiArea;
    //http://doc.qt.io/qt-5/qmdiarea.html#ViewMode-enum
    //mdiArea->setViewMode(QMdiArea::TabbedView);
    setCentralWidget(mdiArea);
    connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            this, SLOT(updateActions()));

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
   // setWindowIcon(QPixmap(":/sourse/images_button/icon.png"));
    setWindowTitle(tr("CongigData"));
    //QTimer::singleShot(0, this, SLOT(loadFiles()));

}



void MainWindow::loadFiles()
{
    qDebug()<<"loadFiles";
    QStringList args = QApplication::arguments();
    args.removeFirst();
    if (!args.isEmpty()) {
        foreach (QString arg, args)
            openFile(arg);
        mdiArea->cascadeSubWindows();
    } else {
        newFile();
        mdiArea->cascadeSubWindows();

    }
    mdiArea->activateNextSubWindow();
}

void MainWindow::newFile()
{
    qDebug()<<"newFile";
    ToolWidget *toolwidget = new ToolWidget(this);
    toolwidget->newFile();
    this->addToolWidget(toolwidget);
}

void MainWindow::openFile(const QString &fileName)
{
    qDebug()<<"openFile";
    ToolWidget *toolwidget = ToolWidget::openFile(fileName, this);
    if (toolwidget)
    addToolWidget(toolwidget);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug()<<"closeEvent";
    mdiArea->closeAllSubWindows();
    if (!mdiArea->subWindowList().isEmpty()) {
        event->ignore();
    } else {
        event->accept();
    }
}

void MainWindow::open()
{
    qDebug()<<"open";
//    Editor *editor = Editor::open(this);
//    if (editor)
//        addToolWidget(editor);
}

void MainWindow::save()
{
//    if (activeEditor())
//        activeEditor()->save();
}

void MainWindow::saveAs()
{
    qDebug()<<"saveAs";
//    if (activeEditor())
//        activeEditor()->saveAs();
}

void MainWindow::cut()
{
     qDebug()<<"saveAs";
//    if (activeEditor())
//        activeEditor()->cut();
}

void MainWindow::copy()
{
//    if (activeEditor())
//        activeEditor()->copy();
}

void MainWindow::paste()
{
     qDebug()<<"paste";
//    if (activeEditor())
//        activeEditor()->paste();
}

void MainWindow::about()
{
    qDebug()<<"about";
    QMessageBox::about(this, tr("About ConfData Editor"),
            tr("<h2>ConfData 1.0(pre-release)</h2>"
               "<p>Copyright &copy; 2018 Software Inc."
               "<p>MDI Editor is a small application that demonstrates "
               "QMdiArea."));
}

void MainWindow::updateActions()
{
    qDebug()<<"updateActions";
 bool hasEditor = (activeEditor() != nullptr);
 bool hasSelection = activeEditor() && activeEditor();

    //bool hasSelection=true;

    saveAction->setEnabled(hasEditor);
    saveAsAction->setEnabled(hasEditor);
    cutAction->setEnabled(hasSelection);
    copyAction->setEnabled(hasSelection);
    pasteAction->setEnabled(hasEditor);
    closeAction->setEnabled(hasEditor);
    closeAllAction->setEnabled(hasEditor);
    tileAction->setEnabled(hasEditor);
    cascadeAction->setEnabled(hasEditor);
    nextAction->setEnabled(hasEditor);
    previousAction->setEnabled(hasEditor);
    separatorAction->setVisible(hasEditor);

    if (activeEditor())
        activeEditor()->windowMenuAction()->setChecked(true);
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/sourse/images_button/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open..."), this);
    openAction->setIcon(QIcon(":/sourse/images_button/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/sourse/images_button/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the file to disk"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAction = new QAction(tr("Save &As..."), this);
    saveAsAction->setStatusTip(tr("Save the file under a new name"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/sourse/images_button/cut.png"));
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut the current selection to the "
                               "clipboard"));
    connect(cutAction, SIGNAL(triggered()), this, SLOT(cut()));

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/sourse/images_button/copy.png"));
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy the current selection to the "
                                "clipboard"));
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setIcon(QIcon(":/sourse/images_button/paste.png"));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the clipboard's contents at "
                                 "the cursor position"));
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));

    closeAction = new QAction(tr("Cl&ose"), this);
    closeAction->setShortcut(QKeySequence::Close);
    closeAction->setStatusTip(tr("Close the active window"));
    connect(closeAction, SIGNAL(triggered()),
            mdiArea, SLOT(closeActiveSubWindow()));

    closeAllAction = new QAction(tr("Close &All"), this);
    closeAllAction->setStatusTip(tr("Close all the windows"));
    connect(closeAllAction, SIGNAL(triggered()), this, SLOT(close()));

    tileAction = new QAction(tr("&Tile"), this);
    tileAction->setStatusTip(tr("Tile the windows"));
    connect(tileAction, SIGNAL(triggered()),
            mdiArea, SLOT(tileSubWindows()));

    cascadeAction = new QAction(tr("&Cascade"), this);
    cascadeAction->setStatusTip(tr("Cascade the windows"));
    connect(cascadeAction, SIGNAL(triggered()),
            mdiArea, SLOT(cascadeSubWindows()));

    nextAction = new QAction(tr("Ne&xt"), this);
    nextAction->setShortcut(QKeySequence::NextChild);
    nextAction->setStatusTip(tr("Move the focus to the next window"));
    connect(nextAction, SIGNAL(triggered()),
            mdiArea, SLOT(activateNextSubWindow()));

    previousAction = new QAction(tr("Pre&vious"), this);
    previousAction->setShortcut(QKeySequence::PreviousChild);
    previousAction->setStatusTip(tr("Move the focus to the previous "
                                    "window"));
    connect(previousAction, SIGNAL(triggered()),
            mdiArea, SLOT(activatePreviousSubWindow()));

    separatorAction = new QAction(this);
    separatorAction->setSeparator(true);

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    windowActionGroup = new QActionGroup(this);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->setStatusTip(tr("&File111"));
   // ->setStatusTip
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));;
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);

    windowMenu = menuBar()->addMenu(tr("&Window"));
    windowMenu->addAction(closeAction);
    windowMenu->addAction(closeAllAction);
    windowMenu->addSeparator();
    windowMenu->addAction(tileAction);
    windowMenu->addAction(cascadeAction);
    windowMenu->addSeparator();
    windowMenu->addAction(nextAction);
    windowMenu->addAction(previousAction);
    windowMenu->addAction(separatorAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
}

void MainWindow::createStatusBar()
{
    readyLabel = new QLabel(tr(" Ready"));
    statusBar()->addWidget(readyLabel, 1);
}

void MainWindow::addToolWidget(ToolWidget *toolwidget)
{
//    connect(ToolWidget, SIGNAL(copyAvailable(bool)),
//            cutAction, SLOT(setEnabled(bool)));
//    connect(ToolWidget, SIGNAL(copyAvailable(bool)),
//          copyAction, SLOT(setEnabled(bool)));

    QMdiSubWindow *subWindow = mdiArea->addSubWindow(toolwidget);
    windowMenu->addAction(toolwidget->windowMenuAction());
    windowActionGroup->addAction(toolwidget->windowMenuAction());
    subWindow->show();
}

ToolWidget *MainWindow::activeEditor()
{
    QMdiSubWindow *subWindow = mdiArea->activeSubWindow();
    if (subWindow)
        return qobject_cast<ToolWidget *>(subWindow->widget());
    return nullptr;
}
MainWindow::~MainWindow()
{

}
