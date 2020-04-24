#include <iostream>
#include <itkBresenhamLine.h>

int main()
{
	itk::BresenhamLine<2> line;
	itk::BresenhamLine<2>::IndexType index1;
	itk::BresenhamLine<2>::IndexType index2;
	index1[0] = 0; index1[1] = 0;
	index2[0] = 100; index2[1] = 100;


	itk::BresenhamLine<2>::IndexArray indexs = line.BuildLine(index1, index2);

	for (size_t i = 0; i < indexs.size(); i++)
	{
		std::cout << indexs[i] << std::endl;
	}


	system("pause");
}