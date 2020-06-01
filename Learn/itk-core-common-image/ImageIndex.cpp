#include <itkIndex.h>
#include <itkIndexRange.h>

void ImageIndex()
{
	itk::Index<2> index = { {0, 1} };

	std::cout << index << std::endl;

	itk::Index<2> index2{ {2, 3} };

	std::cout << index2 << std::endl;


	itk::Size<2> size{ { 4, 5 } };

	itk::Experimental::ImageRegionIndexRange<2> indexrange(size);

	for (const itk::Index<2> index : indexrange)
	{
		std::cout << index;
	}




}