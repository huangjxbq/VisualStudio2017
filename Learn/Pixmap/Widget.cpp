#include "Widget.h"
#include <QPixmap>
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QPixmap pixmap("C:\\Users\\hjx\\Desktop\\IMG_20190324_160629.jpg");
	
	qDebug() << pixmap.isNull();

	ui.label->setPixmap(pixmap);
	
	//qDebug() << pixmap.handle();
}