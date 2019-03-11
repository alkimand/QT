/****************************************************************************
** Meta object code from reading C++ file 'Calculation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Calculation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Calculation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calculation_t {
    QByteArrayData data[8];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculation_t qt_meta_stringdata_Calculation = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Calculation"
QT_MOC_LITERAL(1, 12, 17), // "inputValueChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "resultValueChanged"
QT_MOC_LITERAL(4, 50, 9), // "factorial"
QT_MOC_LITERAL(5, 60, 1), // "n"
QT_MOC_LITERAL(6, 62, 5), // "input"
QT_MOC_LITERAL(7, 68, 6) // "result"

    },
    "Calculation\0inputValueChanged\0\0"
    "resultValueChanged\0factorial\0n\0input\0"
    "result"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       2,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    1,   32,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    1,   35,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,

 // methods: parameters
    QMetaType::ULongLong, QMetaType::ULongLong,    5,

 // properties: name, type, flags
       6, QMetaType::ULongLong, 0x00495003,
       7, QMetaType::ULongLong, 0x00495001,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void Calculation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Calculation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inputValueChanged((*reinterpret_cast< qulonglong(*)>(_a[1]))); break;
        case 1: _t->resultValueChanged((*reinterpret_cast< qulonglong(*)>(_a[1]))); break;
        case 2: { qulonglong _r = _t->factorial((*reinterpret_cast< const qulonglong(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qulonglong*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Calculation::*)(qulonglong );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculation::inputValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Calculation::*)(qulonglong );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculation::resultValueChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Calculation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qulonglong*>(_v) = _t->inputValue(); break;
        case 1: *reinterpret_cast< qulonglong*>(_v) = _t->resultValue(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Calculation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setInputValue(*reinterpret_cast< qulonglong*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Calculation::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Calculation.data,
    qt_meta_data_Calculation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculation.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calculation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Calculation::inputValueChanged(qulonglong _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Calculation::resultValueChanged(qulonglong _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
