#include "Child.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Child w;
	w.show();
	return a.exec();
}
