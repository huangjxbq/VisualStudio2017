#include <itkTimeProbe.h>

void TimeProbeTest()
{
	itk::TimeProbe timeprobe;

	//ResourceProbe
	timeprobe.SetNameOfProbe("timeprobe1");

	timeprobe.Start();
	Sleep(1000);
	timeprobe.Stop();

	timeprobe.Start();
	Sleep(2000);
	timeprobe.Stop();

	timeprobe.Start();
	Sleep(3000);
	timeprobe.Stop();


	//基本信息
	std::cout << "Type:" << timeprobe.GetType() << std::endl;
	std::cout << "Unit:" << timeprobe.GetUnit() << std::endl;
	std::cout << "Name:" << timeprobe.GetNameOfProbe() << std::endl;
	std::cout << "Total:" << timeprobe.GetTotal() << std::endl;
	std::cout << "Mean:" << timeprobe.GetMean() << std::endl;
	std::cout << "NumberOfStarts:" << timeprobe.GetNumberOfStarts() << std::endl;
	std::cout << "NumberOfStops:" << timeprobe.GetNumberOfStops() << std::endl;
	std::cout << "NumberOfIteration:" << timeprobe.GetNumberOfIteration() << std::endl;
	std::cout << "Minimum:" << timeprobe.GetMinimum() << std::endl;
	std::cout << "Maximum:" << timeprobe.GetMaximum() << std::endl;
	std::cout << "StandardDeviation:" << timeprobe.GetStandardDeviation() << std::endl;
	std::cout << "StandardError:" << timeprobe.GetStandardError() << std::endl;

	//Repport
	//timeprobe.JSONReport(std::cout);
	//timeprobe.Report(std::cout, false, true, false);
	//timeprobe.ExpandedReport(std::cout, false, true, false);

	//PrintSystemInformation
	//timeprobe.PrintSystemInformation(std::cout);
	//timeprobe.PrintJSONSystemInformation(std::cout);
}