#include "qprocessclass.h"
//http://itnotesblog.ru/note.php?id=173
//https://evileg.com/ru/forum/topic/1418/

#include <QDebug>

QProcessClass::QProcessClass(QObject *parent) : QObject(parent) {

    //    QString Cmd=  tr("ipconfig");
    //    QProcess *proc= new QProcess(this);
    //    proc->start(Cmd); // ,Args

    //   // if(!Process->waitForFinished())  ui->pushButton->setText("Error");

    //    QByteArray BA = proc->readAll();
    //    QTextCodec *codec = QTextCodec::codecForName("cp866");
    //    QTextStream TextStream ( &BA);


    // TextStream.setCodec("IBM-866")
    //
    //ui->plainTextEdit->setPlainText( TextStream.readAll() ); // В вписываем текст с новой кодировкой

    //ui->pushButton->setText(QString::number(Process->exitCode()));

    static const QString PROGRAM_NAME = "youtube-dl.exe"; // Для примера - Блокнот
    static const QString arguments = "https://www.youtube.com/watch?v=jZnpYVPT8lw";

    QProcess process;
    process.start( PROGRAM_NAME, QStringList() << arguments );
    // process.start( PROGRAM_NAME);
    if( !process.waitForStarted() || !process.waitForFinished() ) {
        return;
    }

    process.waitForReadyRead();

    //     qDebug() << "process.readAll " << process.readAll();

    // connect (process,&QProcess::readyReadStandardOutput(), this,  )

    // process.write( arguments.toUtf8() );
    // process.write( "https://www.youtube.com/watch?v=jZnpYVPT8lw" );
    // process.closeWriteChannel();


    //        if( !process.waitForFinished() ) {
    //            return;
    //        }

    qDebug() << "readAllStandardError: " <<process.readAllStandardError();
    qDebug() << "readAllStandardOutput: " <<process.readAllStandardOutput();




    //   QProcess::startDetached( PROGRAM_NAME ,arguments );



    // qDebug() << proc->readAllStandardOutput();
    //
}
