#include "Widget.h"
#include <QClipboard>
#include <QGuiApplication>
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QClipboard *clipboard = QGuiApplication::clipboard();

	qDebug() << clipboard->supportsSelection();
	qDebug() << clipboard->supportsFindBuffer();

	clipboard->setText("hhhhhhh");
	

	//QPixmap pixmap(u8"C:/Users/lenovo/Desktop/н╒пе╫ьм╪_20200312172405.png");
	//clipboard->setPixmap(pixmap);

	QImage image(u8"C:/Users/lenovo/Desktop/н╒пе╫ьм╪_20200312172405.png");
	clipboard->setImage(image);
}