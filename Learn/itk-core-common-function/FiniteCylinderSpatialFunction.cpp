#include <itkFiniteCylinderSpatialFunction.h>

void FiniteCylinderSpatialFunctionTest()
{
	using FunctionType = itk::FiniteCylinderSpatialFunction<>;
	using InputType = FunctionType::InputType;
	using OutputType = FunctionType::OutputType;
	using OrientationType = FunctionType::InputType;

	FunctionType::Pointer fun = FunctionType::New();

	InputType center;
	center[0] = 0;
	center[1] = 0;
	center[2] = 0;

	OrientationType orientation;
	orientation[0] = 0;
	orientation[1] = 0;
	orientation[2] = 1;

	fun->SetCenter(center);
	fun->SetRadius(4);
	fun->SetAxisLength(10);
	fun->SetOrientation(orientation);
	

	InputType point;
	point[0] = 1;
	point[1] = 1;
	point[2] = 1;

	InputType point2;
	point2[0] = 4;
	point2[1] = 4;
	point2[2] = 11;

	std::cout << "f(" << point << ") = " << fun->Evaluate(point) << std::endl;
	std::cout << "f(" << point2 << ") = " << fun->Evaluate(point2) << std::endl;


}