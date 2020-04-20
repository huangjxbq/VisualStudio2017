#include "Array2D.h"
#include <itkArray2D.h>

using IntArray2DType = itk::Array2D<int>;

void Array2DTest()
{
	IntArray2DType array2d(2, 4);

	for (size_t i = 0; i < array2d.rows(); i++)
	{
		for (size_t j = 0; j < array2d.columns(); j++)
		{
			array2d.SetElement(i, j, 2 * i + j);
		}
	}

	std::cout << array2d << std::endl;
}