#include "Widget.h"
#include <QFont>
#include <QFontMetrics>
#include <QFontDatabase>
#include <QDebug>
#include <QFileDialog>
#include <QMenu>

int m_count = 0;

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	//Qt ��������
	ui.tableWidget_install_qt->setColumnCount(2);
	ui.tableWidget_install_qt->setHorizontalHeaderLabels(QStringList() << "FileName" << "Number");
	ui.tableWidget_install_qt->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.tableWidget_install_qt->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.tableWidget_install_qt->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��ģʽΪѡ����


	m_pUninstallMenuQt = new QMenu(ui.tableWidget_install_qt);
	m_pUninstallMenuQt->addAction(ui.action_uninstall_qt);

	for (size_t i = 0; i < QFontDatabase::WritingSystemsCount; i++)
	{
		QString str = QFontDatabase::writingSystemName((QFontDatabase::WritingSystem)i) + "(" +
			QFontDatabase::writingSystemSample((QFontDatabase::WritingSystem)i) + ")";

		ui.comboBox_writingSystem->addItem(str, i);
	}

	ui.treeWidget->setColumnCount(10);
	ui.treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.treeWidget->setHeaderLabels(QStringList() << "Font" << "Smooth Sizes" << "Point Sizes" <<
		"BitmapScalable" << "SmoothlyScalable" << "Scalable" << "FixedPitch" <<
		"italic" << "bold" << "weight");
	
	
	//Windows SDK ��������


	//��װ����
	//InstallFontUseWin32();
	//InstallFontUseQt();

	//ö������
	//EnumFontUseQt();
	

	//EnumFontUseWin32();

	QFont font;

	font.setFamily(u8"΢���ź�");

	//==========================�����С=========================
	//font.setPointSize(4);
	font.setPixelSize(25);

	//===========================��ʽ==========================
	//font.setStyle(QFont::StyleItalic);  //ʹ��б����
	//font.setStyle(QFont::StyleOblique);   //ʹ������б
	//font.setItalic(true);               //ʹ��б����

	//font.setUnderline(true);       //�»���
	//font.setOverline(true);        //�ϻ���
	//font.setStrikeOut(true);       //�ᴩ��

	//font.setBold(true);            //�Ӵ�
	//font.setWeight(QFont::Bold);     //�Ӵ�

	//=======================����=============================
	font.setStretch(QFont::Unstretched);           

	//======================���=============================
	//font.setKerning(false);                         //�ּ��
	
	//font.setLetterSpacing(QFont::PercentageSpacing, 400); //�ٷֱ�  �ַ���� (��տտպÿտտ�)
	//font.setLetterSpacing(QFont::AbsoluteSpacing, 25);      //ȷ����  �ַ���� (��400��400)
	//font.setWordSpacing(10);                                //�ּ��

	//====================��Сд=============================
	font.setCapitalization(QFont::MixedCase);       //���ı�
	//font.setCapitalization(QFont::AllUppercase);    //ȫ����д(����)
	//font.setCapitalization(QFont::AllLowercase);    //ȫ��Сд
	//font.setCapitalization(QFont::SmallCaps);         //Сд��ĸ ��� ��д��ĸ(С��)
	//font.setCapitalization(QFont::Capitalize);      //����ĸ��д(����)

	font.setFixedPitch(true);

	//===================substitute====================

	//=================================================


	QString str(u8"��� bEBjing!");

	QFontMetrics fm(font);
	qDebug() << fm.width(u8"��� Beijing!");
	qDebug() << fm.width(u8"���Beijing!");
	qDebug() << fm.width(u8" ");

	//ui.label->setFont(font.resolve(font));
	//ui.label->resize(fm.width(str), fm.height());
	//ui.label->setText(str);
	


	qDebug() << font;


	//
	qDebug() << font.key();
	qDebug() << font.toString();
}

Widget::~Widget()
{
}

void Widget::on_pushButton_Install_Qt_clicked()
{
	QFileDialog filedialog;
	filedialog.setLabelText(QFileDialog::Accept, u8"��װ");
	filedialog.setNameFilter(u8"�����ļ� (*.ttf)");      //ttf RawTrueTypeFont
	filedialog.setFileMode(QFileDialog::ExistingFiles); //���ö�ѡ
	if (QFileDialog::Accepted == filedialog.exec())
	{
		//��װ
		InstallFontUseQt(filedialog.selectedFiles());

		//���½���
		updateListWidget();
	}
}

void Widget::on_tableWidget_install_qt_customContextMenuRequested(const QPoint &pos)
{
	//��ʾ�Ҽ��˵�
	m_pUninstallMenuQt->exec(QCursor::pos());
}

