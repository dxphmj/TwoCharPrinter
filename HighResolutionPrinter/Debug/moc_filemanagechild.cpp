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
    QByteArrayData data[9];
    char stringdata0[118];
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
QT_MOC_LITERAL(4, 52, 8), // "slotShow"
QT_MOC_LITERAL(5, 61, 4), // "QDir"
QT_MOC_LITERAL(6, 66, 3), // "dir"
QT_MOC_LITERAL(7, 70, 23), // "loadSeleFileBut_clicked"
QT_MOC_LITERAL(8, 94, 23) // "editSeleFileBut_clicked"

    },
    "FileManageChild\0ShowLocalFilePath\0\0"
    "PreviewLocalFile\0slotShow\0QDir\0dir\0"
    "loadSeleFileBut_clicked\0editSeleFileBut_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileManageChild[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,
       7,    0,   44,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,

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
        case 2: _t->slotShow((*reinterpret_cast< QDir(*)>(_a[1]))); break;
        case 3: _t->loadSeleFileBut_clicked(); break;
        case 4: _t->editSeleFileBut_clicked(); break;
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
