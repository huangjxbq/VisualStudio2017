#include <itkRGBPixel.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkJPEGImageIO.h>
#include <itkImageDuplicator.h>
#include <itkImageAlgorithm.h>
#include <itkImageRegionIterator.h>

using PixelType = itk::RGBPixel<unsigned char>;
using ImageType = itk::Image<PixelType, 2>;
using ImageFileReaderType = itk::ImageFileReader<ImageType>;
using ImageFileWriterType = itk::ImageFileWriter<ImageType>;
using ImageIOType = itk::JPEGImageIO;

void ImageCopyRegion()
{
	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();
	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\lena.jpg");
	reader->Update();

	//同一个图像上复制, 区域不重叠
	{
		//ImgaeType::RegionType region_in;
		//region_in.SetIndex(0, 0);
		//region_in.SetIndex(1, 0);
		//region_in.SetSize(0, 256);
		//region_in.SetSize(1, 256);

		//ImgaeType::RegionType region_out;
		//region_out.SetIndex(0, 256);
		//region_out.SetIndex(1, 256);
		//region_out.SetSize(0, 256);
		//region_out.SetSize(1, 256);

		//itk::ImageAlgorithm::Copy<ImgaeType, ImgaeType>(reader->GetOutput(), reader->GetOutput(), region_in, region_out);
	}

	//同一个图像上复制, 区域重叠
	{
		//ImgaeType::RegionType region_in;
		//region_in.SetIndex(0, 0);
		//region_in.SetIndex(1, 0);
		//region_in.SetSize(0, 256);
		//region_in.SetSize(1, 256);

		//ImgaeType::RegionType region_out;
		//region_out.SetIndex(0, 128);
		//region_out.SetIndex(1, 128);
		//region_out.SetSize(0, 256);
		//region_out.SetSize(1, 256);

		//itk::ImageAlgorithm::Copy<ImgaeType, ImgaeType>(reader->GetOutput(), reader->GetOutput(), region_in, region_out);
	
	
	}

	//ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
	////ImageIOType::Pointer io = ImageIOType::New();
	//writer->SetImageIO(io);   //JPEGIO 只能写unsigned char 和 int 类型的2维图像
	//writer->SetInput(reader->GetOutput());
	//writer->SetFileName("D:\\huangjx\\resource\\lena_m.jpg");
	//writer->Update();

	//不同图像上复制
	{
		ImageFileReaderType::Pointer reader2 = ImageFileReaderType::New();
		//ImageIOType::Pointer io = ImageIOType::New();
		reader2->SetImageIO(io);
		reader2->SetFileName("D:\\huangjx\\resource\\12.jpg");
		reader2->Update();

		ImageType::RegionType region_in;
		region_in.SetIndex(0, 0);
		region_in.SetIndex(1, 0);
		region_in.SetSize(0, 256);
		region_in.SetSize(1, 256);

		ImageType::RegionType region_out;
		region_out.SetIndex(0, 128);
		region_out.SetIndex(1, 128);
		region_out.SetSize(0, 256);
		region_out.SetSize(1, 256);

		itk::ImageAlgorithm::Copy<ImageType, ImageType>(reader->GetOutput(), reader2->GetOutput(), region_in, region_out);
	
		ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
		//ImageIOType::Pointer io = ImageIOType::New();
		writer->SetImageIO(io);   //JPEGIO 只能写unsigned char 和 int 类型的2维图像
		writer->SetInput(reader2->GetOutput());
		writer->SetFileName("D:\\huangjx\\resource\\lena_m.jpg");
		writer->Update();
	}
}

void ImageEnlargeRegionOverBox()
{
	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();
	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\lena.jpg");
	reader->Update();

	ImageType::RegionType region;
	ImageType::IndexType index = { 0, 0 };
	ImageType::SizeType size = { 200, 200 };
	region.SetIndex(index);
	region.SetSize(size);



	itk::ImageAlgorithm::EnlargeRegionOverBox(region, reader->GetOutput(), reader->GetOutput()).Print(std::cout);


}

void ImageDuplicator()
{
	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();
	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\lena.jpg");
	reader->Update();

	using DuplicatorType = itk::ImageDuplicator<ImageType>;
	DuplicatorType::Pointer duplicator = DuplicatorType::New();
	duplicator->SetInputImage(reader->GetOutput());
	duplicator->Update();
	ImageType::Pointer clonedImage = duplicator->GetOutput();

	using ImageIterator = itk::ImageRegionIterator<ImageType>;

	ImageIterator it(clonedImage, clonedImage->GetRequestedRegion());


	ImageIterator::IndexType index = { 256, 256 };
	it.SetIndex(index);
	
	while (!it.IsAtEnd())
	{
		ImageIterator::PixelType pixel;
		pixel.Fill(0);
		it.Set(pixel);
		++it;
	}

	ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
	//ImageIOType::Pointer io = ImageIOType::New();
	writer->SetImageIO(io);   //JPEGIO 只能写unsigned char 和 int 类型的2维图像
	writer->SetInput(clonedImage);
	writer->SetFileName("D:\\huangjx\\resource\\lena_clone.jpg");
	writer->Update();

	writer->SetInput(reader->GetOutput());
	writer->SetFileName("D:\\huangjx\\resource\\lena_m.jpg");
	writer->Update();

}