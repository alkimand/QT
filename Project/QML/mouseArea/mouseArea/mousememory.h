#ifndef MOUSEMEMORY_H
#define MOUSEMEMORY_H

#include <QObject>
#include <QDebug>
#include <QPoint>

class MouseMemory : public QObject
{
    Q_OBJECT
public:
    explicit MouseMemory(QObject *parent = nullptr);

    Q_INVOKABLE void test();

signals:

public slots:
};

#endif // MOUSEMEMORY_H
