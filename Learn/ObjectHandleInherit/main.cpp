#include "ObjectHandleInherit.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ObjectHandleInherit w;
	w.show();
	return a.exec();
}
