#include "Widget.h"
#include <QtWidgets/QApplication>
#include <log4cplus/log4cplus.h>

int main(int argc, char *argv[])
{
	log4cplus::Initializer loginitializer;
	QApplication a(argc, argv);
	Widget w;
	w.show();
	return a.exec();
}
