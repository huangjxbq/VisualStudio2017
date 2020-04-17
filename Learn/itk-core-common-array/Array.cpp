#include "Array.h"
#include <itkArray.h>

using DoubleArrayType = itk::Array<double>;
using FloatArrayType = itk::Array<float>;
using IntArrayType = itk::Array<int>;
using ArrayType = IntArrayType;

void ArrayTest()
{
	//{
	//	ArrayType array;
	//	array.SetSize(3);
	//	array.SetElement(0, 1);
	//	
	//	std::cout << array << std::endl;
	//}

	//{
	//	ArrayType array(4);
	//	array.Fill(0);
	//	std::cout << array << std::endl;
	//}

	ArrayType::ValueType data[] = { 1, 2, 3, 4, 5, 6, 7 };
	ArrayType::ValueType *data2 = new ArrayType::ValueType[10]{ 1, 2, 3, 4 };
	{
		ArrayType array(data2, 4, false);
		std::cout << array << std::endl;
	}
}