#include <itkGaussianSpatialFunction.h>

void GaussianSpatialFunctionTest()
{
	using FunctionType = itk::GaussianSpatialFunction<double, 1>;
	using InputType = FunctionType::InputType;
	using OutputType = FunctionType::OutputType;
	using ArrayType = FunctionType::ArrayType;


	FunctionType::Pointer fun = FunctionType::New();

	ArrayType sigma;
	sigma[0] = 1;

	ArrayType mean;
	mean[0] = 0;

	fun->SetScale(1);
	fun->SetSigma(sigma);
	fun->SetMean(mean);


	InputType point1;
	point1[0] = 0;

	std::cout << "f(" << point1 << ") = " << fun->Evaluate(point1) << std::endl;

	InputType point2;
	point2[0] = 5;

	std::cout << "f(" << point2 << ") = " << fun->Evaluate(point2) << std::endl;
}