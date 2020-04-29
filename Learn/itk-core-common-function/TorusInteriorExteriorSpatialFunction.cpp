#include <itkTorusInteriorExteriorSpatialFunction.h>

void TorusInteriorExteriorSpatialFunctionTest()
{

	using FunctionType = itk::TorusInteriorExteriorSpatialFunction<>;
	using InputType = FunctionType::InputType;
	using OutputType = FunctionType::OutputType;

	FunctionType::Pointer fun = FunctionType::New();

	InputType origin;
	origin[0] = 0;
	origin[1] = 0;
	origin[2] = 0;

	fun->SetOrigin(origin);
	fun->SetMinorRadius(2);
	fun->SetMajorRadius(3);

	InputType point;
	point[0] = 0;
	point[1] = 0;
	point[2] = 0;

	std::cout << "f(" << point << ") = " << fun->Evaluate(point) << std::endl;

	InputType point2;
	point2[0] = 5;
	point2[1] = 0;
	point2[2] = 0;

	std::cout << "f(" << point2 << ") = " << fun->Evaluate(point2) << std::endl;
}