#include <iostream>
#include <itkBresenhamLine.h>

int main()
{
	itk::BresenhamLine<2> line;

	itk::BresenhamLine<2>::IndexType index1;
	itk::BresenhamLine<2>::IndexType index2;
	index1[0] = 0; index1[1] = 0;
	index2[0] = 5; index2[1] = 10;
	itk::BresenhamLine<2>::IndexArray indexs = line.BuildLine(index1, index2);
	for (size_t i = 0; i < indexs.size(); i++)
	{
		//std::cout << indexs[i] << std::endl;
	}

	itk::BresenhamLine<2>::LType l;
	l[0] = 1; l[1] = 2;
	itk::BresenhamLine<2>::OffsetArray offsets = line.BuildLine(l, 10);
	for (size_t i = 0; i < offsets.size(); i++)
	{
		std::cout << offsets[i] << std::endl;
	}

	system("pause");
}