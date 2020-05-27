#include <iostream>
#include <itkMath.h>

int main()
{
	int res = 0;
	res = itk::Math::RoundHalfIntegerToEven<int, double>(1.5);
	res = itk::Math::RoundHalfIntegerToEven<int, double>(2.5);
	res = itk::Math::RoundHalfIntegerToEven<int, double>(3.4);
	res = itk::Math::RoundHalfIntegerToEven<int, double>(3.6);

	res = itk::Math::RoundHalfIntegerUp<int, double>(1.5);
	res = itk::Math::RoundHalfIntegerUp<int, double>(2.5);
	res = itk::Math::RoundHalfIntegerUp<int, double>(-1.5);

	res = itk::Math::Round<int, double>(1.5);
	res = itk::Math::Round<int, double>(2.5);
	res = itk::Math::Round<int, double>(-1.5);

	//向下取整
	res = itk::Math::Floor<int, double>(3.8);
	res = itk::Math::Floor<int, double>(2.8);
	res = itk::Math::Floor<int, double>(1.8);
	res = itk::Math::Floor<int, double>(-1.2);
	res = itk::Math::Floor<int, double>(-2.2);

	//向上取整
	res = itk::Math::Ceil<int, double>(3.5);
	res = itk::Math::Ceil<int, double>(2.5);
	res = itk::Math::Ceil<int, double>(1.5);
	res = itk::Math::Ceil<int, double>(-1.5);
	res = itk::Math::Ceil<int, double>(-2.5);

	//数据类型转换
	try
	{
		res = itk::Math::CastWithRangeCheck<unsigned short, unsigned int>(INT32_MAX);
	}
	catch (const itk::ExceptionObject& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	//浮点型比较大小
	std::cout << itk::Math::FloatDifferenceULP<double>(1.4, 1.3) << std::endl;

	std::cout << itk::Math::FloatAlmostEqual<float>(1.3123123f, 1.3123124f) << std::endl;





	system("pause");
}