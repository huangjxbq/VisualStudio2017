#include <QtCore/QCoreApplication>
#include <itkMesh.h>

using Mesh2D = itk::Mesh<double, 2>;
using Mesh3D = itk::Mesh<double, 3>;
using Mesh2DPointer = Mesh2D::Pointer;
using Mesh3DPointer = Mesh3D::Pointer;

using Mesh2DPoint = Mesh2D::PointType;
using Mesh3DPoint = Mesh3D::PointType;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Mesh2DPointer mesh2d = Mesh2D::New();

	mesh2d->DebugOn();
	//std::cout << "点维度:" << mesh2d->PointDimension << std::endl;
	//std::cout << "最大拓扑维度:" << mesh2d->MaxTopologicalDimension << std::endl;

	//PointSet
	Mesh2DPoint point1; point1.SetElement(0, 0); point1.SetElement(1, 0);
	Mesh2DPoint point2; point2.SetElement(0, 1); point2.SetElement(1, 0);
	Mesh2DPoint point3; point3.SetElement(0, 0); point3.SetElement(1, 1);

	mesh2d->SetPoint(0, point1);
	mesh2d->SetPoint(1, point2);
	mesh2d->SetPoint(2, point3);

	//std::cout << "点数量:" << mesh2d->GetNumberOfPoints() << std::endl;

	mesh2d->SetPointData(0, 2.5);
	mesh2d->SetPointData(1, 2.8);
	mesh2d->SetPointData(2, 6.5);

	mesh2d->Print(std::cout);

	//mesh


	return a.exec();
}