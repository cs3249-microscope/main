/****************************************************************************
** Meta object code from reading C++ file 'PreviewViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Code/PreviewViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PreviewViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PreviewViewer_t {
    QByteArrayData data[8];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PreviewViewer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PreviewViewer_t qt_meta_stringdata_PreviewViewer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PreviewViewer"
QT_MOC_LITERAL(1, 14, 14), // "changeExposure"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "sharpen"
QT_MOC_LITERAL(4, 38, 7), // "magnify"
QT_MOC_LITERAL(5, 46, 8), // "wBalance"
QT_MOC_LITERAL(6, 55, 13), // "openPastScans"
QT_MOC_LITERAL(7, 69, 12) // "startPreview"

    },
    "PreviewViewer\0changeExposure\0\0sharpen\0"
    "magnify\0wBalance\0openPastScans\0"
    "startPreview"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreviewViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PreviewViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PreviewViewer *_t = static_cast<PreviewViewer *>(_o);
        switch (_id) {
        case 0: _t->changeExposure(); break;
        case 1: _t->sharpen(); break;
        case 2: _t->magnify(); break;
        case 3: _t->wBalance(); break;
        case 4: _t->openPastScans(); break;
        case 5: _t->startPreview(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PreviewViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PreviewViewer.data,
      qt_meta_data_PreviewViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PreviewViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreviewViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PreviewViewer.stringdata))
        return static_cast<void*>(const_cast< PreviewViewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PreviewViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
