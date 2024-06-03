/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[40];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 15), // "signalAuthError"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 13), // "slotReadyRead"
QT_MOC_LITERAL(42, 16), // "slotAuthComplete"
QT_MOC_LITERAL(59, 8), // "userinfo"
QT_MOC_LITERAL(68, 17), // "cancelGroupCreate"
QT_MOC_LITERAL(86, 15), // "nextGroupCreate"
QT_MOC_LITERAL(102, 9), // "groupName"
QT_MOC_LITERAL(112, 13), // "slotCancelAdd"
QT_MOC_LITERAL(126, 11), // "slotAddUser"
QT_MOC_LITERAL(138, 5), // "users"
QT_MOC_LITERAL(144, 26), // "on_mess_edit_returnPressed"
QT_MOC_LITERAL(171, 23), // "slotDialogButtonClicked"
QT_MOC_LITERAL(195, 25), // "on_searchLine_textChanged"
QT_MOC_LITERAL(221, 4), // "arg1"
QT_MOC_LITERAL(226, 21), // "on_menuButton_clicked"
QT_MOC_LITERAL(248, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(270, 26), // "on_groupChatButton_clicked"
QT_MOC_LITERAL(297, 24) // "on_adduserButton_clicked"

    },
    "MainWindow\0signalAuthError\0\0slotReadyRead\0"
    "slotAuthComplete\0userinfo\0cancelGroupCreate\0"
    "nextGroupCreate\0groupName\0slotCancelAdd\0"
    "slotAddUser\0users\0on_mess_edit_returnPressed\0"
    "slotDialogButtonClicked\0"
    "on_searchLine_textChanged\0arg1\0"
    "on_menuButton_clicked\0on_pushButton_clicked\0"
    "on_groupChatButton_clicked\0"
    "on_adduserButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   99,    2, 0x0a,    2 /* Public */,
       4,    1,  100,    2, 0x0a,    3 /* Public */,
       6,    0,  103,    2, 0x0a,    5 /* Public */,
       7,    1,  104,    2, 0x0a,    6 /* Public */,
       9,    0,  107,    2, 0x0a,    8 /* Public */,
      10,    1,  108,    2, 0x0a,    9 /* Public */,
      12,    0,  111,    2, 0x08,   11 /* Private */,
      13,    0,  112,    2, 0x08,   12 /* Private */,
      14,    1,  113,    2, 0x08,   13 /* Private */,
      16,    0,  116,    2, 0x08,   15 /* Private */,
      17,    0,  117,    2, 0x08,   16 /* Private */,
      18,    0,  118,    2, 0x08,   17 /* Private */,
      19,    0,  119,    2, 0x08,   18 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalAuthError(); break;
        case 1: _t->slotReadyRead(); break;
        case 2: _t->slotAuthComplete((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 3: _t->cancelGroupCreate(); break;
        case 4: _t->nextGroupCreate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->slotCancelAdd(); break;
        case 6: _t->slotAddUser((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 7: _t->on_mess_edit_returnPressed(); break;
        case 8: _t->slotDialogButtonClicked(); break;
        case 9: _t->on_searchLine_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->on_menuButton_clicked(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->on_groupChatButton_clicked(); break;
        case 13: _t->on_adduserButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalAuthError)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalAuthError()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
