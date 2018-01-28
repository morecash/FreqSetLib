/****************************************************************************
** Meta object code from reading C++ file 'FreqsetsWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FreqsetsWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FreqsetsWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FreqsetsWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   16,   15,   15, 0x05,
     120,   57,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     187,   15,   15,   15, 0x08,
     215,   15,   15,   15, 0x08,
     246,   15,   15,   15, 0x08,
     289,  278,   15,   15, 0x08,
     313,   16,   15,   15, 0x08,
     338,  278,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FreqsetsWidget[] = {
    "FreqsetsWidget\0\0iIndex,dFreq\0"
    "TableSelectFreq(int,double)\0"
    "startFreq,sEndFreq,sFreqCount,sHopCycle,sLevel,sFreqSets,sUUID\0"
    "NetSignal(QString,QString,QString,QString,QString,QString,QString)\0"
    "on_pushButton_Add_clicked()\0"
    "on_pushButton_Delete_clicked()\0"
    "on_pushButton_InTable_clicked()\0"
    "row,column\0on_cellClicked(int,int)\0"
    "OnSelectFreq(int,double)\0"
    "on_AllFreqcellClicked(int,int)\0"
};

void FreqsetsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FreqsetsWidget *_t = static_cast<FreqsetsWidget *>(_o);
        switch (_id) {
        case 0: _t->TableSelectFreq((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->NetSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 2: _t->on_pushButton_Add_clicked(); break;
        case 3: _t->on_pushButton_Delete_clicked(); break;
        case 4: _t->on_pushButton_InTable_clicked(); break;
        case 5: _t->on_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->OnSelectFreq((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->on_AllFreqcellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FreqsetsWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FreqsetsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FreqsetsWidget,
      qt_meta_data_FreqsetsWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FreqsetsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FreqsetsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FreqsetsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FreqsetsWidget))
        return static_cast<void*>(const_cast< FreqsetsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int FreqsetsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FreqsetsWidget::TableSelectFreq(int _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FreqsetsWidget::NetSignal(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6, QString _t7)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
