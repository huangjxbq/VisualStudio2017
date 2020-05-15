#include <itkImageRegionConstIterator.h>
#include <itkImageRegionIterator.h>
#include <itkRGBPixel.h>
#include <itkImageFileReader.h>
#include <itkJPEGImageIO.h>

void ImageRegionConstIteratorTest()
{
	using PixelType = itk::RGBPixel<>;
	using ImgaeType = itk::Image<PixelType, 2>;
	using ImageFileReaderType = itk::ImageFileReader<ImgaeType>;
	using ImageIOType = itk::JPEGImageIO;

	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();

	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\test.jpg");
	reader->Update();

	using ImageRegionConstIteratorType = itk::ImageRegionConstIterator<ImgaeType>;
	using ImageRegionIteratorType = itk::ImageRegionIterator<ImgaeType>;

	ImageRegionConstIteratorType::RegionType region;
	region.SetIndex(0, 1);
	region.SetIndex(1, 2);
	region.SetSize(0, 2);
	region.SetSize(1, 1);

	//ImageRegionConstIteratorType image_region_it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	ImageRegionConstIteratorType image_region_it(reader->GetOutput(), region);



	//设置迭代器位置1 (设置到开始)
	image_region_it.GoToBegin();

	//设置迭代器位置2 (设置到中间某一位置)
	//ImageRegionConstIteratorType::IndexType index;
	//index[0] = 1;
	//index[1] = 1;
	//image_region_it.SetIndex(index);

	//设置迭代器位置3 (设置到结束)
	//image_region_it.GoToEnd();
	while (!image_region_it.IsAtEnd())
	{
		std::cout << image_region_it.GetIndex() << ":" << image_region_it.Get() << " " << image_region_it.Value() << std::endl;
		++image_region_it;
	}


	ImageRegionIteratorType it(reader->GetOutput(), region);
	it.GoToBegin();
	while (!it.IsAtEnd())
	{
		std::cout << it.GetIndex() << ":" << it.Get() << " " << it.Value() << std::endl;
		ImageRegionIteratorType::PixelType pixel;
		pixel[0] = 0;
		pixel[1] = 0;
		pixel[2] = 0;
		it.Set(pixel);
		++it;
	}

	image_region_it.GoToBegin();
	while (!image_region_it.IsAtEnd())
	{
		std::cout << image_region_it.GetIndex() << ":" << image_region_it.Get() << " " << image_region_it.Value() << std::endl;
		++image_region_it;
	}
}