#include <itkMemoryUsageObserver.h>

void MemoryUsageObserverTest()
{
	itk::MemoryUsageObserver memory;

	//char a[1024 * 100] = { 0 };

	std::cout << "MemoryUsage:" << memory.GetMemoryUsage() << std::endl;
}