#include "Widget.h"
#include <QFont>
#include <QFontMetrics>
#include <QFontDatabase>
#include <QDebug>

int m_count = 0;

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	EnumFont();

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

	ui.label->setFont(font.resolve(font));
	ui.label->resize(fm.width(str), fm.height());
	ui.label->setText(str);
	


	qDebug() << font;


	//
	qDebug() << font.key();
	qDebug() << font.toString();
}

void Widget::EnumFont()
{
	//=================================设置表格===========================================
	ui.tableWidget->setRowCount(1200);
	ui.tableWidget->setColumnCount(2);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList() << "FullName" << "Smooth Sizes");
	//
	//QTableWidgetItem *child = new QTableWidgetItem;
	//child->setText(/*QString::fromWCharArray(cast_lpelfe->elfFullName)*/"xx");
	//ui.tableWidget->setItem(1, 1, child);


	//=================================枚举字体===========================================
	HDC dc = GetDC((HWND)winId());

	LOGFONT logfont;
	logfont.lfCharSet = DEFAULT_CHARSET;
	logfont.lfFaceName[0] = '\0';
	logfont.lfPitchAndFamily = 0;

	EnumFontFamiliesEx(dc, &logfont, CallBackEnumFontFamExProc, (LPARAM)ui.tableWidget, 0);
	
	qDebug() <<  "count:" << m_count;



}

int Widget::CallBackEnumFontFamExProc(const LOGFONT * lpelfe, const TEXTMETRIC * lpntme, DWORD FontType, LPARAM lParam)
{
	//ENUMLOGFONTEXDV > ENUMLOGFONTEX > LOGFONT
	const ENUMLOGFONTEX * cast_lpelfe = ((const ENUMLOGFONTEX *)lpelfe);

	QTableWidget *table = (QTableWidget *)lParam;

	//FullName
	QTableWidgetItem *child = new QTableWidgetItem;

#ifdef UNICODE
	child->setText(QString::fromWCharArray(cast_lpelfe->elfFullName));
#else
	child->setText(QString::fromLocal8Bit(cast_lpelfe->elfFullName));
#endif // UNICODE

	table->setItem(m_count, 0, child);






	m_count++;
	return 1;
}
