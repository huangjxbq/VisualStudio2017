#include "Widget.h"
#include <QMovie>
#include <QStyle>
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	ui.label->setBackgroundRole(QPalette::Dark);

	//ÉèÖÃ°´Å¥
	ui.toolButton_open->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
	ui.toolButton_start->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	ui.toolButton_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
	ui.toolButton_stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

	QMovie movie;

	qDebug() << QMovie::supportedFormats();
}
