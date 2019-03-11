#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDebug>
#include <QtNetwork>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);

signals:
    void onReady();

public slots:
    void getData();     // Метод инициализации запроса на получение данных
    void onResult(QNetworkReply *reply);    // Сохранение страницы - для подтверждения наличия байтов ответа
    void setPass(); //отправка поста с данными
private:
    //QNetworkAccessManager *manager;
    QNetworkAccessManager *manager; // менеджер сетевого доступа
    QNetworkRequest *request;
    QUrl url;
    QNetworkReply *reply;
    QString Str_url;
};

#endif // DOWNLOADER_H
