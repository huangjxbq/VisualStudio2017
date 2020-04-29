#include <itkSymmetricEllipsoidInteriorExteriorSpatialFunction.h>

void  SymmetricEllipsoidInteriorExteriorSpatialFunctionTest()
{
	using FunctionType = itk::SymmetricEllipsoidInteriorExteriorSpatialFunction<>;
	using InputType = FunctionType::InputType;
	using OutputType = FunctionType::OutputType;
	using VectorType = FunctionType::VectorType;

	FunctionType::Pointer fun = FunctionType::New();

	InputType center;
	center[0] = 0;
	center[1] = 0;
	center[2] = 0;

	VectorType orientation;
	orientation[0] = 0;
	orientation[1] = 0;
	orientation[2] = 1;

	fun->SetCenter(center);
	fun->SetOrientation(orientation, 5, 2);

	InputType point;
	point[0] = 0;
	point[1] = 0;
	point[2] = 0;

	std::cout << "f(" << point << ") = " << fun->Evaluate(point) << std::endl;

	InputType point2;
	point2[0] = 1;
	point2[1] = 0;
	point2[2] = 0.1;

	std::cout << "f(" << point2 << ") = " << fun->Evaluate(point2) << std::endl;
}