#include <itkRealTimeInterval.h>


void RealTimeIntervalTest()
{
	itk::RealTimeInterval rti1(3600 * 12 * 2, 0);
	itk::RealTimeInterval rti2(2, 0);

	std::cout << rti1.GetTimeInDays() << std::endl;
	std::cout << rti1.GetTimeInHours() << std::endl;
	std::cout << rti1.GetTimeInMinutes() << std::endl;
	std::cout << rti1.GetTimeInSeconds() << std::endl;
	std::cout << rti1.GetTimeInMilliSeconds() << std::endl;
	std::cout << rti1.GetTimeInMicroSeconds() << std::endl;

	//+ - 
	std::cout << rti1 + rti2 << std::endl;
	std::cout << rti1 - rti2 << std::endl;

	//±È½Ï
	std::cout << (rti1 < rti2) << std::endl;
}