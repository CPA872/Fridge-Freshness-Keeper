/****************************************************************************
** Meta object code from reading C++ file 'newitemwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newitemwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newitemwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewItemWindow_t {
    QByteArrayData data[16];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewItemWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewItemWindow_t qt_meta_stringdata_NewItemWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NewItemWindow"
QT_MOC_LITERAL(1, 14, 11), // "sendNewItem"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "FoodItem*"
QT_MOC_LITERAL(4, 37, 7), // "newItem"
QT_MOC_LITERAL(5, 45, 31), // "on_shelfLifeBox_editingFinished"
QT_MOC_LITERAL(6, 77, 28), // "on_shelfLifeBox_valueChanged"
QT_MOC_LITERAL(7, 106, 4), // "arg1"
QT_MOC_LITERAL(8, 111, 33), // "on_expirationDateEdit_dateCha..."
QT_MOC_LITERAL(9, 145, 4), // "date"
QT_MOC_LITERAL(10, 150, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(11, 174, 24), // "on_confirmButton_clicked"
QT_MOC_LITERAL(12, 199, 25), // "on_countAddButton_clicked"
QT_MOC_LITERAL(13, 225, 27), // "on_countMinusButton_clicked"
QT_MOC_LITERAL(14, 253, 29), // "on_shelfLifeAddbutton_clicked"
QT_MOC_LITERAL(15, 283, 31) // "on_shelfLifeMinusButton_clicked"

    },
    "NewItemWindow\0sendNewItem\0\0FoodItem*\0"
    "newItem\0on_shelfLifeBox_editingFinished\0"
    "on_shelfLifeBox_valueChanged\0arg1\0"
    "on_expirationDateEdit_dateChanged\0"
    "date\0on_cancelButton_clicked\0"
    "on_confirmButton_clicked\0"
    "on_countAddButton_clicked\0"
    "on_countMinusButton_clicked\0"
    "on_shelfLifeAddbutton_clicked\0"
    "on_shelfLifeMinusButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewItemWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   67,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
      10,    0,   74,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,
      14,    0,   78,    2, 0x08 /* Private */,
      15,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QDate,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewItemWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewItemWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendNewItem((*reinterpret_cast< FoodItem*(*)>(_a[1]))); break;
        case 1: _t->on_shelfLifeBox_editingFinished(); break;
        case 2: _t->on_shelfLifeBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_expirationDateEdit_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 4: _t->on_cancelButton_clicked(); break;
        case 5: _t->on_confirmButton_clicked(); break;
        case 6: _t->on_countAddButton_clicked(); break;
        case 7: _t->on_countMinusButton_clicked(); break;
        case 8: _t->on_shelfLifeAddbutton_clicked(); break;
        case 9: _t->on_shelfLifeMinusButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NewItemWindow::*)(FoodItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NewItemWindow::sendNewItem)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NewItemWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_NewItemWindow.data,
    qt_meta_data_NewItemWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NewItemWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewItemWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewItemWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int NewItemWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void NewItemWindow::sendNewItem(FoodItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
