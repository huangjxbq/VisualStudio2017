#include "Widget.h"

#include <QCursor>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	QCursor cursor;
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