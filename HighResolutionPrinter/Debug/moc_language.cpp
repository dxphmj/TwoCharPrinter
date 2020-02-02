/****************************************************************************
** Meta object code from reading C++ file 'language.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../language.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'language.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_language_t {
    QByteArrayData data[12];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_language_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_language_t qt_meta_stringdata_language = {
    {
QT_MOC_LITERAL(0, 0, 8), // "language"
QT_MOC_LITERAL(1, 9, 16), // "OKLanBut_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 24), // "lanEnglish_KBBut_clicked"
QT_MOC_LITERAL(4, 52, 24), // "LanChinese_KBBut_clicked"
QT_MOC_LITERAL(5, 77, 23), // "LanKorean_KBBut_clicked"
QT_MOC_LITERAL(6, 101, 25), // "LanJapanese_KBBut_clicked"
QT_MOC_LITERAL(7, 127, 22), // "LanCzech_KBBut_clicked"
QT_MOC_LITERAL(8, 150, 22), // "LanDutch_KBBut_clicked"
QT_MOC_LITERAL(9, 173, 23), // "LanGerman_KBBut_clicked"
QT_MOC_LITERAL(10, 197, 22), // "LanFarsi_KBBut_clicked"
QT_MOC_LITERAL(11, 220, 22) // "LanHindi_KBBut_clicked"

    },
    "language\0OKLanBut_clicked\0\0"
    "lanEnglish_KBBut_clicked\0"
    "LanChinese_KBBut_clicked\0"
    "LanKorean_KBBut_clicked\0"
    "LanJapanese_KBBut_clicked\0"
    "LanCzech_KBBut_clicked\0LanDutch_KBBut_clicked\0"
    "LanGerman_KBBut_clicked\0LanFarsi_KBBut_clicked\0"
    "LanHindi_KBBut_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_language[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void language::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        language *_t = static_cast<language *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OKLanBut_clicked(); break;
        case 1: _t->lanEnglish_KBBut_clicked(); break;
        case 2: _t->LanChinese_KBBut_clicked(); break;
        case 3: _t->LanKorean_KBBut_clicked(); break;
        case 4: _t->LanJapanese_KBBut_clicked(); break;
        case 5: _t->LanCzech_KBBut_clicked(); break;
        case 6: _t->LanDutch_KBBut_clicked(); break;
        case 7: _t->LanGerman_KBBut_clicked(); break;
        case 8: _t->LanFarsi_KBBut_clicked(); break;
        case 9: _t->LanHindi_KBBut_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject language::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_language.data,
      qt_meta_data_language,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *language::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *language::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_language.stringdata0))
        return static_cast<void*>(const_cast< language*>(this));
    return QWidget::qt_metacast(_clname);
}

int language::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
