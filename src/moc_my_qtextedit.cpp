/****************************************************************************
** Meta object code from reading C++ file 'my_qtextedit.h'
**
** Created: Tue Mar 13 18:00:53 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "my_qtextedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_qtextedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_my_qtextedit[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_my_qtextedit[] = {
    "my_qtextedit\0\0my_resize()\0"
};

const QMetaObject my_qtextedit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_my_qtextedit,
      qt_meta_data_my_qtextedit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &my_qtextedit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *my_qtextedit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *my_qtextedit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_my_qtextedit))
        return static_cast<void*>(const_cast< my_qtextedit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int my_qtextedit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: my_resize(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void my_qtextedit::my_resize()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
