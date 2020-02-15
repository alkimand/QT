#include <QCoreApplication>
quint16     m_nNextBlockSize;
#include <QString>
#include <QByteArray>
#include <QtGlobal>
#include <QDataStream>
#include <zlib.h>
#include <QTextCodec>
#include <QTcpSocket>
#include <QDebug>
#include <QtNetwork>

quint32 computeStringHash(const QString& str)
{
    quint32 hash = 0;
    for (int i = 0; i < str.size(); i++)
    {
        hash ^= str.at(i).unicode();
    }

    return hash;
}



QString string_CSR( int s, QString str)  // подстчет контрольной суммы,на выходе строка которую отправляем в порт
       {
    QString writestr;
    QString str3;
    int asciiCode[10];
    int k=0;
     QByteArray byteArray = str.toLocal8Bit();
     for (int i = 0; i < byteArray.size(); i++){
          asciiCode[i] = (int)byteArray[i];
      k=asciiCode[i]^k;
     }
     str3=QString("%1").arg(k,0,16);
     writestr=str+str3;
return writestr;
}







int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
   QTcpServer *m_ptcpServer = new QTcpServer;
   QTcpSocket* pClientSocket=new QTcpSocket;
   int nPort=6000;

    m_ptcpServer->listen(QHostAddress::Any, nPort);
   pClientSocket = m_ptcpServer->nextPendingConnection();

    QDataStream in(pClientSocket);

    quint16 m_nNextBlockSize=0;
     //QByteArray  arrBlock= pClientSocket->readAll();
    //qDebug()<< QTextCodec::codecForMib(1015)->toUnicode(arrBlock);
   in.setVersion(QDataStream::Qt_5_3);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (pClientSocket->bytesAvailable() < (int)sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }

       // QTime   time;
        QString str;

        //QDataStream out(&arrBlock, QIODevice::WriteOnly);
       // in2 >> arrBlock;
       // in >> arrBlock;
        //in >> time >> str;
        in >> str;

        QString strMessage = "Server has sent - " + str + " to Port " + QString::number(nPort);
               // time.toString() + " " + "Server has sent - " + str + " to Port " + QString::number(this->nPort);

        //m_ptxt->append(strMessage);

        m_nNextBlockSize = 0;


















    //QString str("1L");
    QString str2;
    QByteArray array;

    QByteArray  arrBlock;
    QByteArray  CompressedBlock;

    QDataStream in(&CompressedBlock, QIODevice::WriteOnly);
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_3);
    in.setVersion(QDataStream::Qt_5_3);
    in.device()->seek(0);
    out.device()->seek(0);
    in << quint16(0) << str;

    QTcpSocket * socket = new QTcpSocket;
    socket->connectToHost("localhost", 6001);
    socket->write(CompressedBlock);
    pClientSocket->write(CompressedBlock);
   // socket->writeData(str, str.length());
    //QDataStream in(socket);

     quint16     m_nNextBlockSize=0;

    for (;;) {
        if (!m_nNextBlockSize) {
            if (pClientSocket->bytesAvailable() < (int)sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }
        qDebug()<<"m_nNextBlockSize "<<m_nNextBlockSize;

        if (socket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        in >> str2;
        m_nNextBlockSize = 0;

    }

















QString str3;
    out >> str3;

    QString DataAsString = QTextCodec::codecForMib(1014)->toUnicode(arrBlock);
    QString DataAsString1013 = QTextCodec::codecForMib(1015)->toUnicode(arrBlock);
    QString DataAsString1016 = QTextCodec::codecForMib(1013)->toUnicode(arrBlock);
    QString DataAsString106 = QTextCodec::codecForMib(106)->toUnicode(arrBlock);//++
    //QString qstr_test2 = QString::fromUtf8(((ushort *)arrBlock.data()));

   // QString qstr_test3 = QString::fromLocal8Bit(((ushort *)arrBlock.data()));

    QString qstr_test = QString::fromUtf16((ushort *)arrBlock.data());
    QString asd2 = QString::fromStdString(arrBlock.toStdString());//++
    QString asd3 = QString::fromStdString(arrBlock.data());
    QString asd=  QString::fromUtf16((ushort *)&arrBlock);

     QString asd4=   string_CSR(15,asd2);






    //str2 =



    // Перегоняем строку в массив байтов
    array.append(str);
    return a.exec();
}}

//int main(int argc, char *argv[])
//{

//    QCoreApplication a(argc, argv);




//    return a.exec();
//}
