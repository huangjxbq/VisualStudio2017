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
	//=================================���ñ��===========================================
	ui.tableWidget->setRowCount(1200);
	ui.tableWidget->setColumnCount(2);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList() << "FullName" << "Smooth Sizes");
	//
	//QTableWidgetItem *child = new QTableWidgetItem;
	//child->setText(/*QString::fromWCharArray(cast_lpelfe->elfFullName)*/"xx");
	//ui.tableWidget->setItem(1, 1, child);


	//=================================ö������===========================================
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
