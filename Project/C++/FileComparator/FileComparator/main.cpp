#include <iostream>

#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include <QSurfaceFormat>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include <mainwindow.h>


QByteArray fileChecksum(const QString& fileName, QCryptographicHash::Algorithm hashAlgorithm) {
    return QByteArray();
}
int main(int argc, char *argv[]) {
    // Initialize a Fibonacci relation sequence.
    //fibonacci_init(1, 1);
    //// Write out the sequence values until overflow.
    //do {
    //    std::cout << fibonacci_index() << ": "
    //        << fibonacci_current() << std::endl;
    //} while (fibonacci_next());
    //// Report count of values written before overflow.
    //std::cout << fibonacci_index() + 1 <<
    //    " Fibonacci sequence values fit in an " <<
    //    "unsigned 64-bit integer." << std::endl;

    //QList < QList<QString> > result_files;
    //QList <QString> result_files_;
    //result_files_.push_back("1252");
    //result_files.push_back(result_files_);

    QCoreApplication::setApplicationName("FileComparator");
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption multipleSampleOption("multisample", "Multisampling");
    parser.addOption(multipleSampleOption);
    QCommandLineOption coreProfileOption("coreprofile", "Use core profile");
    parser.addOption(coreProfileOption);
    QCommandLineOption transparentOption("transparent", "Transparent window");
    parser.addOption(transparentOption);

    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    QCoreApplication::setLibraryPaths(paths);

    QApplication app(argc, argv);

    parser.process(app);

    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    if (parser.isSet(multipleSampleOption))
        fmt.setSamples(4);
    if (parser.isSet(coreProfileOption)) {
        fmt.setVersion(3, 2);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
    }
    QSurfaceFormat::setDefaultFormat(fmt);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
