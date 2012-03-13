/****************************************************************************
** Meta object code from reading C++ file 'main_widget.h'
**
** Created: Tue Mar 13 18:00:48 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_main_widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      24,   12,   12,   12, 0x0a,
      37,   12,   12,   12, 0x0a,
      49,   12,   12,   12, 0x0a,
      66,   12,   12,   12, 0x0a,
      82,   12,   12,   12, 0x0a,
      95,   93,   12,   12, 0x0a,
     109,   12,   12,   12, 0x0a,
     126,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_main_widget[] = {
    "main_widget\0\0resize_s()\0push_right()\0"
    "push_left()\0mark_selection()\0"
    "open_new_file()\0set_font()\0i\0set_page(int)\0"
    "set_background()\0save_label()\0"
};

const QMetaObject main_widget::staticMetaObject = {
    { &QWorkspace::staticMetaObject, qt_meta_stringdata_main_widget,
      qt_meta_data_main_widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &main_widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *main_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *main_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_main_widget))
        return static_cast<void*>(const_cast< main_widget*>(this));
    return QWorkspace::qt_metacast(_clname);
}

int main_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWorkspace::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: resize_s(); break;
        case 1: push_right(); break;
        case 2: push_left(); break;
        case 3: mark_selection(); break;
        case 4: open_new_file(); break;
        case 5: set_font(); break;
        case 6: set_page((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: set_background(); break;
        case 8: save_label(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
