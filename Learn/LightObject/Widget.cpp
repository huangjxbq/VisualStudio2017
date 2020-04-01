#include "Widget.h"
#include <QDebug>
#include <itkLightObject.h>

#include <fstream>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	itk::LightObject::Pointer lightobject = itk::LightObject::New();
	qDebug() << lightobject->GetNameOfClass();

	itk::LightObject::Pointer lightobject2 = lightobject->Clone();

	itk::LightObject::Pointer lightobject3 = lightobject->CreateAnother();

	std::ofstream o("a.txt");
	lightobject->Print(o);
	lightobject2->Print(o);
	lightobject3->Print(o);
}