void Widget::on_action_uninstall_qt_triggered()
{
	QList<QTableWidgetItem *> item_list = ui.tableWidget_install_qt->selectedItems();

	for (size_t i = 0; i < item_list.size(); i += 2)
	{
		QTableWidgetItem *file_item = item_list[i];
		QTableWidgetItem *id_item = item_list[i + 1];

		if (QFontDatabase::removeApplicationFont(id_item->text().toInt()))
		{
			m_InstalledFontFile.remove(file_item->text());
			ui.tableWidget_install_qt->removeRow(file_item->row());
		}
	}
}

void Widget::on_pushButton_enum_qt_clicked()
{
	EnumFontUseQt();
}

void Widget::InstallFontUseQt(const QStringList &files)
{
	for (const QString &file : files)
	{
		if (!m_InstalledFontFile.contains(file))
		{
			int id = QFontDatabase::addApplicationFont(file);
			if (-1 != id)
			{
				m_InstalledFontFile.insert(file, id);
			}
		}
	}
}

void Widget::updateListWidget()
{
	ui.tableWidget_install_qt->clear();
	ui.tableWidget_install_qt->setRowCount(m_InstalledFontFile.size());
	ui.tableWidget_install_qt->setHorizontalHeaderLabels(QStringList() << "FileName" << "Number");

	int i = 0;
	for (auto it = m_InstalledFontFile.begin(); it != m_InstalledFontFile.end(); ++it, ++i)
	{
		QTableWidgetItem *child_file = new QTableWidgetItem;
		child_file->setText(it.key());
		ui.tableWidget_install_qt->setItem(i, 0, child_file);

		QTableWidgetItem *child_number = new QTableWidgetItem;
		child_number->setText(QString::number(it.value()));
		ui.tableWidget_install_qt->setItem(i, 1, child_number);
	}
}

void Widget::EnumFontUseQt()
{
	ui.treeWidget->clear();

	QFontDatabase database;
	const QStringList fontFamilies = database.families((QFontDatabase::WritingSystem)ui.comboBox_writingSystem->currentData().toInt());

	for (const QString &family : fontFamilies)
	{
		QTreeWidgetItem *familyItem = new QTreeWidgetItem(ui.treeWidget);

		if (database.isPrivateFamily(family))
		{
			familyItem->setText(0, family + u8"(˽��)");
		}
		else
		{
			familyItem->setText(0, family);
		}

		const QStringList fontStyles = database.styles(family);
		for (const QString &style : fontStyles)
		{
			QTreeWidgetItem *styleItem = new QTreeWidgetItem(familyItem);
			styleItem->setText(0, style);

			//Smooth Sizes
			QString str_smooth_sizes;
			const QList<int> smoothSizes = database.smoothSizes(family, style);
			for (int points : smoothSizes)
			{
				str_smooth_sizes += QString::number(points) + ' ';
			}
			styleItem->setText(1, str_smooth_sizes.trimmed());

			//Point Sizes
			QString str_point_sizes;
			const QList<int> pointSizes = database.pointSizes(family, style);
			for (int points : pointSizes)
			{
				str_point_sizes += QString::number(points) + ' ';
			}
			styleItem->setText(2, str_point_sizes.trimmed());

			//BitmapScalable
			if (database.isBitmapScalable(family, style))
			{
				styleItem->setText(3, "True");
			}
			else
			{
				styleItem->setText(3, "False");
			}
			//SmoothlyScalable
			if (database.isSmoothlyScalable(family, style))
			{
				styleItem->setText(4, "True");
			}
			else
			{
				styleItem->setText(4, "False");
			}

			//Scalable
			if (database.isScalable(family, style))
			{
				styleItem->setText(5, "True");
			}
			else
			{
				styleItem->setText(5, "False");
			}
			//FixedPitch
			if (database.isFixedPitch(family, style))
			{
				styleItem->setText(6, "True");
			}
			else
			{
				styleItem->setText(6, "False");
			}
			//italic
			if (database.italic(family, style))
			{
				styleItem->setText(7, "True");
			}
			else
			{
				styleItem->setText(7, "False");
			}

			//bold
			if (database.bold(family, style))
			{
				styleItem->setText(8, "True");
			}
			else
			{
				styleItem->setText(8, "False");
			}
			//weight
			styleItem->setText(9, QString::number(database.weight(family, style)));
		}
	}
}



