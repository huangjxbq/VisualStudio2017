#include "OptimizerParameters.h"
#include <itkOptimizerParameters.h>

using DoubleOptimizerParameters = itk::OptimizerParameters<double>;
using FloatOptimizerParameters = itk::OptimizerParameters<float>;
using IntOptimizerParameters = itk::OptimizerParameters<int>;

using OptimizerParametersType = IntOptimizerParameters;
using OptimizerParametersHelperType = OptimizerParametersType::OptimizerParametersHelperType;


void OptimizerParametersTest()
{
	OptimizerParametersType::ValueType *data = new OptimizerParametersType::ValueType[5]{ 0, 1, 2, 3, 4 };
	OptimizerParametersType optimizerParameters(5);
	optimizerParameters.MoveDataPointer(data);
	std::cout << optimizerParameters << std::endl;
	delete[]data;
}