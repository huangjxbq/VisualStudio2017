#include <itkVectorContainer.h>

using DoubleVectorContainer = itk::VectorContainer<itk::IdentifierType, double>;
using IntVectorContainer = itk::VectorContainer<itk::IdentifierType, int>;

void VectorContainerTest()
{
	IntVectorContainer::Pointer intvector = IntVectorContainer::New();

	intvector->Reserve(10);

	for (size_t i = 0; i < 10; i++)
	{
		intvector->SetElement(i, i);
	}

	std::cout << intvector->Size() << std::endl;


	intvector->Initialize();
	std::cout << intvector->Size() << std::endl;

	intvector.Print(std::cout);


	intvector->CastToSTLContainer();
}