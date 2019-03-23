/****************************************************************************
** Meta object code from reading C++ file 'clientbase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/C++code/Server/Client/Clients/clientbase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientBase_t {
    QByteArrayData data[14];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientBase_t qt_meta_stringdata_ClientBase = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ClientBase"
QT_MOC_LITERAL(1, 11, 21), // "documentTittleChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 17), // "proxiModelChanged"
QT_MOC_LITERAL(4, 52, 10), // "saveAsSlot"
QT_MOC_LITERAL(5, 63, 8), // "saveSlot"
QT_MOC_LITERAL(6, 72, 9), // "setStatus"
QT_MOC_LITERAL(7, 82, 13), // "clearDataPool"
QT_MOC_LITERAL(8, 96, 18), // "openInExplorerSlot"
QT_MOC_LITERAL(9, 115, 17), // "filterChangedSlot"
QT_MOC_LITERAL(10, 133, 19), // "setNameDocumentSlot"
QT_MOC_LITERAL(11, 153, 14), // "documentTittle"
QT_MOC_LITERAL(12, 168, 10), // "proximodel"
QT_MOC_LITERAL(13, 179, 21) // "ProxiModelServiseUDP*"

    },
    "ClientBase\0documentTittleChanged\0\0"
    "proxiModelChanged\0saveAsSlot\0saveSlot\0"
    "setStatus\0clearDataPool\0openInExplorerSlot\0"
    "filterChangedSlot\0setNameDocumentSlot\0"
    "documentTittle\0proximodel\0"
    "ProxiModelServiseUDP*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    1,   63,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
       8,    0,   67,    2, 0x0a /* Public */,
       9,    2,   68,    2, 0x0a /* Public */,
      10,    1,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // properties: name, type, flags
      11, QMetaType::QString, 0x00495103,
      12, 0x80000000 | 13, 0x0049500b,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void ClientBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->documentTittleChanged(); break;
        case 1: _t->proxiModelChanged(); break;
        case 2: _t->saveAsSlot(); break;
        case 3: _t->saveSlot(); break;
        case 4: _t->setStatus((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->clearDataPool(); break;
        case 6: _t->openInExplorerSlot(); break;
        case 7: _t->filterChangedSlot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->setNameDocumentSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientBase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientBase::documentTittleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientBase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientBase::proxiModelChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ProxiModelServiseUDP* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ClientBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->readDocumentTittle(); break;
        case 1: *reinterpret_cast< ProxiModelServiseUDP**>(_v) = _t->readproxiModel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ClientBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDocumentTittle(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setproximodel(*reinterpret_cast< ProxiModelServiseUDP**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ClientBase::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ClientBase.data,
    qt_meta_data_ClientBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClientBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClientBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
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
void ClientBase::documentTittleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ClientBase::proxiModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
