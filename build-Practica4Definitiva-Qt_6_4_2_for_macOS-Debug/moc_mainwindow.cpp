/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Practica4Definitiva/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[31];
    char stringdata5[25];
    char stringdata6[13];
    char stringdata7[7];
    char stringdata8[9];
    char stringdata9[17];
    char stringdata10[8];
    char stringdata11[21];
    char stringdata12[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 20),  // "on_botonSuma_clicked"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 22),  // "on_botonEquals_clicked"
        QT_MOC_LITERAL(56, 30),  // "on_botonMultiplicacion_clicked"
        QT_MOC_LITERAL(87, 24),  // "on_botonDivision_clicked"
        QT_MOC_LITERAL(112, 12),  // "pasarBinario"
        QT_MOC_LITERAL(125, 6),  // "numero"
        QT_MOC_LITERAL(132, 8),  // "longitud"
        QT_MOC_LITERAL(141, 16),  // "pasarHexadecimal"
        QT_MOC_LITERAL(158, 7),  // "numIEEE"
        QT_MOC_LITERAL(166, 20),  // "MainWindow::floatNum"
        QT_MOC_LITERAL(187, 3)   // "var"
    },
    "MainWindow",
    "on_botonSuma_clicked",
    "",
    "on_botonEquals_clicked",
    "on_botonMultiplicacion_clicked",
    "on_botonDivision_clicked",
    "pasarBinario",
    "numero",
    "longitud",
    "pasarHexadecimal",
    "numIEEE",
    "MainWindow::floatNum",
    "var"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    2,   60,    2, 0x08,    5 /* Private */,
       9,    1,   65,    2, 0x08,    8 /* Private */,
      10,    1,   68,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::QString, QMetaType::Float,    7,
    QMetaType::QString, 0x80000000 | 11,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_botonSuma_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_botonEquals_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_botonMultiplicacion_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_botonDivision_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pasarBinario'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'pasarHexadecimal'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'numIEEE'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<MainWindow::floatNum, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_botonSuma_clicked(); break;
        case 1: _t->on_botonEquals_clicked(); break;
        case 2: _t->on_botonMultiplicacion_clicked(); break;
        case 3: _t->on_botonDivision_clicked(); break;
        case 4: { QString _r = _t->pasarBinario((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->pasarHexadecimal((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->numIEEE((*reinterpret_cast< std::add_pointer_t<MainWindow::floatNum>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
