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
#include "text_open.h"

QString read_text(QString file_name)
{
	QString memory_line;
	QFile input_file(file_name);
	if(!input_file.open(QIODevice::ReadOnly))
	{
		qWarning("[ERROR] Openning file!");
	}
	else
	{
		QTextStream in(&input_file);
		while(!in.atEnd())
		{
			memory_line += in.readLine();
			memory_line += "\n";
		}
	}
	return memory_line;
}
