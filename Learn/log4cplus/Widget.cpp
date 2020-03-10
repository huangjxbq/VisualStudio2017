#include "Widget.h"

#include <log4cplus/appender.h>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
