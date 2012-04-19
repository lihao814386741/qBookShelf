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
#ifndef MAIN_WIDGET_H_INCLUDED
#define MAIN_WIDGET_H_INCLUDED
#include <QtGui>
#include <QtCore>
#include <QTextCharFormat>
#include "text_open.h"
#include "my_qtextedit.h"
#include <QtWebKit>
#include <QToolBar>
#include <QTimer>



class main_widget: public QWorkspace
{
	Q_OBJECT 
	public: 
//CONSTRUCTORS
	main_widget();
	~main_widget();
//FUNCTIONS
	int max_lines();
	int line_count();
	void page_map();
	void packing();
	void group_widgets();
	void restore_settings();
        void restore_background();
	void write_settings();
        void write_background();
        void write_font();
        void display();
        void show_dialog(QString toast);
        void restore_page();
        void restore_mark();
        //void rest_position();
//STRINGS
	QString R;
	QString L;
	QString file_name;
	QString bkgr_name;

	//QString virt_s;
/*/DIALOGS
	QFileDialog file_dialog;
	QFontDialog font_dialog;*/
//FONTS
	QFont my_font;
//VECTORS
        QVector<long int> page_arr;
//list
        QList<QVariant> mark_label;

//VARIABLES
	int count_page;
	bool resize_b;
	bool OK;
	int l_numb;
	int r_numb;
	int text_position;
        int text_scroll;
//Dialog
        QDialog *find_dialog;
        QDialog *show_up;
 //Button
	QPushButton *move_L_button;
	QPushButton *move_R_button;
	QPushButton *mark_button;
        QPushButton *open_button;
        QPushButton *full_screen_button;
        QPushButton *background_button;
        QPushButton *font_button;
        QPushButton *about_button;
        QPushButton *exit_button;
        QPushButton *find_button;
        QPushButton *test_button;
        QPushButton *auto_down_button;
//LABELS
	QLabel *L_page_number_label;
	QLabel *R_page_number_label;
	QLabel *max_pages_label; 

//VIWERS
        my_qtextedit *page_viwer;
	my_qtextedit *page_viwer_R;
	QTextEdit *virt_viwer;
        QLineEdit *find_text_edit;
//CURSORS
	QTextCursor L_cursor;
	//QTextCursor R_cursor;
	QTextCursor shift_cursor;
//SPINBOX
      //  QSpinBox *spin_box;
//PANELS
	QHBoxLayout *labels_panel;
        QVBoxLayout *viwers_panel;
        QVBoxLayout *controls_panel;
        QHBoxLayout *main_panel;
        QWebView *view;
//ENCODE
        QTextCodec* pcodec;
//Timer
        QTimer *timer;
        bool isopen;

//SLOTS
	public slots:
        void resize_s();
        void push_right();
	void push_left();
	void mark_selection();
        void open_new_file();
	void set_font();
        void set_page(int i);
        void set_background();
	void save_label();
        void restore_label();
        void find_text();
        void push_find_button();
        void testthebutton();
        void move_up();
        void move_down();
        void delete_dialog();
        void auto_down();
        void restore_html_page();

};
#endif
