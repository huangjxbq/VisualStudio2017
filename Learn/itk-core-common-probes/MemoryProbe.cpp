#include <itkMemoryProbe.h>

void MemoryProbeTest()
{
	itk::MemoryProbe memoryprobe;

	//ResourceProbe
	memoryprobe.SetNameOfProbe("memoryprobe1");

	memoryprobe.Start();
	char *a = new char[1024 * 10]{ 0 };   //只能检测用new开辟的内存
	memoryprobe.Stop();

	memoryprobe.Start();
	char *b = new char[1024 * 20]{ 0 };
	memoryprobe.Stop();

	memoryprobe.Start();
	char *c = new char[1024 * 30]{ 0 };
	memoryprobe.Stop();

	memoryprobe.Start();
	delete[]a;
	delete[]b;
	delete[]c;
	memoryprobe.Stop();

	//基本信息
	std::cout << "Type:" << memoryprobe.GetType() << std::endl;
	std::cout << "Unit:" << memoryprobe.GetUnit() << std::endl;
	std::cout << "Name:" << memoryprobe.GetNameOfProbe() << std::endl;
	std::cout << "Total:" << memoryprobe.GetTotal() << std::endl;
	std::cout << "Mean:" << memoryprobe.GetMean() << std::endl;
	std::cout << "NumberOfStarts:" << memoryprobe.GetNumberOfStarts() << std::endl;
	std::cout << "NumberOfStops:" << memoryprobe.GetNumberOfStops() << std::endl;
	std::cout << "NumberOfIteration:" << memoryprobe.GetNumberOfIteration() << std::endl;
	std::cout << "Minimum:" << memoryprobe.GetMinimum() << std::endl;
	std::cout << "Maximum:" << memoryprobe.GetMaximum() << std::endl;
	std::cout << "StandardDeviation:" << memoryprobe.GetStandardDeviation() << std::endl;
	std::cout << "StandardError:" << memoryprobe.GetStandardError() << std::endl;

	//Repport
	//memoryprobe.JSONReport(std::cout);
	//memoryprobe.Report(std::cout, false, true, false);
	//memoryprobe.ExpandedReport(std::cout, false, true, false);

	//PrintSystemInformation
	//memoryprobe.PrintSystemInformation(std::cout);
	//memoryprobe.PrintJSONSystemInformation(std::cout);
}