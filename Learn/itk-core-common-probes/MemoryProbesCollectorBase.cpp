#include <itkMemoryProbesCollectorBase.h>

void MemoryProbesCollectorBaseTest()
{
	itk::MemoryProbesCollectorBase memoryprobescollector;

	memoryprobescollector.Start("memoryprobes1");
	char *a = new char[1024 * 20]{ 0 };
	memoryprobescollector.Stop("memoryprobes1");

	memoryprobescollector.Start("memoryprobes2");
	char *b = new char[1024 * 10]{ 0 };
	memoryprobescollector.Stop("memoryprobes2");

	memoryprobescollector.Start("memoryprobes1");
	delete[]a;
	delete[]b;
	memoryprobescollector.Stop("memoryprobes1");

	memoryprobescollector.JSONReport(std::cout, false);

	memoryprobescollector.Clear();
}