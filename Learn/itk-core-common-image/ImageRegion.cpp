#include <itkImageRegion.h>

void ImageRegionTest()
{
	using ImageRegionType = itk::ImageRegion<2>;

	std::cout << "ImageDimension:" << ImageRegionType::ImageDimension << std::endl;
	std::cout << "SliceDimension:" << ImageRegionType::SliceDimension << std::endl;
	std::cout << "GetImageDimension:" << ImageRegionType::GetImageDimension() << std::endl;

	//设置region
	ImageRegionType region;
	region.SetIndex(0, 0);
	region.SetIndex(1, 0);
	region.SetSize(0, 2);
	region.SetSize(1, 3);

	//设置region
	region.SetIndex(0, 1);
	region.SetIndex(1, 1);
	ImageRegionType::IndexType upperindex;
	upperindex[0] = 5;
	upperindex[1] = 5;
	region.SetUpperIndex(upperindex);


	std::cout << region.GetRegionType() << std::endl;
	std::cout << "UpperIndex:" << region.GetUpperIndex() << std::endl;


	//检测索引是否在 区域内
	ImageRegionType::IndexType index1;
	index1[0] = 5;
	index1[1] = 5;

	ImageRegionType::IndexType index2;
	index2[0] = 6;
	index2[1] = 6;

	std::cout << "index1:" << index1 << " isinside:" << region.IsInside(index1) << std::endl;
	std::cout << "index2:" << index2 << " isinside:" << region.IsInside(index2) << std::endl;

	//检查连续索引是否在区域内
	using ContinuousIndexType = itk::ContinuousIndex<float, ImageRegionType::ImageDimension>;

	ContinuousIndexType cindex1;
	cindex1[0] = 4.5;
	cindex1[1] = 4.5;

	ContinuousIndexType cindex2;
	cindex2[0] = 5.6;
	cindex2[1] = 5.6;

	std::cout << "cindex1:" << cindex1 << " isinside:" << region.IsInside(cindex1) << std::endl;
	std::cout << "cindex2:" << cindex2 << " isinside:" << region.IsInside(cindex2) << std::endl;

	//检查区域是否在本区域内


	//扩展区域 
	ImageRegionType::SizeType size;
	size[0] = 2;
	size[1] = 2;
	region.Print(std::cout);
	region.PadByRadius(size);
	region.Print(std::cout);

	//收缩区域


}