#include "Widget.h"
#include <QFont>
#include <QFontMetrics>
#include <QFontDatabase>
#include <QDebug>
#include <QFileDialog>

int m_count = 0;

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	ui.treeWidget->setColumnCount(10);
	ui.treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.treeWidget->setHeaderLabels(QStringList() << "Font" << "Smooth Sizes" << "Point Sizes" << 
		"BitmapScalable" << "SmoothlyScalable" << "Scalable" << "FixedPitch" << 
		"italic" << "bold" << "weight");

	//安装字体
	//InstallFontUseWin32();
	//InstallFontUseQt();

	//枚举字体
	EnumFontUseQt();
	

	EnumFontUseWin32();

	QFont font;

	font.setFamily(u8"微软雅黑");

	//==========================字体大小=========================
	//font.setPointSize(4);
	font.setPixelSize(25);

	//===========================样式==========================
	//font.setStyle(QFont::StyleItalic);  //使用斜体字
	//font.setStyle(QFont::StyleOblique);   //使文字倾斜
	//font.setItalic(true);               //使用斜体字

	//font.setUnderline(true);       //下划线
	//font.setOverline(true);        //上划线
	//font.setStrikeOut(true);       //贯穿线

	//font.setBold(true);            //加粗
	//font.setWeight(QFont::Bold);     //加粗

	//=======================拉伸=============================
	font.setStretch(QFont::Unstretched);           

	//======================间距=============================
	//font.setKerning(false);                         //字间距
	
	//font.setLetterSpacing(QFont::PercentageSpacing, 400); //百分比  字符间隔 (你空空空好空空空)
	//font.setLetterSpacing(QFont::AbsoluteSpacing, 25);      //确定数  字符间隔 (你400好400)
	//font.setWordSpacing(10);                                //字间距

	//====================大小写=============================
	font.setCapitalization(QFont::MixedCase);       //不改变
	//font.setCapitalization(QFont::AllUppercase);    //全都大写(大型)
	//font.setCapitalization(QFont::AllLowercase);    //全都小写
	//font.setCapitalization(QFont::SmallCaps);         //小写字母 变成 大写字母(小型)
	//font.setCapitalization(QFont::Capitalize);      //首字母大写(大型)

	font.setFixedPitch(true);

	//===================substitute====================

	//=================================================


	QString str(u8"你好 bEBjing!");

	QFontMetrics fm(font);
	qDebug() << fm.width(u8"你好 Beijing!");
	qDebug() << fm.width(u8"你好Beijing!");
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
	filedialog.setLabelText(QFileDialog::Accept, u8"安装");
	filedialog.setNameFilter(u8"字体文件 (*.ttf)");      //ttf RawTrueTypeFont
	filedialog.setFileMode(QFileDialog::ExistingFiles); //设置多选
	if (QFileDialog::Accepted == filedialog.exec())
	{
		//安装
		InstallFontUseQt(filedialog.selectedFiles());

		//更新界面
		updateListWidget();
	}
}

void Widget::updateListWidget()
{
	//auto it = m_InstalledFontFile.begin();
	for (auto it = m_InstalledFontFile.begin(); it != m_InstalledFontFile.end(); ++it)
	{
		QListWidgetItem *item = new QListWidgetItem(it.key(), ui.listWidget);
		ui.listWidget->create
	}
}

void Widget::EnumFontUseQt()
{
	//InstallFontUseQt();
	

	QFontDatabase database;
	const QStringList fontFamilies = database.families();

	for (const QString &family : fontFamilies)
	{
		QTreeWidgetItem *familyItem = new QTreeWidgetItem(ui.treeWidget);
		familyItem->setText(0, family);

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

void Widget::EnumFontUseWin32()
{
	//=================================设置表格===========================================
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


	//=================================枚举字体===========================================
	HDC dc = GetDC((HWND)winId());

	LOGFONT logfont;
	logfont.lfCharSet = DEFAULT_CHARSET;
	//logfont.lfCharSet = GB2312_CHARSET;
	//logfont.lfCharSet = CHINESEBIG5_CHARSET;
	
	logfont.lfFaceName[0] = 0;
	//logfont.lfFaceName[1] = '体';
	//logfont.lfFaceName[2] = '\0';
	logfont.lfPitchAndFamily = 0;
	
	EnumFontFamiliesEx(dc, &logfont, CallBackEnumFontFamExProc, (LPARAM)ui.tableWidget, 0);
	
	qDebug() << "count:" << m_count;
}

void Widget::InstallFontUseWin32()
{
	//第一种
	m_win_font_1 = AddFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\方正黑体简体.ttf"));
	m_win_font_2 = AddFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\华文细黑.ttf"));
	m_win_font_3 = AddFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\OCR-B 10 BT.ttf"));
	SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
	
}

void Widget::RemoveFontUseWin32()
{
	BOOL res1 = RemoveFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\方正黑体简体.ttf"));
	//SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
	BOOL res2 = RemoveFontResource(TEXT("C:\\Users\\lenovo\\Desktop\\华文细黑.ttf"));
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


	//LOGFONT的字段
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