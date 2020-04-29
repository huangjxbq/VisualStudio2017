#include <itkEllipsoidInteriorExteriorSpatialFunction.h>


void EllipsoidInteriorExteriorSpatialFunctionTest()
{
	using FunctionType = itk::EllipsoidInteriorExteriorSpatialFunction<>;
	using InputType = FunctionType::InputType;
	using OutputType = FunctionType::OutputType;
	using OrientationType = FunctionType::OrientationType;

	FunctionType::Pointer fun = FunctionType::New();


	InputType center;
	center[0] = 0;
	center[1] = 0;
	center[2] = 0;

	InputType axes;
	axes[0] = 2;
	axes[1] = 2;
	axes[2] = 5;

	OrientationType orientation;
	orientation(0, 0) = 1; orientation(0, 1) = 0; orientation(0, 2) = 0;
	orientation(1, 0) = 0; orientation(1, 1) = 1; orientation(1, 2) = 0;
	orientation(2, 0) = 0; orientation(2, 1) = 0; orientation(2, 2) = 1;

	fun->SetCenter(center);
	fun->SetAxes(axes);
	fun->SetOrientations(orientation);

	InputType point;
	point[0] = 0.9;
	point[1] = 0.9;
	point[2] = 0.9;

	std::cout << "f(" << point << ") = " << fun->Evaluate(point) << std::endl;
}