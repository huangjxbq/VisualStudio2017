#include "Widget.h"
#include <Windows.h>
#include <QSysInfo>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QSysInfo sysinfo;


	GetVersion();

	//GetVersionEx();
}
