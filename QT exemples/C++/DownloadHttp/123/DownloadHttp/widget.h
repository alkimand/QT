#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>

#include <downloader.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals :
    void loadFinish();

private slots:
    void readFile();
    void readFileAfterSendPas();

private:
    Ui::Widget *ui;
    Downloader *downloader; // Объявляем объект класса для скачивания данных по http
};

#endif // WIDGET_H
