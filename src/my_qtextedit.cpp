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
#include "my_qtextedit.h"

my_qtextedit::my_qtextedit(){}
void my_qtextedit::resizeEvent(QResizeEvent *event)
{
	emit my_resize();
	QTextEdit::resizeEvent(event);
}
my_qtextedit::~my_qtextedit(){}
