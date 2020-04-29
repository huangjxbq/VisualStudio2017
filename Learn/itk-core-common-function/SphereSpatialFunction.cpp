#include <itkSphereSpatialFunction.h>

void SphereSpatialFunctionTest()
{
	using FunctionType = itk::SphereSpatialFunction<>;
	using InputType = FunctionType::InputType;
	using OutputType = FunctionType::OutputType;

	FunctionType::Pointer fun = FunctionType::New();


	InputType center;
	center[0] = 0;
	center[1] = 0;
	center[2] = 0;

	fun->SetCenter(center);
	fun->SetRadius(2);

	InputType point;
	point[0] = 1;
	point[1] = 1;
	point[2] = 1;

	InputType point2;
	point2[0] = 3;
	point2[1] = 3;
	point2[2] = 3;

	std::cout << "f(" << point << ") = " << fun->Evaluate(point) << std::endl;
	std::cout << "f(" << point2 << ") = " << fun->Evaluate(point2) << std::endl;
}