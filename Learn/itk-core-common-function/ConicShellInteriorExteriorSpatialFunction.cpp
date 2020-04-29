#include <itkConicShellInteriorExteriorSpatialFunction.h>

void ConicShellInteriorExteriorSpatialFunctionTest()
{
	itk::ConicShellInteriorExteriorSpatialFunction<>::Pointer fun =
		itk::ConicShellInteriorExteriorSpatialFunction<>::New();

	using InputType = itk::ConicShellInteriorExteriorSpatialFunction<>::InputType;

	using GradientType = itk::ConicShellInteriorExteriorSpatialFunction<>::GradientType;

	GradientType gradient;
	gradient[0] = 1;
	gradient[1] = 1;
	gradient[2] = 0;

	fun->SetDistanceMin(0);
	fun->SetDistanceMax(10);
	fun->SetOriginGradient(gradient);
	fun->SetEpsilon(0.00001);


	InputType x1;
	x1[0] = 2;
	x1[1] = 2;
	x1[2] = 0;

	InputType x2 = 0;
	InputType x3 = 1;

	std::cout << "f(" << x1 << ") = " << fun->Evaluate(x1) << std::endl;
	std::cout << "f(" << x2 << ") = " << fun->Evaluate(x2) << std::endl;
	std::cout << "f(" << x3 << ") = " << fun->Evaluate(x3) << std::endl;
	std::cout << std::endl;
}