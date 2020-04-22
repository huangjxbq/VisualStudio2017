#include <itkTimeStamp.h>

void TimeStampTest()
{
	itk::TimeStamp timestamp1;
	itk::TimeStamp timestamp2;
	itk::TimeStamp timestamp3;

	std::cout << timestamp1.GetMTime() << std::endl;
	std::cout << timestamp2.GetMTime() << std::endl;
	std::cout << timestamp3.GetMTime() << std::endl;

	timestamp1.Modified();

	std::cout << timestamp1.GetMTime() << std::endl;
	std::cout << timestamp2.GetMTime() << std::endl;
	std::cout << timestamp3.GetMTime() << std::endl;

	timestamp2.Modified();

	std::cout << timestamp1.GetMTime() << std::endl;
	std::cout << timestamp2.GetMTime() << std::endl;
	std::cout << timestamp3.GetMTime() << std::endl;

	timestamp3.Modified();

	std::cout << timestamp1.GetMTime() << std::endl;
	std::cout << timestamp2.GetMTime() << std::endl;
	std::cout << timestamp3.GetMTime() << std::endl;

	timestamp1.Modified();

	std::cout << timestamp1.GetMTime() << std::endl;
	std::cout << timestamp2.GetMTime() << std::endl;
	std::cout << timestamp3.GetMTime() << std::endl;
}