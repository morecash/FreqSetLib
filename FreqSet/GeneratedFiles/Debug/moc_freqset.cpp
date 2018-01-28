/****************************************************************************
** Meta object code from reading C++ file 'freqset.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../freqset.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'freqset.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FreqSet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      17,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FreqSet[] = {
    "FreqSet\0\0onAdd()\0onSpaceAct()\0"
};

void FreqSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FreqSet *_t = static_cast<FreqSet *>(_o);
        switch (_id) {
        case 0: _t->onAdd(); break;
        case 1: _t->onSpaceAct(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FreqSet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FreqSet::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FreqSet,
      qt_meta_data_FreqSet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FreqSet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FreqSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FreqSet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FreqSet))
        return static_cast<void*>(const_cast< FreqSet*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FreqSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
