/****************************************************************************
** Meta object code from reading C++ file 'MySocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MySocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MySocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MySocket_t {
    QByteArrayData data[14];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MySocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MySocket_t qt_meta_stringdata_MySocket = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MySocket"
QT_MOC_LITERAL(1, 9, 10), // "removePort"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "port"
QT_MOC_LITERAL(4, 26, 9), // "TreadStop"
QT_MOC_LITERAL(5, 36, 7), // "TextAdd"
QT_MOC_LITERAL(6, 44, 13), // "slotReadyRead"
QT_MOC_LITERAL(7, 58, 9), // "slotError"
QT_MOC_LITERAL(8, 68, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 97, 16), // "slotSendToClient"
QT_MOC_LITERAL(10, 114, 13), // "slotConnected"
QT_MOC_LITERAL(11, 128, 10), // "stopThread"
QT_MOC_LITERAL(12, 139, 10), // "setneedZip"
QT_MOC_LITERAL(13, 150, 11) // "setneedCode"

    },
    "MySocket\0removePort\0\0port\0TreadStop\0"
    "TextAdd\0slotReadyRead\0slotError\0"
    "QAbstractSocket::SocketError\0"
    "slotSendToClient\0slotConnected\0"
    "stopThread\0setneedZip\0setneedCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MySocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    1,   79,    2, 0x08 /* Private */,
      12,    1,   82,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MySocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MySocket *_t = static_cast<MySocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removePort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->TreadStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->TextAdd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotReadyRead(); break;
        case 4: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->slotSendToClient(); break;
        case 6: _t->slotConnected(); break;
        case 7: _t->stopThread((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setneedZip((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setneedCode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MySocket::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MySocket::removePort)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MySocket::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MySocket::TreadStop)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MySocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MySocket::TextAdd)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MySocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_MySocket.data,
      qt_meta_data_MySocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MySocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MySocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MySocket.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int MySocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MySocket::removePort(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MySocket::TreadStop(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MySocket::TextAdd(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
