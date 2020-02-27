#include "Widget.h"
#include <QCursor>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.label_count->setAlignment(Qt::AlignCenter);

	


	//ui.comboBox_cursor->addItem(tr("Standard arrow and small hourglass"),						QString::fromWCharArray(IDC_APPSTARTING));
	//ui.comboBox_cursor->addItem(tr("Standard arrow"),											(qint64)IDC_ARROW);
	//ui.comboBox_cursor->addItem(tr("Crosshair"),												(qint64)IDC_CROSS);
	//ui.comboBox_cursor->addItem(tr("Hand"),														(qint64)IDC_HAND);
	//ui.comboBox_cursor->addItem(tr("Arrow and question mark"),									(qint64)IDC_HELP);
	//ui.comboBox_cursor->addItem(tr("Obsolete"),													(qint64)IDC_ICON);
	//ui.comboBox_cursor->addItem(tr("Slashed circle"),											(qint64)IDC_NO);
	//ui.comboBox_cursor->addItem(tr("Obsolete; use IDC_SIZEALL"),								(qint64)IDC_SIZE);
	//ui.comboBox_cursor->addItem(tr("Four-pointed arrow pointing north, south, east, and west"), (qint64)IDC_SIZEALL);
	//ui.comboBox_cursor->addItem(tr("Double-pointed arrow pointing northeast and southwest"),	(qint64)IDC_SIZENESW);
	//ui.comboBox_cursor->addItem(tr("Double-pointed arrow pointing north and south"),			(qint64)IDC_SIZENS);
	//ui.comboBox_cursor->addItem(tr("Double-pointed arrow pointing northwest and southeast"),	(qint64)IDC_SIZENWSE);
	//ui.comboBox_cursor->addItem(tr("Double-pointed arrow pointing west and east"),				(qint64)IDC_SIZEWE);
	//ui.comboBox_cursor->addItem(tr("Vertical arrow"),											(qint64)IDC_UPARROW);
	//ui.comboBox_cursor->addItem(tr("Hourglass"), QString::fromWCharArray(IDC_WAIT));




	m_hWnd = (HWND)winId();
	GetClipCursor(&m_OldClipRect);
}

void Widget::on_pushButton_ArrowCursor_clicked()
{
	QCursor cursor(Qt::ArrowCursor);
	this->setCursor(cursor);
}
void Widget::on_pushButton_UpArrowCursor_clicked()
{
	QCursor cursor(Qt::UpArrowCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_CrossCursor_clicked()
{
	QCursor cursor(Qt::CrossCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_WaitCursor_clicked()
{
	QCursor cursor(Qt::WaitCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_IBeamCursor_clicked()
{
	QCursor cursor(Qt::IBeamCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SizeVerCursor_clicked()
{
	QCursor cursor(Qt::SizeVerCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SizeHorCursor_clicked()
{
	QCursor cursor(Qt::SizeHorCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SizeBDiagCursor_clicked()
{
	QCursor cursor(Qt::SizeBDiagCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SizeFDiagCursor_clicked()
{
	QCursor cursor(Qt::SizeFDiagCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SizeAllCursor_clicked()
{
	QCursor cursor(Qt::SizeAllCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_BlankCursor_clicked()
{
	QCursor cursor(Qt::BlankCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SplitVCursor_clicked()
{
	QCursor cursor(Qt::SplitVCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SplitHCursor_clicked()
{
	QCursor cursor(Qt::SplitHCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_PointingHandCursor_clicked()
{
	QCursor cursor(Qt::PointingHandCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_ForbiddenCursor_clicked()
{
	QCursor cursor(Qt::ForbiddenCursor);
	this->setCursor(cursor);
}
void Widget::on_pushButton_WhatsThisCursor_clicked()
{
	QCursor cursor(Qt::WhatsThisCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_BusyCursor_clicked()
{
	QCursor cursor(Qt::BusyCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_OpenHandCursor_clicked() 
{
	QCursor cursor(Qt::OpenHandCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_ClosedHandCursor_clicked() 
{
	QCursor cursor(Qt::ClosedHandCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_DragCopyCursor_clicked() 
{
	QCursor cursor(Qt::DragCopyCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_DragMoveCursor_clicked()
{
	QCursor cursor(Qt::DragMoveCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_DragLinkCursor_clicked()
{
	QCursor cursor(Qt::DragLinkCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_LastCursor_clicked()
{
	QCursor cursor(Qt::LastCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_BitmapCursor_clicked()
{
	QCursor cursor(Qt::BitmapCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_CustomCursor_clicked() 
{
	QCursor cursor(Qt::CustomCursor);
	this->setCursor(cursor);
	
}


void Widget::on_pushButton_clipCursor_clicked()
{
	GetWindowRect((HWND)winId(), &m_NewClipRect);
	ClipCursor(&m_NewClipRect);
}

void Widget::on_pushButton_cancleClipCursor_clicked()
{
	ClipCursor(&m_OldClipRect);
}

void Widget::on_pushButton_show_clicked()
{
	m_Count = ShowCursor(TRUE);
	ui.label_count->setText(QString::number(m_Count));
	
}

void Widget::on_pushButton_hide_clicked()
{
	m_Count = ShowCursor(FALSE);
	ui.label_count->setText(QString::number(m_Count));
}

void Widget::on_comboBox_cursor_currentIndexChanged(int index)
{
#ifdef UNICODE
	wchar_t str[128] = { 0 };
	ui.comboBox_cursor->currentData().toString().toWCharArray(str);
#else


#endif // UNICODE


	 
	HCURSOR cursor = LoadCursor(NULL, str);
	if (NULL == cursor)
	{
		QMessageBox::critical(this, tr("error"), tr("critical"));
	}
	SetCursor(cursor);
}