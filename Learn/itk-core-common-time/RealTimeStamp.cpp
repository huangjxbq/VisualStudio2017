#include <itkRealTimeStamp.h>
#include <itkRealTimeClock.h>


void RealTimeStampTest()
{
	itk::RealTimeClock::Pointer clock = itk::RealTimeClock::New();

	itk::RealTimeStamp currenttime = clock->GetRealTimeStamp();

	std::cout << clock->GetTimeInSeconds() << std::endl;

	std::cout << "Frequency:" << clock->GetFrequency() << std::endl;

	//itk::RealTimeInterval rti(3600 * 24 * 365 * 50, 0);



	std::cout << currenttime << std::endl;
}