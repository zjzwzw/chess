/****************************************************************************
** Meta object code from reading C++ file 'showpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../showpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_showpage_t {
    QByteArrayData data[10];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_showpage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_showpage_t qt_meta_stringdata_showpage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "showpage"
QT_MOC_LITERAL(1, 9, 9), // "showmain1"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "showmain0"
QT_MOC_LITERAL(4, 30, 10), // "showmain_1"
QT_MOC_LITERAL(5, 41, 14), // "on_pvp_clicked"
QT_MOC_LITERAL(6, 56, 14), // "on_pve_clicked"
QT_MOC_LITERAL(7, 71, 6), // "reshow"
QT_MOC_LITERAL(8, 78, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 100, 14) // "on_eve_clicked"

    },
    "showpage\0showmain1\0\0showmain0\0showmain_1\0"
    "on_pvp_clicked\0on_pve_clicked\0reshow\0"
    "on_pushButton_clicked\0on_eve_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_showpage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void showpage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        showpage *_t = static_cast<showpage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showmain1(); break;
        case 1: _t->showmain0(); break;
        case 2: _t->showmain_1(); break;
        case 3: _t->on_pvp_clicked(); break;
        case 4: _t->on_pve_clicked(); break;
        case 5: _t->reshow(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_eve_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (showpage::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showpage::showmain1)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (showpage::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showpage::showmain0)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (showpage::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showpage::showmain_1)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject showpage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_showpage.data,
      qt_meta_data_showpage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *showpage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showpage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_showpage.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int showpage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void showpage::showmain1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void showpage::showmain0()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void showpage::showmain_1()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
