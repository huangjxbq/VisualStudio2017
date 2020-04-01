#include "BoundingBox.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BoundingBox w;
	w.show();
	return a.exec();
}
