// ======================================================================
//  test.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.3 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2014 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook : http://www.facebook.com/mschlee
//  Twitter  : http://twitter.com/Max_Schlee
//  2Look.me : http://2look.me/NW100003
//  Xing     : http://www.xing.com/profile/Max_Schlee
//  vk.com   : https://vk.com/max.schlee
// ======================================================================

#include <QtTest>
#include "MyClass.h"

// ======================================================================
class Test_MyClass : public QObject {
Q_OBJECT
private slots:
    void min_data();
    void max_data();

    void min();
    void max();
};

// ----------------------------------------------------------------------
void Test_MyClass::min_data()
{
    QTest::addColumn<int>("arg1");
    QTest::addColumn<int>("arg2");
    QTest::addColumn<int>("result");

    QTest::newRow("min_test1") << 25 << 0 << 0;
    QTest::newRow("min_test2") << -12 << -5 << -12;
    QTest::newRow("min_test3") << 2007 << 2007 << 2007;
    QTest::newRow("min_test4") << -12 << 5 << -12;
}

// ----------------------------------------------------------------------
void Test_MyClass::max_data()
{
    QTest::addColumn<int>("arg1");
    QTest::addColumn<int>("arg2");
    QTest::addColumn<int>("result");

    QTest::newRow("max_test1") << 25 << 0 << 25;
    QTest::newRow("max_test2") << -12 << -5 << -5;
    QTest::newRow("max_test3") << 2007 << 2007 << 2007;
    QTest::newRow("max_test4") << -12 << 5 << 5;
}

// ----------------------------------------------------------------------
void Test_MyClass::min()
{
    MyClass myClass;
    QFETCH(int, arg1);
    QFETCH(int, arg2);
    QFETCH(int, result);

    QCOMPARE(myClass.min(arg1, arg2), result);
}

// ----------------------------------------------------------------------
void Test_MyClass::max()
{
    MyClass myClass;
    QFETCH(int, arg1);
    QFETCH(int, arg2);
    QFETCH(int, result);

    QCOMPARE(myClass.max(arg1, arg2), result);
}

QTEST_MAIN(Test_MyClass)
#include "test.moc"
