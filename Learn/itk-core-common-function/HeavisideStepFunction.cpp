#include <itkHeavisideStepFunction.h>

void HeavisideStepFunctionTest()
{
	itk::HeavisideStepFunction<>::Pointer heaviside = itk::HeavisideStepFunction<>::New();

	int x1 = -1;
	int x2 = 0;
	int x3 = 1;

	std::cout << "f(" << x1 << ") = " << heaviside->Evaluate(x1) << std::endl;
	std::cout << "f(" << x2 << ") = " << heaviside->Evaluate(x2) << std::endl;
	std::cout << "f(" << x3 << ") = " << heaviside->Evaluate(x3) << std::endl;
	std::cout << std::endl;

	std::cout << "f'(" << x1 << ") = " << heaviside->EvaluateDerivative(x1) << std::endl;
	std::cout << "f'(" << x2 << ") = " << heaviside->EvaluateDerivative(x2) << std::endl;
	std::cout << "f'(" << x3 << ") = " << heaviside->EvaluateDerivative(x3) << std::endl;
}