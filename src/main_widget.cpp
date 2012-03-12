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
#include "main_widget.h"

main_widget::main_widget()
{	

	text_position = 0; 
	count_page = 0;
	resize_b = false;

	spin_box = new QSpinBox(this);
	spin_box -> setMinimum (1);

	setWindowTitle(tr("QBookShelf"));

        move_L_button = new QPushButton();
        move_R_button = new QPushButton();
        mark_button = new QPushButton();
        open_button = new QPushButton();
        full_screen_button = new QPushButton();
        background_button = new QPushButton();
        font_button = new QPushButton();
        about_button = new QPushButton();

        move_L_button ->setFixedSize(60, 60);
        move_R_button->setFixedSize(60, 60);
        mark_button->setFixedSize(60, 60);
        open_button->setFixedSize(60, 60);
        full_screen_button->setFixedSize(60, 60);
        background_button->setFixedSize(60, 60);
        about_button->setFixedSize(60, 60);
        font_button->setFixedSize(60, 60);

        QPixmap about_pix("image/about.png");
        about_button->setIcon(about_pix);
        about_button->setIconSize(about_pix.size());

        QPixmap background_pix("image/background.png");
        background_button->setIcon(background_pix);
        background_button->setIconSize(background_pix.size());

        QPixmap font_pix("image/font.png");
        font_button->setIcon(font_pix);
        font_button->setIconSize(font_pix.size());

        QPixmap full_screen_pix("image/full.png");
        full_screen_button->setIcon(full_screen_pix);
        full_screen_button->setIconSize(full_screen_pix.size());

        QPixmap open_pix("image/open.png");
        open_button->setIcon(open_pix);
        open_button->setIconSize(open_pix.size());

        QPixmap next_pix("image/next.png");
        move_R_button->setIcon(next_pix);
        move_R_button->setIconSize(next_pix.size());

        QPixmap pre_pix("image/pre.png");
        move_L_button->setIcon(pre_pix);
        move_L_button->setIconSize(pre_pix.size());

        QPixmap mark_pix("image/mark.png");
        mark_button->setIcon(mark_pix);
        mark_button->setIconSize(mark_pix.size());

        L_page_number_label = new QLabel("Page");

	max_pages_label = new QLabel("...");
	max_pages_label -> setAlignment(Qt::AlignCenter);

	virt_viwer = new QTextEdit();
	virt_viwer -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	virt_viwer -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        //////////////view
        view = new QWebView();
        //////
        page_viwer = new my_qtextedit();
        page_viwer -> setReadOnly(true);
        page_viwer -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        page_viwer -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        page_viwer_R = new my_qtextedit();

	group_widgets();
	addWindow(virt_viwer);
      //  addWindow(view, Qt::FramelessWindowHint);
//        view->setGeometry(219, 9, 1050, 723);
//        view->move(10, 10);
        view->hide();
	setLayout(main_panel);
//        this->setStyleSheet("background-image: url(image/main_background.png);background-repeat: none;");
        QObject::connect(page_viwer,SIGNAL(my_resize()),this,SLOT(resize_s()));
	QObject::connect(move_R_button, SIGNAL(clicked()), this, SLOT(push_right()));
	QObject::connect(move_L_button, SIGNAL(clicked()), this, SLOT(push_left()));
	QObject::connect(mark_button, SIGNAL(clicked()), this, SLOT(mark_selection()));
	QObject::connect(spin_box, SIGNAL(valueChanged(int)), this, SLOT(set_page(int)));

}
main_widget::~main_widget(){
}
void main_widget::group_widgets()
{	
	labels_panel = new QHBoxLayout;
	labels_panel -> addWidget(L_page_number_label);
	labels_panel -> addWidget(max_pages_label);

        viwers_panel = new QVBoxLayout;
        viwers_panel -> addWidget(view);
        viwers_panel -> addWidget(page_viwer);
//        view -> resize(1050, 155);

        controls_panel = new QVBoxLayout;
        controls_panel -> addWidget(open_button);
        controls_panel -> addWidget(full_screen_button);
        controls_panel -> addWidget(background_button);
        controls_panel -> addWidget(font_button);
        controls_panel -> addWidget(mark_button);
        controls_panel -> addWidget(move_L_button);
	controls_panel -> addWidget(move_R_button);
        controls_panel -> addWidget(spin_box);
        controls_panel -> addWidget(about_button);


        main_panel = new QHBoxLayout;

//	main_panel -> addLayout(labels_panel);
        main_panel -> addLayout(controls_panel);
        main_panel -> addLayout(viwers_panel);
      //  virt_viwer -> resize(page_viwer->size());
}
void main_widget::packing()
{
        virt_viwer ->show();
      //  virt_viwer ->hideEvent();
    //    virt_viwer -> resize(page_viwer->size());

	if(resize_b == true)
	{
		page_map();
		resize_b = false;
	}

	L_cursor = virt_viwer->textCursor();
	L_cursor.movePosition(QTextCursor::Down,QTextCursor::KeepAnchor,line_count());

	R = L_cursor.selectedText();

        virt_viwer -> hide();
        page_viwer -> setText(R);

        r_numb = count_page+1;
        L_page_number_label-> setText(QString::number(r_numb,10));
}

