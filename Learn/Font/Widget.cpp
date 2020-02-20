#include "Widget.h"
#include <QFont>
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	QFont font;


	font.setFamily(u8"Î¢ÈíÑÅºÚ");
	font.setPointSize(4);
	//font.setPixelSize(50);
	//font.setWeight(QFont::Black);


	ui.label->setFont(font);
	ui.label->resize(100, 50);
	ui.label->setText(u8"ÄãºÃ");
	ui.label->update();

	qDebug() << font;
}