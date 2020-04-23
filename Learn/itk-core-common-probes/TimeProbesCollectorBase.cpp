#include <itkTimeProbesCollectorBase.h>

void TimeProbesCollectorBaseTest()
{
	itk::TimeProbesCollectorBase timeprobescollector;

	timeprobescollector.Start("timeprobes1");
	Sleep(1000);
	timeprobescollector.Stop("timeprobes1");

	timeprobescollector.Start("timeprobes2");
	Sleep(1500);
	timeprobescollector.Stop("timeprobes2");

	timeprobescollector.Start("timeprobes1");
	Sleep(500);
	timeprobescollector.Stop("timeprobes1");

	timeprobescollector.JSONReport(std::cout, false);

	timeprobescollector.Clear();
}