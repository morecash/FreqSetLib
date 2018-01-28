/****************************************************************************
** Meta object code from reading C++ file 'testnetshow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testnetshow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testnetshow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestNetShow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      21,   12,   12,   12, 0x08,
      97,   34,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestNetShow[] = {
    "TestNetShow\0\0onAdd()\0onSpaceAct()\0"
    "startFreq,sEndFreq,sFreqCount,sHopCycle,sLevel,sFreqSets,sUUID\0"
    "OnNetSignal(QString,QString,QString,QString,QString,QString,QString)\0"
};

void TestNetShow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TestNetShow *_t = static_cast<TestNetShow *>(_o);
        switch (_id) {
        case 0: _t->onAdd(); break;
        case 1: _t->onSpaceAct(); break;
        case 2: _t->OnNetSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TestNetShow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TestNetShow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestNetShow,
      qt_meta_data_TestNetShow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestNetShow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestNetShow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestNetShow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestNetShow))
        return static_cast<void*>(const_cast< TestNetShow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TestNetShow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
