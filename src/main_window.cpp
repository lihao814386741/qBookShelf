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
#include "main_window.h"
#include <QtWebKit>

main_window::main_window()
{
        m_win = new main_widget();

        QPixmap background_pix("image/main_background.png");

        m_win->setBackground(background_pix);

        create_actions();

//        file = menuBar() -> addMenu(tr("&File"));
//        file -> addAction(open_act);
//        file -> addAction(quit_act);

//        view = menuBar() -> addMenu(tr("&View"));
//        view -> addAction(fullsc_act);
//        view -> addAction(backgr_act);
//        view -> addAction(font_act);
//	view -> addAction(save_label_act);

//        about = menuBar() -> addMenu(tr("&About"));
//        about -> addAction(about_act);


        setCentralWidget(m_win);
}
main_window::~main_window(){}
void main_window::create_actions()
{
        open_act = new QAction(tr("&Open"),this);//Open
        open_act -> setShortcut(tr("Ctrl+O"));
        QObject::connect(open_act, SIGNAL(triggered()), m_win, SLOT(open_new_file()));

        font_act = new QAction(tr("&Set font"),this);//Set font
        QObject::connect(font_act, SIGNAL(triggered()), m_win, SLOT(set_font()));

        backgr_act = new QAction(tr("&Set background"),this);//Set background
        QObject::connect(backgr_act, SIGNAL(triggered()), m_win, SLOT(set_background()));

	save_label_act = new QAction(tr("Save label"),this);
        QObject::connect(save_label_act, SIGNAL(triggered()), m_win, SLOT(save_label()));

        quit_act = new QAction(tr("&Quit"),this);//Quit
        quit_act -> setShortcut(tr("Ctrl+Q"));
        QObject::connect(quit_act, SIGNAL(triggered()), this, SLOT(close()));

        about_act = new QAction(tr("&About"),this);
        QObject::connect(about_act, SIGNAL(triggered()), this, SLOT(about_dia()));

        fullsc_act = new QAction(tr("&Fullscreen"),this);
        fullsc_act -> setShortcut(tr("Ctrl+F"));
        QObject::connect(fullsc_act, SIGNAL(triggered()), this, SLOT(toggle_fullscreen()));


        QObject::connect(m_win -> open_button,SIGNAL(clicked()), m_win,SLOT(open_new_file()));
        QObject::connect(m_win -> full_screen_button,SIGNAL(clicked()), this,SLOT(toggle_fullscreen()));
        QObject::connect(m_win -> background_button,SIGNAL(clicked()), m_win,SLOT(set_background()));
        QObject::connect(m_win -> font_button,SIGNAL(clicked()), m_win,SLOT(set_font()));
        QObject::connect(m_win -> about_button,SIGNAL(clicked()), this,SLOT(about_dia()));
        QObject::connect(m_win -> exit_button,SIGNAL(clicked()), this,SLOT(close()));
        QObject::connect(m_win ->find_button, SIGNAL(clicked()), m_win, SLOT(find_text()));



}
void main_window::toggle_fullscreen()
{
        if(this-> windowState() == Qt::WindowFullScreen)
        {
                this-> setWindowState(previous_window_state);
        }
        else
        {
                previous_window_state = this->windowState();
                this-> setWindowState(Qt::WindowFullScreen);
        }
 //       m_win -> virt_viwer -> resize(m_win -> page_viwer->size());
        m_win->view->resize(m_win -> page_viwer->size());
        m_win -> resize_s();
}
void main_window::closeEvent(QCloseEvent *event)
{
        save_size();
        event->accept();
}
void main_window::save_size()
{
        QFileInfo file_info(m_win -> file_name);

        QSettings settings(QSettings::IniFormat, QSettings::UserScope,"settings", file_info.fileName());


        settings.setValue("size",this->size());
        m_win -> write_settings();
}

void main_window::restore_size()
{
        QFileInfo file_info(m_win -> file_name);

        qDebug("restore_size:%s.\n", m_win -> file_name.toStdString().c_str());
        QSettings settings(QSettings::IniFormat, QSettings::UserScope,"settings", file_info.fileName());


        this-> resize(settings.value("size").toSize());

        m_win -> restore_settings();
        m_win -> page_map();
        m_win -> packing();
}
void main_window::about_dia()
{
        QMessageBox::about( this, "About", "Author: Phoenix" );
}