void Widget::EnumFontUseWin32()
{
	//=================================���ñ��===========================================
	ui.tableWidget->setRowCount(1200);
	ui.tableWidget->setColumnCount(18);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList() << "FullName" << "Style" << "Script" << "FontType"
	<< "Height" << "Width" << "Escapement" << "Orientation" << "Weight"
	<< "Italic" << "Underline" << "StrikeOut" << "CharSet" << "OutPrecision"
	<< "ClipPrecision" << "Quality" << "PitchAndFamily" << "FaceName");
	//
	//QTableWidgetItem *child = new QTableWidgetItem;
	//child->setText(/*QString::fromWCharArray(cast_lpelfe->elfFullName)*/"xx");
	//ui.tableWidget->setItem(1, 1, child);


	//=================================ö������===========================================
	HDC dc = GetDC((HWND)winId());

	LOGFONT logfont;
	logfont.lfCharSet = DEFAULT_CHARSET;
	//logfont.lfCharSet = GB2312_CHARSET;
	//logfont.lfCharSet = CHINESEBIG5_CHARSET;
	
	logfont.lfFaceName[0] = 0;
	//logfont.lfFaceName[1] = '��';
	//logfont.lfFaceName[2] = '\0';
	logfont.lfPitchAndFamily = 0;
	
	EnumFontFamiliesEx(dc, &logfont, CallBackEnumFontFamExProc, (LPARAM)ui.tableWidget, 0);
	
	qDebug() << "count:" << m_count;
}

void Widget::InstallFontUseWin32()
{
	//��һ��
	m_win_font_1 = AddFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\�����������.ttf"));
	m_win_font_2 = AddFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\����ϸ��.ttf"));
	m_win_font_3 = AddFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\OCR-B 10 BT.ttf"));
	SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
	
}

void Widget::RemoveFontUseWin32()
{
	BOOL res1 = RemoveFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\�����������.ttf"));
	//SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
	BOOL res2 = RemoveFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\����ϸ��.ttf"));
	//SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
	BOOL res3 = RemoveFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\OCR-B 10 BT.ttf"));
	SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
}


int Widget::CallBackEnumFontFamExProc(const LOGFONT * lpelfe, const TEXTMETRIC * lpntme, DWORD FontType, LPARAM lParam)
{
	//ENUMLOGFONTEXDV > ENUMLOGFONTEX > LOGFONT
	const ENUMLOGFONTEX *cast_lpelfe = ((const ENUMLOGFONTEX *)lpelfe);
		
#ifdef UNICODE
	QString fullname = QString::fromWCharArray(cast_lpelfe->elfFullName);
	QString style    = QString::fromWCharArray(cast_lpelfe->elfStyle);
	QString script   = QString::fromWCharArray(cast_lpelfe->elfScript);
#else
	QString fullname = QString::fromLocal8Bit((const char *)cast_lpelfe->elfFullName);  
	QString style    = QString::fromLocal8Bit((const char *)cast_lpelfe->elfStyle);
	QString script   = QString::fromLocal8Bit((const char *)cast_lpelfe->elfScript);
#endif // UNICODE

	QTableWidget *table = (QTableWidget *)lParam;

	//FullName
	QTableWidgetItem *child_fullname = new QTableWidgetItem;
	child_fullname->setText(fullname);
	table->setItem(m_count, 0, child_fullname);

	//Style
	QTableWidgetItem *child_style = new QTableWidgetItem;
	child_style->setText(style);
	table->setItem(m_count, 1, child_style);

	//Script
	QTableWidgetItem *child_script = new QTableWidgetItem;
	child_script->setText(script);
	table->setItem(m_count, 2, child_script);

	//FontType
	QString string_font_type;
	switch (FontType)
	{
	case RASTER_FONTTYPE:
		string_font_type = "Raster";
		break;
	case DEVICE_FONTTYPE:
		string_font_type = "Device";
		break;
	case TRUETYPE_FONTTYPE:
		string_font_type = "TrueType";
		break;
	default:
		string_font_type = "Unknown";
		break;
	}

	QTableWidgetItem *child_fonttype = new QTableWidgetItem;
	child_fonttype->setText(string_font_type);
	table->setItem(m_count, 3, child_fonttype);


	//LOGFONT���ֶ�
	QTableWidgetItem *child_height = new QTableWidgetItem;
	child_height->setText(QString::number(lpelfe->lfWeight));
	table->setItem(m_count, 4, child_height);

	QTableWidgetItem *child_width = new QTableWidgetItem;
	child_width->setText(QString::number(lpelfe->lfWidth));
	table->setItem(m_count, 5, child_width);

	QTableWidgetItem *child_escapement = new QTableWidgetItem;
	child_escapement->setText(QString::number(lpelfe->lfEscapement));
	table->setItem(m_count, 6, child_escapement);

	QTableWidgetItem *child_orientation = new QTableWidgetItem;
	child_orientation->setText(QString::number(lpelfe->lfOrientation));
	table->setItem(m_count, 7, child_orientation);


	QTableWidgetItem *child_facename = new QTableWidgetItem;
	child_facename->setText(QString::fromWCharArray(lpelfe->lfFaceName));
	table->setItem(m_count, 17, child_facename);


	m_count++;
	return 1;
}