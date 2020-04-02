#include <QtCore/QCoreApplication>
#include <itkMesh.h>

using Mesh2D = itk::Mesh<double, 2>;
using Mesh3D = itk::Mesh<double, 3>;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	return a.exec();
}