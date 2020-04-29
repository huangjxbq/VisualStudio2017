#include <itkBinaryThresholdSpatialFunction.h>
#include <itkGaussianSpatialFunction.h>

void BinaryThresholdSpatialFunctionTest()
{
	using InternalFuntion = itk::GaussianSpatialFunction<double, 1>;
	using ArrayType = InternalFuntion::ArrayType;

	using FunctionType = itk::BinaryThresholdSpatialFunction<InternalFuntion>;
	using InputType = FunctionType::InputType;
	using OutputType = FunctionType::OutputType;

	InternalFuntion::Pointer internal = InternalFuntion::New();
	FunctionType::Pointer fun = FunctionType::New();

	ArrayType sigma;
	sigma[0] = 1;

	ArrayType mean;
	mean[0] = 0;

	internal->SetScale(1);
	internal->SetSigma(sigma);
	internal->SetMean(mean);


	fun->SetFunction(internal);
	fun->SetUpperThreshold(0.5);
	fun->SetLowerThreshold(0);

	InputType point1;
	point1[0] = 0;

	std::cout << "f(" << point1 << ") = " << fun->Evaluate(point1) << std::endl;

	InputType point2;
	point2[0] = 5;

	std::cout << "f(" << point2 << ") = " << fun->Evaluate(point2) << std::endl;
}