#include <itkMapContainer.h>

using DoubleMapContainer = itk::MapContainer<itk::IdentifierType, double>;

void MapContainerTest()
{
	DoubleMapContainer::Pointer map = DoubleMapContainer::New();

	map->Reserve(10);

	for (size_t i = 0; i < 10; i++)
	{
		map->SetElement(i, i);
	}

	std::cout << map->Size() << std::endl;


	map->Initialize();
	std::cout << map->Size() << std::endl;

	map.Print(std::cout);


	map->CastToSTLContainer();
}