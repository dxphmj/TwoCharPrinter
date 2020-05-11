/****************************************************************************
** Meta object code from reading C++ file 'filemanagechild.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../filemanagechild.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filemanagechild.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileManageChild_t {
    QByteArrayData data[17];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileManageChild_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileManageChild_t qt_meta_stringdata_FileManageChild = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FileManageChild"
QT_MOC_LITERAL(1, 16, 17), // "ShowLocalFilePath"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "PreviewLocalFile"
QT_MOC_LITERAL(4, 52, 17), // "SetButtonEnableOn"
QT_MOC_LITERAL(5, 70, 18), // "SetButtonEnableOff"
QT_MOC_LITERAL(6, 89, 8), // "slotShow"
QT_MOC_LITERAL(7, 98, 4), // "QDir"
QT_MOC_LITERAL(8, 103, 3), // "dir"
QT_MOC_LITERAL(9, 107, 23), // "loadSeleFileBut_clicked"
QT_MOC_LITERAL(10, 131, 23), // "editSeleFileBut_clicked"
QT_MOC_LITERAL(11, 155, 22), // "fileNmaeLineEdit_click"
QT_MOC_LITERAL(12, 178, 21), // "OKFileNameBut_clicked"
QT_MOC_LITERAL(13, 200, 22), // "delSeleFileBut_clicked"
QT_MOC_LITERAL(14, 223, 20), // "UdiskFileBut_clicked"
QT_MOC_LITERAL(15, 244, 25), // "copyFile2localBut_clicked"
QT_MOC_LITERAL(16, 270, 16) // "ScrollBarChanged"

    },
    "FileManageChild\0ShowLocalFilePath\0\0"
    "PreviewLocalFile\0SetButtonEnableOn\0"
    "SetButtonEnableOff\0slotShow\0QDir\0dir\0"
    "loadSeleFileBut_clicked\0editSeleFileBut_clicked\0"
    "fileNmaeLineEdit_click\0OKFileNameBut_clicked\0"
    "delSeleFileBut_clicked\0UdiskFileBut_clicked\0"
    "copyFile2localBut_clicked\0ScrollBarChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileManageChild[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    1,   83,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,
      15,    0,   92,    2, 0x0a /* Public */,
      16,    1,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void FileManageChild::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileManageChild *_t = static_cast<FileManageChild *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowLocalFilePath(); break;
        case 1: _t->PreviewLocalFile(); break;
        case 2: _t->SetButtonEnableOn(); break;
        case 3: _t->SetButtonEnableOff(); break;
        case 4: _t->slotShow((*reinterpret_cast< QDir(*)>(_a[1]))); break;
        case 5: _t->loadSeleFileBut_clicked(); break;
        case 6: _t->editSeleFileBut_clicked(); break;
        case 7: _t->fileNmaeLineEdit_click(); break;
        case 8: _t->OKFileNameBut_clicked(); break;
        case 9: _t->delSeleFileBut_clicked(); break;
        case 10: _t->UdiskFileBut_clicked(); break;
        case 11: _t->copyFile2localBut_clicked(); break;
        case 12: _t->ScrollBarChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject FileManageChild::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FileManageChild.data,
      qt_meta_data_FileManageChild,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FileManageChild::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileManageChild::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FileManageChild.stringdata0))
        return static_cast<void*>(const_cast< FileManageChild*>(this));
    return QWidget::qt_metacast(_clname);
}

int FileManageChild::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
