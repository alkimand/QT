#include "downloader.h"
#include <QDebug>
#include <QAuthenticator>
#include <QNetworkReply>
#include <QNetworkRequest>

Downloader::Downloader(QObject *parent) : QObject(parent)
{

  // Str_url = "https://mail.ru";
   //Str_url ="https://www.google.ru";
   //Str_url = "https://accounts.google.com/signin/v2/identifier?hl=ru&passive=true&continue=https%3A%2F%2Fwww.google.ru%2F&flowName=GlifWebSignIn&flowEntry=ServiceLogin";
   //Str_url = "http://www.cyberforum.ru/login.php";
   Str_url = "http://online-red.com/radio/dinamitnn.html";
   QUrl url(Str_url);
     //QUrl url("https://e.mail.ru/messages/inbox/?back=1");
     //this->url.setUrl("https://e.mail.ru/messages/inbox/?back=1",QUrl::TolerantMode);
    //this->url.setUrl("http://greentalk.ru/blogs/entry/682-%D1%83%D0%BC%D0%BD%D0%B0%D1%8F-%D1%82%D0%B5%D0%BF%D0%BB%D0%B8%D1%86%D0%B0-%D1%80%D0%B0%D0%B7%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%BA%D0%B0-%D0%BD%D0%B0%D1%80%D0%BE%D0%B4%D0%BD%D0%BE%D0%B3%D0%BE-%D0%BA%D0%BE%D0%BD%D1%82%D1%80%D0%BE%D0%BB%D0%BB%D0%B5%D1%80%D0%B0-%D0%BD%D0%B0-%D0%B1%D0%B0%D0%B7%D0%B5-raspberry-pi/",QUrl::TolerantMode);

    // Инициализируем менеджер ...
    manager = new QNetworkAccessManager();
    this->request = new QNetworkRequest;
    request->setUrl(url);
    // ... и подключаем сигнал о завершении получения данных к обработчику полученного ответа
    connect(manager, &QNetworkAccessManager::finished, this, &Downloader::onResult);

}
//SIGNAL(onResult(QNetworkReply *)));
void Downloader::getData()
{
    //QUrl url("http://www.mtbank.by/currxml.php"); // URL, к которому будем получать данные
    //QUrl url("https://gitlab.com/users/sign_in");
    //QUrl url("https://gitlab.com/Sergey_Timofeev");
    //QUrl url("https://e.mail.ru/messages/inbox/?back=1");
    //url.setUserName("alkimand@mail.ru");
    //url.setPassword("qwertyop");


//    url.setUserName("stimofey@mera.ru");
//    url.setPassword("qwertyop");
        // Отправляемый запрос
          // Устанавлвиваем URL в запрос
    this->manager->get(*request);      // Выполняем запрос


    qDebug () << "Downloader::getData()";
}

void Downloader::onResult(QNetworkReply *reply)
{
    qDebug () << "Downloader::onResult";

    // Если в процесе получения данных произошла ошибка
    if(reply->error()){
        // Сообщаем об этом и показываем информацию об ошибках
        qDebug() << "ERROR";
        qDebug() << reply->errorString();
    } else {
        //this->setPass();


        // В противном случае создаём объект для работы с файлом
        QFile *file = new QFile("C:/example/file.xml");
        // Создаём файл или открываем его на перезапись ...
        if(file->open(QFile::WriteOnly)){
            file->write(reply->readAll());  // ... и записываем всю информацию со страницы в файл
            file->close();                  // закрываем файл
        qDebug() << "Downloading is completed";
        emit onReady(); // Посылаем сигнал о завершении получения файла
        }
    }
}

void Downloader::setPass()
{
   // http://www.cyberforum.ru/qt/thread1022642.html
    //http://www.cyberforum.ru/qt/thread843094.html
    //http://easy-qt.blogspot.com/2016/07/get-post-qt-542-qt-57.html
    //https://stackoverflow.com/questions/1512849/basic-authentication-with-qt-qnetworkaccessmanager
    qDebug () << "Downloader::setPass";


     //this->reply = new QNetworkReply();
    //QAuthenticator *authenticator = new QAuthenticator;
    //qDebug () << "authenticator";
    //qDebug () <<authenticator->realm();
    QByteArray postDataByteArray;// = variantMapToJson(data);
    QByteArray postData;
    QString userName = "alkimand@mail.ru";
    QString password = "qwertyop";

    /*postData+= "&vb_login_username=" +  QUrl::toPercentEncoding( userName.toUtf8() );
    postData+= "&cookieuser=1";
    postData+= "&vb_login_password="+  QUrl::toPercentEncoding( password.toUtf8() );
    postData+= "&s=&securitytoken=guest";
    postData+= "&do=login";
    postData+= "&vb_login_md5password=";
    postData+= "&vb_login_md5password_utf=";*/

    postData+= "&login=" +  QUrl::toPercentEncoding( userName.toUtf8() );
    postData+= "&cookieuser=1";
    postData+= "&password=" +  QUrl::toPercentEncoding( password.toUtf8() );
    postData+= "&s=&securitytoken=guest";
    postData+= "&do=login";
    postData+= "&vb_login_md5password=";
    postData+= "&vb_login_md5password_utf=";



    QNetworkRequest Newrequest(this->Str_url); //our server with php-script
    Newrequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    Newrequest.setRawHeader("Accept-Encoding","identity");

    qDebug () << "Downloader::setPass::manager->post(Newrequest,postData)";
    QNetworkReply *reply3 = this->manager->post(Newrequest,postData);



    //this->request->setRawHeader()

    //manager->get(*request);
    //QNetworkReply *reply2;
   // manager->get(*request);
//manager->post(reply,postDataByteArray);
    //reply2 = this->manager->post(reply2, postDataByteArray);

    //this->request = new QNetworkRequest;
   // request->setUrl(url);
    //reply = manager->get(*request);


  // manager2->post(request, postDataByteArray);
   // QString username("alkimand");
   // QString password("qwertyop");


//    QString concatenated = username + ":" + password;
//    QByteArray data = concatenated.toLocal8Bit().toBase64();
//    QString headerData = "Basic " + data;
     //request->setRawHeader("Authorization", headerData.toLocal8Bit());





}

