#include <itkImageRegion.h>
#include <itkImageRegionSplitterDirection.h>
#include <itkImageRegionSplitterMultidimensional.h>
#include <itkImageRegionSplitterSlowDimension.h>

void ImageRegionTest()
{
	using ImageRegionType = itk::ImageRegion<2>;

	std::cout << "ImageDimension:" << ImageRegionType::ImageDimension << std::endl;
	std::cout << "SliceDimension:" << ImageRegionType::SliceDimension << std::endl;
	std::cout << "GetImageDimension:" << ImageRegionType::GetImageDimension() << std::endl;

	//����region
	ImageRegionType region;
	region.SetIndex(0, 0);
	region.SetIndex(1, 0);
	region.SetSize(0, 2);
	region.SetSize(1, 3);


	//����region
	region.SetIndex(0, 1);
	region.SetIndex(1, 1);
	ImageRegionType::IndexType upperindex;
	upperindex[0] = 5;
	upperindex[1] = 5;
	region.SetUpperIndex(upperindex);


	std::cout << region.GetRegionType() << std::endl;
	std::cout << "UpperIndex:" << region.GetUpperIndex() << std::endl;


	//��������Ƿ��� ������
	ImageRegionType::IndexType index1;
	index1[0] = 5;
	index1[1] = 5;

	ImageRegionType::IndexType index2;
	index2[0] = 6;
	index2[1] = 6;

	std::cout << "index1:" << index1 << " isinside:" << region.IsInside(index1) << std::endl;
	std::cout << "index2:" << index2 << " isinside:" << region.IsInside(index2) << std::endl;

	//������������Ƿ���������
	using ContinuousIndexType = itk::ContinuousIndex<float, ImageRegionType::ImageDimension>;

	ContinuousIndexType cindex1;
	cindex1[0] = 4.5;
	cindex1[1] = 4.5;

	ContinuousIndexType cindex2;
	cindex2[0] = 5.6;
	cindex2[1] = 5.6;

	std::cout << "cindex1:" << cindex1 << " isinside:" << region.IsInside(cindex1) << std::endl;
	std::cout << "cindex2:" << cindex2 << " isinside:" << region.IsInside(cindex2) << std::endl;

	//��������Ƿ��ڱ�������


	//��չ���� 
	ImageRegionType::SizeType size;
	size[0] = 2;
	size[1] = 2;
	region.Print(std::cout);
	region.PadByRadius(size);
	region.Print(std::cout);

	//��������


}


using ImageRegionSplitterType = itk::ImageRegionSplitterDirection;
//using ImageRegionSplitterType = itk::ImageRegionSplitterMultidimensional;
//using ImageRegionSplitterType = itk::ImageRegionSplitterSlowDimension;

void ImageRegionSplitterTest()
{
	using ImageRegionType = itk::ImageRegion<2>;

	//����region
	ImageRegionType region;
	region.SetIndex(0, 0);
	region.SetIndex(1, 0);
	region.SetSize(0, 5);
	region.SetSize(1, 5);

	ImageRegionSplitterType::Pointer regionsplitter = ImageRegionSplitterType::New();
	
	std::cout << "GetNumberOfSplits:" << regionsplitter->GetNumberOfSplits(region, 10) << std::endl;

	ImageRegionType region2;
	int available = regionsplitter->GetSplit(1, regionsplitter->GetNumberOfSplits(region, 10), region2);

	region2.Print(std::cout);

}