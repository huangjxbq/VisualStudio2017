#include "ValarrayImageContainer.h"
#include <itkValarrayImageContainer.h>
#include <itkIntTypes.h>

using DoubleValarrayImageContainerType = itk::ValarrayImageContainer<itk::IdentifierType, double>;

using DoubleValarrayImageContainerElement = DoubleValarrayImageContainerType::Element;
using DoubleValarrayImageContainerIdentifier = DoubleValarrayImageContainerType::ElementIdentifier;

void ValarrayImageContainerTest()
{
	DoubleValarrayImageContainerType::Pointer doublevalarray = DoubleValarrayImageContainerType::New();
	doublevalarray->Reserve(5);
	doublevalarray->Fill(2);
	doublevalarray->operator[](1) = 10;
	doublevalarray->Print(std::cout);

	for (DoubleValarrayImageContainerIdentifier i = 0; i < doublevalarray->Size(); i++)
	{
		DoubleValarrayImageContainerElement element = (doublevalarray->operator[](i));
		std::cout << element << " ";
	}
	std::cout << std::endl;
}