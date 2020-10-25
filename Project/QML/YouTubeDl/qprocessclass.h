#ifndef QPROCESSCLASS_H
#define QPROCESSCLASS_H

#include <QObject>
#include <QProcess>
#include <QTextStream>
#include <QByteArray>
#include <QTextCodec>




class QProcessClass : public QObject
{
    Q_OBJECT
public:
    explicit QProcessClass(QObject *parent = nullptr);

signals:

};

#endif // QPROCESSCLASS_H
