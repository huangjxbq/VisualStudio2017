#include <itkAtanRegularizedHeavisideStepFunction.h>

void AtanRegularizedHeavisideStepFunctionTest()
{
	itk::AtanRegularizedHeavisideStepFunction<>::Pointer fun =
		itk::AtanRegularizedHeavisideStepFunction<>::New();

	using RealType = itk::NumericTraits< itk::AtanRegularizedHeavisideStepFunction<>::InputType>::RealType;
	std::cout << "epsilon:" << itk::NumericTraits<RealType>::epsilon() << std::endl;

	fun->SetEpsilon(1);


	int x1 = -1;
	int x2 = 0;
	int x3 = 1;

	std::cout << "f(" << x1 << ") = " << fun->Evaluate(x1) << std::endl;
	std::cout << "f(" << x2 << ") = " << fun->Evaluate(x2) << std::endl;
	std::cout << "f(" << x3 << ") = " << fun->Evaluate(x3) << std::endl;
	std::cout << std::endl;

	std::cout << "f'(" << x1 << ") = " << fun->EvaluateDerivative(x1) << std::endl;
	std::cout << "f'(" << x2 << ") = " << fun->EvaluateDerivative(x2) << std::endl;
	std::cout << "f'(" << x3 << ") = " << fun->EvaluateDerivative(x3) << std::endl;


}