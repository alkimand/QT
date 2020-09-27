#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QPainter>
#include <QRgb>
#include <QImage>
#include <QMessageBox>
#include <QDebug>
//http://itnotesblog.ru/note.php?id=148

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    QPixmap puzzleImage;
    if (!puzzleImage.load("test.jpg")) {
        QMessageBox::warning(this, tr("Open Image"),
                             tr("The image file could not be loaded."),
                             QMessageBox::Close);
        return;
    }


    int size = qMin(puzzleImage.width(), puzzleImage.height());
    puzzleImage = puzzleImage.copy((puzzleImage.width() - size) / 2,
                                   (puzzleImage.height() - size) / 2, size, size).
                  scaled(600, 800, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);


    QPixmap pix1(QPixmap("puzle.png"));
    QImage pix1_image(pix1.size(), QImage::Format_RGB32 );//Format_Indexed8 Format_RGB32

    //  QImage image;

    //QPainter painter(&image);
    //painter.begin(this);

    // painter.setRenderHint(QPainter::Antialiasing); result_image pix1


    QImage template_image = pix1.toImage();//puzzleImage pix1
    int pixmap_height = template_image.height();
    int pixmap_width = template_image.width();

    //QImage result_image(template_image.size(), QImage::Format_ARGB32_Premultiplied  );//Format_Indexed8//= pix1.toImage();
    QImage result_image = pix1.toImage();;
        // (template_image.size(), QImage::Format_RGB32 );//Format_Indexed8
    QImage image(template_image.size(), QImage::Format_RGB32);



    QRgb value;

    QImage image_2 = puzzleImage.toImage();
    //image.load("puzle.png");
    //painter.end();

    QRgb b = template_image.pixel(18,18);
    QColor *c = new QColor;
    c->setRgb(b);
    // qDebug() << c->name();
    QColor transparent_color = QColor(0,0,0,255);
    //    qDebug()<< image.pixel(0,0);
    //    qDebug()<< image.pixel(18,18);
    //    qDebug()<< image.pixelColor(0,0);
    //    qDebug()<< image.pixelColor(18,18);
    //    qDebug()<< QColor(image.pixel(0,0));
    //    qDebug()<< QColor(image.pixel(18,18));


    //qDebug()<<transparent_color;
    QColor test1 = QColor(template_image.pixel(0,0));
    QColor test2 = QColor(0,0,0,255);
    // qDebug()<<test1;
    // qDebug()<<test2;

    //  if (test1 == test2)
    if (QColor(template_image.pixel(0,0))== transparent_color)
    {
        //qDebug()<< "in 0";
    }

    QPainter p(&pix1);
    p.setRenderHint(QPainter::Antialiasing);






    // while (point != pixmap_rect.bottomRight()) {
    for (int height = 0 ;height < pixmap_height ; ++height){
        uchar* line = result_image.scanLine(height);
        for (int width = 0 ;width < pixmap_width ; ++width) {
            QRgb srcImgPixel = image_2.pixel(width+50,height+50);//pix1 image_2 result_image
            QRgb* newPixel = reinterpret_cast< QRgb* >( line+ width*4);

           if (QColor(template_image.pixel(width,height))!= transparent_color)
            {
                //template_image image_2

                //QColor *c = new QColor;
                //c->setRgb(srcImgPixel);
                //() << c->name();

                ;//+ width+40 );
                //QRgb rgb(255,255,255,0);
                *newPixel =  srcImgPixel;
              // *newPixel = qRgb(189,149,39);
               // QColor qRgb(189,149,39);
               // result_image.setPixelColor(width, height, QColor(template_image.pixel(width,height)));


                //QRgb value;
               // value = qRgb(122, 163, 39); // 0xff7aa327
               // result_image.setPixelColor(width, height, QColor(template_image.pixel(width,height)));
               // value = qRgb(189, 149, 39);
                //result_image.setPixel(width, height, value); //++

               // image.setPixel(width, height, value); //++
                image.setPixelColor(width, height,  QColor(template_image.pixel(width,height)));//++

                //c->setRgb(*newPixel);
                //qDebug() << c->name();


                //result_image.setPixelColor(width,height,QColor(template_image.pixel(width,height)));
                //   result_pixmap.
                //                //qDebug()<< "in 0";
                // result_pixmap

                //  result_pixmap.drawPixmap(width,height,40,40,puzzleImage);
            }
           else{
              //  *newPixel =  srcImgPixel;
                //*newPixel = template_image.pixel(width,height);
                    //result_image.setPixelColor(width, height, QColor(template_image.pixel(width,height)));
            }
        }



    }
    // QPixmap::convertFromImage(result_image,)
    //result_pixmap.fromImage(result_image);


    //pix1.// создаём пустой QPixmap размером 100x100

    //img = img.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //p.drawPixmap(0,10,40,40,puzzleImage);
    // p.setRenderHint(QPainter::Antialiasing, false);

    //this->ui->setupUi(result_pixmap

    QPixmap test_2 = QPixmap::fromImage(template_image);

    QPixmap test_3 = QPixmap::fromImage(pix1_image);

    QPixmap test = QPixmap::fromImage(image);
    QPixmap result_pixmap = QPixmap::fromImage(result_image);

    ui->label->setPixmap(result_pixmap); //result_pixmap //test test_2 //pix1
    ui->label_2->setPixmap(result_pixmap);

    p.end();

}

MainWindow::~MainWindow()
{
    delete ui;
}

