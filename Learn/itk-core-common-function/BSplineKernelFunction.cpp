#include <itkBSplineKernelFunction.h>

void BSplineKernelFunctionTest()
{
	itk::BSplineKernelFunction<>::Pointer fun = itk::BSplineKernelFunction<>::New();

	itk::BSplineKernelFunction<>::RealType x1 = -2;
	itk::BSplineKernelFunction<>::RealType x2 = -1;
	itk::BSplineKernelFunction<>::RealType x3 = 0;
	itk::BSplineKernelFunction<>::RealType x4 = 1;
	itk::BSplineKernelFunction<>::RealType x5 = 2;

	std::cout << "f(" << x1 << ") = " << fun->Evaluate(x1) << std::endl;
	std::cout << "f(" << x2 << ") = " << fun->Evaluate(x2) << std::endl;
	std::cout << "f(" << x3 << ") = " << fun->Evaluate(x3) << std::endl;
	std::cout << "f(" << x4 << ") = " << fun->Evaluate(x4) << std::endl;
	std::cout << "f(" << x5 << ") = " << fun->Evaluate(x5) << std::endl;
}