#include "Widget.h"
#include <QMovie>
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);



	//QMovie movie;

	qDebug() << QMovie::supportedFormats();
}