void main_widget::push_right()
{	
        L_cursor = virt_viwer->textCursor();
	int max_l = max_lines();
	int max_pages;
	int page_l = line_count();

        if(max_l%page_l==0)
		max_pages = max_l / page_l;
	else 
                max_pages = ((max_l-(max_l % page_l))/page_l)+1;

        if(count_page<(max_pages - 1))
                {
			count_page++;
                        L_cursor.setPosition(page_arr[count_page]);
                        text_position = page_arr[count_page];
			virt_viwer->setTextCursor(L_cursor);
			packing();
		}

}
void main_widget::push_left()
{
        L_cursor = virt_viwer->textCursor();
	if(count_page>0)
	{
		count_page--;
                L_cursor.setPosition(page_arr[count_page]);
                text_position = page_arr[count_page];
		virt_viwer->setTextCursor(L_cursor);
		packing();
	}
}
void main_widget::mark_selection()
{

    page_viwer->setTextBackgroundColor(Qt::yellow);
    qDebug("start   :%d\n", page_viwer->textCursor().selectionStart());
    qDebug("end     :%d\n", page_viwer->textCursor().selectionEnd());
    qDebug("position:%d\n", page_viwer->textCursor().position());
    qDebug("anchor  :%d\n", page_viwer->textCursor().anchor());


//    QTextCursor cursor();

//    page_viwer->setTextCursor();
    //page_viwer
}
int main_widget::line_count()
{
        QFontMetrics font_metrics(page_viwer->currentFont());
        int count_lines = (int)(page_viwer->size().height()/font_metrics.height());
	return count_lines-1;
}
int main_widget::max_lines()
{
        virt_viwer ->show();
        QFontMetrics font_metrics(page_viwer->currentFont());
	int count =  (int)virt_viwer -> document() -> size().height();
	int size = (int)font_metrics.height();
	int page_lines = count / size;
	virt_viwer -> hide();
	return page_lines-1;
}
void main_widget::page_map()
{
	page_arr.clear();
	int max_l = max_lines();
	int max_pages;
        int page_l = line_count();
	int max_p;
        int p_l=page_l;

	if(max_l%page_l==0)max_pages = max_l / page_l;
        else max_pages = ((max_l-(max_l % page_l))/page_l)+1;
	if(max_l%p_l==0)
	{
		max_p = max_l / (p_l);
		max_pages_label-> setText(QString::number(max_p,10));
		spin_box -> setMaximum(max_p);
	}
	else
	{
		max_p = ((max_l-(max_l % p_l))/p_l)+1;
		max_pages_label-> setText(QString::number(max_p,10));
		spin_box -> setMaximum(max_p);
	}
	page_arr.resize(max_pages);
        virt_viwer ->show();
	shift_cursor = virt_viwer->textCursor();
	int current_pos = text_position;
        shift_cursor.setVisualNavigation(true);
	shift_cursor.movePosition(QTextCursor::Start);
	for(int t=0; t< max_pages ; t++)
	{
		page_arr[t] = shift_cursor.position();
		shift_cursor.movePosition(QTextCursor::Down,QTextCursor::MoveAnchor,page_l);
	}
	for(int t =0; t< page_arr.size(); t++)
	{

		if(((page_arr[t+1]-current_pos)>0) && ((page_arr[t]-current_pos)< (page_arr[t+1]-current_pos)))
		{
			shift_cursor.setPosition(page_arr[t]);
			count_page = t;
			virt_viwer->setTextCursor(shift_cursor);
			break;
		}
	}
	virt_viwer -> hide();
}
void main_widget::open_new_file()
{	
        file_name = (QFileDialog::getOpenFileName(this,"Open Text", file_name, "txt Files (*.txt *.html);;image files (*.jpg *.png *.jpeg)"));

        if(file_name.contains(".html"))
        {
            virt_viwer->hide();

            view->load(file_name);
            view->showFullScreen();


            page_viwer->hide();

            move_L_button ->setEnabled(false);
            move_R_button->setEnabled(false);
            mark_button->setEnabled(false);
            background_button->setEnabled(false);
            font_button->setEnabled(false);
            spin_box->setEnabled(false);




//            qDebug("%d\t%d\t%d\t%d\n", page_viwer->x(), page_viwer->y(), page_viwer->width(), page_viwer->height());

      }
        else if (file_name.contains(".txt"))
        {
            text_position = 0;
            count_page = 0;
            virt_viwer -> setText(read_text(file_name));
            page_viwer->show();
            page_map();
            packing();
            move_L_button ->setEnabled(true);
            move_R_button->setEnabled(true);
            mark_button->setEnabled(true);
            background_button->setEnabled(true);
            font_button->setEnabled(true);
            spin_box->setEnabled(true);

            this->restore_background();
        //    page_viwer -> setStyleSheet("background-color: white");
          //  this->restore_settings();
            view->hide();
        }
        else
        {
            text_position = 0;
            count_page = 0;
            virt_viwer -> setText("");
            page_map();
            packing();
            view->hide();
            page_viwer->show();
            move_L_button ->setEnabled(false);
            move_R_button->setEnabled(false);
            mark_button->setEnabled(false);
            background_button->setEnabled(false);
            font_button->setEnabled(false);
            spin_box->setEnabled(false);

            page_viwer -> setStyleSheet("background-image: url("+ file_name +");background-repeat: none;background-position:center;background-attachment:   fixed;background-origin: content;");
        }
}
void main_widget::set_font()
{ 
	bool ok;
	my_font = QFontDialog::getFont(&ok, virt_viwer->currentFont(), this);

	if(ok)
	{
		virt_viwer -> setFont(my_font);
                page_viwer -> setFont(my_font);
		resize_b = true; 
		packing();
                this->write_font();
	} else {}

}
void main_widget::resize_s()
{
	resize_b = true;
	packing();
}
void main_widget::set_page(int i)
{
	if(i!=0)
	{
                L_cursor = virt_viwer->textCursor();
                count_page = i - 1;
                L_cursor.setPosition(page_arr[count_page]);
                text_position = page_arr[count_page];
		virt_viwer->setTextCursor(L_cursor);
		packing();
	}
}
void main_widget::restore_settings()
{
        QFileInfo file_info(file_name);

        QSettings settings(QSettings::IniFormat, QSettings::UserScope,"settings", file_info.fileName());


        file_name = settings.value("file").toString();

        virt_viwer -> setText(read_text(file_name));
	my_font.fromString(settings.value("font").toString());
	virt_viwer -> setFont(my_font);

        page_viwer -> setFont(my_font);
        bkgr_name = settings.value("bkgr").toString();
        page_viwer -> setStyleSheet("background-image: url("+ bkgr_name +")");

     //   virt_viwer -> resize(page_viwer->size());
	L_cursor = virt_viwer->textCursor();
	text_position = settings.value("current_page").toInt();
	L_cursor.setPosition(text_position);
        virt_viwer->setTextCursor(L_cursor);

        qDebug("restore:%d\n", text_position);
}
void main_widget::restore_background()
{
    QFileInfo file_info("settings");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, file_info.fileName());


    my_font.fromString(settings.value("font").toString());
    virt_viwer -> setFont(my_font);

    page_viwer -> setFont(my_font);

    bkgr_name = settings.value("bkgr").toString();
    page_viwer -> setStyleSheet("background-image: url("+ bkgr_name +")");

}
void main_widget::write_settings()
{
        qDebug("restore:%s\n", file_name.toStdString().c_str());
        QFileInfo file_info(file_name);

        QSettings settings(QSettings::IniFormat, QSettings::UserScope,"settings", file_info.fileName());
        settings.setValue("file",file_name);
        settings.setValue("bkgr",bkgr_name);
        settings.setValue("font",my_font.toString());
        settings.setValue("current_page",text_position);
}
void main_widget::write_background()
{
    QFileInfo file_info("settings");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, file_info.fileName());
    settings.setValue("bkgr",bkgr_name);

}

void main_widget::set_background()
{
        bkgr_name = (QFileDialog::getOpenFileName(this,"Open Image", bkgr_name, "Jpg Files (*.jpg *.png *.jpeg)"));
        page_viwer -> setStyleSheet("background-image: url("+ bkgr_name +")");
        this->write_background();

}
void main_widget::write_font()
{
    QFileInfo file_info("settings");

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, file_info.fileName());
    settings.setValue("font",my_font.toString());
}

void main_widget::save_label()
{
	qDebug("in widget");
}
