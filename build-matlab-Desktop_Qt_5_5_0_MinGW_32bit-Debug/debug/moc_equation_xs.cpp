/****************************************************************************
** Meta object code from reading C++ file 'equation_xs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../matlab/equation_xs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'equation_xs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_equation_xs_t {
    QByteArrayData data[5];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_equation_xs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_equation_xs_t qt_meta_stringdata_equation_xs = {
    {
QT_MOC_LITERAL(0, 0, 11), // "equation_xs"
QT_MOC_LITERAL(1, 12, 9), // "setAnswer"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "answer"
QT_MOC_LITERAL(4, 30, 14) // "equation_slots"

    },
    "equation_xs\0setAnswer\0\0answer\0"
    "equation_slots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_equation_xs[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void equation_xs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        equation_xs *_t = static_cast<equation_xs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setAnswer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->equation_slots(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (equation_xs::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&equation_xs::setAnswer)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject equation_xs::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_equation_xs.data,
      qt_meta_data_equation_xs,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *equation_xs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *equation_xs::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_equation_xs.stringdata0))
        return static_cast<void*>(const_cast< equation_xs*>(this));
    return QWidget::qt_metacast(_clname);
}

int equation_xs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void equation_xs::setAnswer(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
