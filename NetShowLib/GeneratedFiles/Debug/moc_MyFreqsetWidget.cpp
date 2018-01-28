/****************************************************************************
** Meta object code from reading C++ file 'MyFreqsetWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyFreqsetWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyFreqsetWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyFreqsetWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyFreqsetWidget[] = {
    "MyFreqsetWidget\0\0iIndex,dFreq\0"
    "SelectFreq(int,double)\0"
    "on_TableSelectFreq(int,double)\0"
};

void MyFreqsetWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyFreqsetWidget *_t = static_cast<MyFreqsetWidget *>(_o);
        switch (_id) {
        case 0: _t->SelectFreq((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->on_TableSelectFreq((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyFreqsetWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyFreqsetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyFreqsetWidget,
      qt_meta_data_MyFreqsetWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyFreqsetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyFreqsetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyFreqsetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyFreqsetWidget))
        return static_cast<void*>(const_cast< MyFreqsetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyFreqsetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MyFreqsetWidget::SelectFreq(int _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
