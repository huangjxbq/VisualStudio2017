#include "BoundingBox.h"
#include <QDebug>
#include <itkBoundingBox.h>

BoundingBox::BoundingBox(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	using BoundingBoxType = itk::BoundingBox<itk::IdentifierType, 2, double>;
	BoundingBoxType::Pointer boundingbox = BoundingBoxType::New();

	boundingbox->Print(std::cout);

	BoundingBoxType::PointsContainer::Pointer points = BoundingBoxType::PointsContainer::New();
	
	BoundingBoxType::PointType point1;
	BoundingBoxType::PointType point2;
	BoundingBoxType::PointType point3;
	BoundingBoxType::PointType point4;
	//point1.SetElement(0, 0); point1.SetElement(1, 0);
	point1 = 1, 1;
	point2 = 2, 2;
	point3 = 3, 3;
	point4 = 4, 4;

	BoundingBoxType::PointType point5;
	point5 = 2.5, 2.5;

	BoundingBoxType::PointType point6;
	point6 = 5.5, 5.5;
	
	points->Reserve(4);
	points->SetElement(0, point1);
	points->SetElement(1, point2);
	points->SetElement(2, point3);
	points->SetElement(3, point4);

	boundingbox->SetPoints(points);
	boundingbox->ComputeBoundingBox();
	boundingbox->Print(std::cout);

	//获取边界
	std::cout << boundingbox->GetBounds() << std::endl;

	//获取角点
	std::cout << boundingbox->GetCorners()->Size() << std::endl;
	for (size_t i = 0; i < boundingbox->GetCorners()->Size(); i++)
	{
		std::cout << boundingbox->GetCorners()->GetElement(i) << std::endl;
	}

	//获取中心点
	std::cout << boundingbox->GetCenter() << std::endl;

	//获取对角线的平方
	std::cout << "DiagonalLength2:" << boundingbox->GetDiagonalLength2() << std::endl;

	std::cout << "Maximum:" << boundingbox->GetMaximum() << std::endl;
	std::cout << "Minimum:" << boundingbox->GetMinimum() << std::endl;


	std::cout << boundingbox->IsInside(point5) << std::endl;
	std::cout << boundingbox->IsInside(point6) << std::endl;

	boundingbox->ConsiderPoint(point6);
	boundingbox->Print(std::cout);

}