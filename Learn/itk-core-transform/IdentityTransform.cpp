#include <itkIdentityTransform.h>

using IdentityTransformType = itk::IdentityTransform<double, 2>;

//TransformBase
using ParametersType = IdentityTransformType::ParametersType;
using ParametersValueType = IdentityTransformType::ParametersValueType;
using FixedParametersType = IdentityTransformType::FixedParametersType;
using FixedParametersValueType = IdentityTransformType::FixedParametersValueType;
using NumberOfParametersType = IdentityTransformType::NumberOfParametersType;

void IdentityTransform()
{
	IdentityTransformType::Pointer transform = IdentityTransformType::New();

	//TransformBase API
	std::cout << "TransformTypeAsString:" << transform->GetTransformTypeAsString() << std::endl;
	std::cout << "TransformCategory:" << transform->GetTransformCategory() << std::endl;
	std::cout << "NumberOfParameters:" << transform->GetNumberOfParameters() << std::endl;
	std::cout << "InputSpaceDimension:" << transform->GetInputSpaceDimension() << std::endl;
	std::cout << "OutputSpaceDimension:" << transform->GetOutputSpaceDimension() << std::endl;

	//SetParameters GetParameters CopyInParameters 
	//SetFixedParameters GetFixedParameters CopyInFixedParameters
	ParametersValueType data[10] = { 1, 2, 3 };
	ParametersType parameters;
	parameters.SetData(data, 10);

	FixedParametersValueType datafixed[10] = { 1.2, 2.3, 3.1 };
	FixedParametersType parametersfixed;
	parametersfixed.SetData(datafixed, 10);

	std::cout << parameters << std::endl;
	std::cout << parametersfixed << std::endl;

	transform->SetParameters(parameters);
	transform->SetFixedParameters(parametersfixed);

	//transform->CopyInParameters(&data[0], &data[3]);
	//transform->CopyInFixedParameters(datafixed, datafixed + 9);

	std::cout << "NumberOfParameters:" << transform->GetNumberOfParameters() << std::endl;


	//Transform API
	int a = 0;
	int b = 2;
	IdentityTransformType::InputPointType point{ {a, b} };
	std::cout << transform->TransformPoint(point) << std::endl;




	

	//transform->Print(std::cout);
}