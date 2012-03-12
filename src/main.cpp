/* This file is part of QBookShelf.

    QBookShelf is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    QBookShelf is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with QBookShelf.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <QtGui/QApplication>
#include <QtCore>
#include "main_window.h"

int main(int argc, char* argv[])
{
        QApplication app(argc, argv);
        QSettings::setPath(QSettings::IniFormat, QSettings::UserScope,QCoreApplication::applicationDirPath());
       // qDebug(QCoreApplication::applicationDirPath().toStdString().c_str());
        main_window *program= new main_window();
        program -> show();
        program -> restore_size();
        return app.exec();
}
