#include <itkRGBPixel.h>
#include <itkImageFileReader.h>
#include <itkJPEGImageIO.h>
#include <itkImageRegionConstIterator.h>
#include <itkImageRegionIterator.h>
#include <itkImageRegionConstIteratorWithIndex.h>
#include <itkImageRegionIteratorWithIndex.h>
#include <itkImageRegionConstIteratorWithOnlyIndex.h>
#include <itkImageRegionExclusionConstIteratorWithIndex.h>
#include <itkImageRegionExclusionIteratorWithIndex.h>
#include <itkImageRegionReverseConstIterator.h>
#include <itkImageRegionReverseIterator.h>

using PixelType = itk::RGBPixel<>;
using ImgaeType = itk::Image<PixelType, 2>;
using ImageFileReaderType = itk::ImageFileReader<ImgaeType>;
using ImageIOType = itk::JPEGImageIO;


void ImageRegionConstIteratorTest()
{
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

void ImageRegionConstIteratorWithIndexTest()
{
	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();

	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\test.jpg");
	reader->Update();

	using ImageRegionConstIteratorType = itk::ImageRegionConstIteratorWithIndex<ImgaeType>;
	using ImageRegionIteratorType = itk::ImageRegionIteratorWithIndex<ImgaeType>;

	ImageRegionConstIteratorType::RegionType region;
	region.SetIndex(0, 1);
	region.SetIndex(1, 2);
	region.SetSize(0, 2);
	region.SetSize(1, 1);

	ImageRegionConstIteratorType image_region_it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	//ImageRegionConstIteratorType image_region_it(reader->GetOutput(), region);


	//设置迭代器位置1 (设置到开始)
	image_region_it.GoToBegin();

	//设置迭代器位置2 (设置到中间某一位置)
	/*ImageRegionConstIteratorType::IndexType index;
	index[0] = 1;
	index[1] = 1;
	image_region_it.SetIndex(index);*/

	//设置迭代器位置3 (设置到结束)
	//image_region_it.GoToReverseBegin();

	while (image_region_it.Remaining())
	{
		std::cout << image_region_it.GetIndex() << ":" << image_region_it.Get() << " " << image_region_it.Value() << std::endl;
		++image_region_it;
	}


	ImageRegionIteratorType it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	it.GoToBegin();
	while (it.Remaining())
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
	while (image_region_it.Remaining())
	{
		std::cout << image_region_it.GetIndex() << ":" << image_region_it.Get() << " " << image_region_it.Value() << std::endl;
		++image_region_it;
	}
}

void ImageRegionExclusionConstIteratorWithIndexTest()
{
	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();

	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\test.jpg");
	reader->Update();

	using ImageRegionConstIteratorType = itk::ImageRegionExclusionConstIteratorWithIndex<ImgaeType>;
	using ImageRegionIteratorType = itk::ImageRegionExclusionIteratorWithIndex<ImgaeType>;

	ImageRegionConstIteratorType::RegionType region;
	region.SetIndex(0, 1);
	region.SetIndex(1, 1);
	region.SetSize(0, 3);
	region.SetSize(1, 3);

	ImageRegionConstIteratorType image_region_it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	//ImageRegionConstIteratorType image_region_it(reader->GetOutput(), region);


	//设置迭代器位置1 (设置到开始)
	image_region_it.GoToBegin();

	//设置迭代器位置2 (设置到中间某一位置)
	/*ImageRegionConstIteratorType::IndexType index;
	index[0] = 1;
	index[1] = 1;
	image_region_it.SetIndex(index);*/

	//设置迭代器位置3 (设置到结束)
	//image_region_it.GoToReverseBegin();

	image_region_it.SetExclusionRegion(region);

	image_region_it.SetExclusionRegionToInsetRegion();

	while (image_region_it.Remaining())
	{
		std::cout << image_region_it.GetIndex() << ":" << image_region_it.Get() << " " << image_region_it.Value() << std::endl;
		++image_region_it;
	}


	ImageRegionIteratorType it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	it.GoToBegin();
	it.SetExclusionRegion(region);
	while (it.Remaining())
	{
		//std::cout << it.GetIndex() << ":" << it.Get() << " " << it.Value() << std::endl;
		ImageRegionIteratorType::PixelType pixel;
		pixel[0] = 0;
		pixel[1] = 0;
		pixel[2] = 0;
		it.Set(pixel);
		++it;
	}

	ImageRegionConstIteratorType image_region_it2(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	image_region_it2.GoToBegin();
	while (image_region_it2.Remaining())
	{
		std::cout << image_region_it2.GetIndex() << ":" << image_region_it2.Get() << " " << image_region_it2.Value() << std::endl;
		++image_region_it2;
	}
}

void ImageRegionConstIteratorWithOnlyIndexTest()
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

	using ImageRegionConstIteratorType = itk::ImageRegionConstIteratorWithOnlyIndex<ImgaeType>;
	//using ImageRegionIteratorType = itk::ImageRegionIteratorWithIndex<ImgaeType>;

	ImageRegionConstIteratorType::RegionType region;
	region.SetIndex(0, 1);
	region.SetIndex(1, 2);
	region.SetSize(0, 2);
	region.SetSize(1, 1);

	ImageRegionConstIteratorType image_region_it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	//ImageRegionConstIteratorType image_region_it(reader->GetOutput(), region);


	//设置迭代器位置1 (设置到开始)
	image_region_it.GoToBegin();

	//设置迭代器位置2 (设置到中间某一位置)
	/*ImageRegionConstIteratorType::IndexType index;
	index[0] = 1;
	index[1] = 1;
	image_region_it.SetIndex(index);*/

	//设置迭代器位置3 (设置到结束)
	//image_region_it.GoToReverseBegin();

	while (image_region_it.Remaining())
	{
		std::cout << image_region_it.GetIndex() << std::endl;
		++image_region_it;
	}
}

void ImageRegionReverseConstIteratorTest()
{
	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();

	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\test.jpg");
	reader->Update();

	using ImageRegionConstIteratorType = itk::ImageRegionReverseConstIterator<ImgaeType>;
	using ImageRegionIteratorType = itk::ImageRegionReverseIterator<ImgaeType>;

	ImageRegionConstIteratorType::RegionType region;
	region.SetIndex(0, 1);
	region.SetIndex(1, 2);
	region.SetSize(0, 2);
	region.SetSize(1, 1);

	ImageRegionConstIteratorType image_region_it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	//ImageRegionConstIteratorType image_region_it(reader->GetOutput(), region);



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


	ImageRegionIteratorType it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	it.GoToBegin();
	while (!it.IsAtEnd())
	{
		//std::cout << it.GetIndex() << ":" << it.Get() << " " << it.Value() << std::endl;
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