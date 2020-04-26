#include <iostream>
#include <itkMersenneTwisterRandomVariateGenerator.h>


//1.RandomVariateGeneratorBase
//2.MersenneTwisterRandomVariateGenerator


int main()
{
	itk::Statistics::MersenneTwisterRandomVariateGenerator::Pointer random =
		itk::Statistics::MersenneTwisterRandomVariateGenerator::GetInstance();

	std::cout << "[0,1]   " << random->GetVariateWithClosedRange() << std::endl;
	std::cout << "[0,n]   " << random->GetVariateWithClosedRange(2) << std::endl;

	std::cout << "[0,1)   " << random->GetVariateWithOpenUpperRange() << std::endl;
	std::cout << "[0,n)   " << random->GetVariateWithOpenUpperRange(5) << std::endl;

	std::cout << "(0,1)   " << random->GetVariateWithOpenRange() << std::endl;
	std::cout << "(0,n)   " << random->GetVariateWithOpenRange(5) << std::endl;

	std::cout << "[0, 2^32-1]   " << random->GetIntegerVariate() << std::endl;
	std::cout << "[0, n]   " << random->GetIntegerVariate(100) << std::endl;


	std::cout << "[0, 1)   " << random->Get53BitVariate() << std::endl;

	std::cout << "正态分布   " << random->GetNormalVariate() << std::endl;
	std::cout << "均匀分布   " << random->GetUniformVariate(1, 2) << std::endl;

	system("pause");
}