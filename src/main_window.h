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
#ifndef MAIN_WINDOW_H_INCLUDED
#define MAIN_WINDOW_H_INCLUDED
#include <QtGui>
#include <QtCore>
#include "main_widget.h"

class main_window: public QMainWindow
{
        Q_OBJECT 
        public:
//CONSTRUCTORS
        main_window();
        ~main_window();
//FUNCTIONS
        void save_size();
        void restore_size();
        void create_actions();
//MENUS
        QMenu *file;
        QMenu *view;
        QMenu *about;
//ACTIONS
        QAction *open_act;
        QAction *quit_act;
        QAction *about_act;
        QAction *fullsc_act;
        QAction *font_act;
        QAction *backgr_act;
        QAction *save_label_act;

//WIDGETS
        main_widget *m_win;
//SLOTS
        public slots:
        void toggle_fullscreen();
        void about_dia();
//VARIABLES
        private:
        Qt::WindowStates previous_window_state;
//FUNCTIONS
        protected:
        void closeEvent(QCloseEvent *event); 
};
#endif
