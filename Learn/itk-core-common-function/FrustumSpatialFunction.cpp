#include <itkFrustumSpatialFunction.h>

void FrustumSpatialFunctionTest()
{
	using FunctionType = itk::FrustumSpatialFunction<>;
	using InputType = FunctionType::InputType;
	using OutputType = FunctionType::OutputType;


	FunctionType::Pointer fun = FunctionType::New();

	InputType center;
	center[0] = 0;
	center[1] = 0;
	center[2] = 0;




}