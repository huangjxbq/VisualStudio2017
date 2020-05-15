#include <itkImageBase.h>
#include <itkImage.h>
#include <itkRGBPixel.h>
#include <itkJPEGImageIO.h>
#include <itkImageFileReader.h>

using ImageBase2D = itk::Image<int, 2>;

using OriginType = ImageBase2D::PointType;
using SpacingType = ImageBase2D::SpacingType;
using RegionType = ImageBase2D::RegionType;


void ImageBaseTest()
{
	ImageBase2D::Pointer image = ImageBase2D::New();

	std::cout << "ImageDimension:" << ImageBase2D::GetImageDimension() << std::endl;

	//设置原点
	OriginType origin;
	origin[0] = 1;
	origin[1] = 1;
	image->SetOrigin(origin);

	//设置间隔
	SpacingType spacing;
	spacing[0] = 2;
	spacing[1] = 3;
	image->SetSpacing(spacing);

	//设置区域
	RegionType region;
	RegionType::IndexType index;
	index[0] = 0;
	index[1] = 0;
	RegionType::SizeType size;
	size[0] = 3;
	size[1] = 3;
	region.SetIndex(index);
	region.SetSize(size);
	image->SetRegions(region);

	//设置方向

	//
	image->Initialize();
	image->Allocate();


	//物理坐标 与 索引 的 变换
	ImageBase2D::IndexType index2;
	index2[0] = 1;
	index2[1] = 1;
	std::cout << "" << image->TransformIndexToPhysicalPoint<float>(index2) << std::endl;

	//物理坐标 与 索引 的 变换
	ImageBase2D::PointType point;
	point[0] = 2.1f;
	point[1] = 1.1f;
	std::cout << "" << image->TransformPhysicalPointToIndex<float>(point) << std::endl;


	//image.Print(std::cout);
}



void ImageTest()
{
	using PixelType = itk::RGBPixel<>;
	using ImgaeType = itk::Image<PixelType, 2>;
	using ImageFileReaderType = itk::ImageFileReader<ImgaeType>;
	using ImageIOType = itk::JPEGImageIO;

	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();

	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\lena.jpg");
	reader->Update();

	std::cout << "Origin:" << reader->GetOutput()->GetOrigin() << std::endl;
	std::cout << "Spacing:" << reader->GetOutput()->GetSpacing() << std::endl;
	std::cout << "Direction:" << reader->GetOutput()->GetDirection() << std::endl;
	std::cout << "InverseDirection:" << reader->GetOutput()->GetInverseDirection() << std::endl;

	std::cout << "LargestPossibleRegion:" << reader->GetOutput()->GetLargestPossibleRegion() << std::endl;
	std::cout << "BufferedRegion:" << reader->GetOutput()->GetBufferedRegion() << std::endl;
	std::cout << "RequestedRegion:" << reader->GetOutput()->GetRequestedRegion() << std::endl;

	//std::cout << reader->GetOutput()->GetOffsetTable()[0] << std::endl;
	//std::cout << reader->GetOutput()->GetOffsetTable()[1] << std::endl;
	//std::cout << reader->GetOutput()->GetOffsetTable()[2] << std::endl;
	//std::cout << reader->GetOutput()->GetOffsetTable()[3] << std::endl;

	ImgaeType::IndexType index;
	index[0] = 0;
	index[1] = 0;
	std::cout << reader->GetOutput()->GetPixel(index) << std::endl;
}