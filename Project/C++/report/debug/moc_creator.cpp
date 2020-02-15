/****************************************************************************
** Meta object code from reading C++ file 'creator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../creator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'creator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Creator_t {
    QByteArrayData data[21];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Creator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Creator_t qt_meta_stringdata_Creator = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Creator"
QT_MOC_LITERAL(1, 8, 14), // "addNewResponse"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "date"
QT_MOC_LITERAL(4, 29, 7), // "setDate"
QT_MOC_LITERAL(5, 37, 13), // "setupDateList"
QT_MOC_LITERAL(6, 51, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(7, 73, 10), // "selectDate"
QT_MOC_LITERAL(8, 84, 17), // "clearwidgetSignal"
QT_MOC_LITERAL(9, 102, 12), // "CpathChanges"
QT_MOC_LITERAL(10, 115, 20), // "CNewpushButtonCliked"
QT_MOC_LITERAL(11, 136, 20), // "CDelpushButtonCliked"
QT_MOC_LITERAL(12, 157, 9), // "CSaveFile"
QT_MOC_LITERAL(13, 167, 12), // "setLCDNumber"
QT_MOC_LITERAL(14, 180, 21), // "CDellpushButtonCliked"
QT_MOC_LITERAL(15, 202, 21), // "CSavepushButtonCliked"
QT_MOC_LITERAL(16, 224, 11), // "CSelectDate"
QT_MOC_LITERAL(17, 236, 15), // "pathChangesSlot"
QT_MOC_LITERAL(18, 252, 23), // "CTextEditWorkerLoadFile"
QT_MOC_LITERAL(19, 276, 9), // "debugSlot"
QT_MOC_LITERAL(20, 286, 10) // "debugSlot2"

    },
    "Creator\0addNewResponse\0\0date\0setDate\0"
    "setupDateList\0QMap<QString,QString>\0"
    "selectDate\0clearwidgetSignal\0CpathChanges\0"
    "CNewpushButtonCliked\0CDelpushButtonCliked\0"
    "CSaveFile\0setLCDNumber\0CDellpushButtonCliked\0"
    "CSavepushButtonCliked\0CSelectDate\0"
    "pathChangesSlot\0CTextEditWorkerLoadFile\0"
    "debugSlot\0debugSlot2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Creator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    1,  112,    2, 0x06 /* Public */,
       5,    1,  115,    2, 0x06 /* Public */,
       7,    1,  118,    2, 0x06 /* Public */,
       8,    0,  121,    2, 0x06 /* Public */,
       9,    1,  122,    2, 0x06 /* Public */,
      10,    1,  125,    2, 0x06 /* Public */,
      11,    1,  128,    2, 0x06 /* Public */,
      12,    1,  131,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  134,    2, 0x08 /* Private */,
      10,    1,  137,    2, 0x08 /* Private */,
      14,    1,  140,    2, 0x08 /* Private */,
      15,    1,  143,    2, 0x08 /* Private */,
      16,    1,  146,    2, 0x08 /* Private */,
      17,    1,  149,    2, 0x08 /* Private */,
      17,    1,  152,    2, 0x08 /* Private */,
      18,    0,  155,    2, 0x08 /* Private */,
      19,    0,  156,    2, 0x08 /* Private */,
      20,    0,  157,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QDate,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Creator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Creator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addNewResponse((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 1: _t->setDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: _t->setupDateList((*reinterpret_cast< const QMap<QString,QString>(*)>(_a[1]))); break;
        case 3: _t->selectDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 4: _t->clearwidgetSignal(); break;
        case 5: _t->CpathChanges((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->CNewpushButtonCliked((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 7: _t->CDelpushButtonCliked((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 8: _t->CSaveFile((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 9: _t->setLCDNumber((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 10: _t->CNewpushButtonCliked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->CDellpushButtonCliked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->CSavepushButtonCliked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->CSelectDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 14: _t->pathChangesSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->pathChangesSlot((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 16: _t->CTextEditWorkerLoadFile(); break;
        case 17: _t->debugSlot(); break;
        case 18: _t->debugSlot2(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Creator::*)(QDate );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Creator::addNewResponse)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Creator::*)(const QDate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Creator::setDate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Creator::*)(const QMap<QString,QString> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Creator::setupDateList)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Creator::*)(const QDate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Creator::selectDate)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Creator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Creator::clearwidgetSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Creator::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Creator::CpathChanges)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Creator::*)(const QDate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Creator::CNewpushButtonCliked)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Creator::*)(const QDate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Creator::CDelpushButtonCliked)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Creator::*)(const QDate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Creator::CSaveFile)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Creator::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Creator.data,
    qt_meta_data_Creator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Creator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Creator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Creator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Creator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Creator::addNewResponse(QDate _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Creator::setDate(const QDate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Creator::setupDateList(const QMap<QString,QString> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Creator::selectDate(const QDate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Creator::clearwidgetSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Creator::CpathChanges(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Creator::CNewpushButtonCliked(const QDate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Creator::CDelpushButtonCliked(const QDate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Creator::CSaveFile(const QDate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
