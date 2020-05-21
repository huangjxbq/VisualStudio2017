#include <itkRGBPixel.h>
#include <itkImageFileReader.h>
#include <itkJPEGImageIO.h>
#include <itkImageRandomConstIteratorWithIndex.h>
#include <itkImageRandomIteratorWithIndex.h>
#include <itkImageRandomConstIteratorWithOnlyIndex.h>
#include <itkImageRandomNonRepeatingConstIteratorWithIndex.h>
#include <itkImageRandomNonRepeatingIteratorWithIndex.h>

using PixelType = itk::RGBPixel<>;
using ImgaeType = itk::Image<PixelType, 2>;
using ImageFileReaderType = itk::ImageFileReader<ImgaeType>;
using ImageIOType = itk::JPEGImageIO;

void ImageRandomConstIteratorWithIndexTest()
{
	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();
	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\test.jpg");
	reader->Update();

	using ImageRandomConstIteratorType = itk::ImageRandomConstIteratorWithIndex<ImgaeType>;
	using ImageRandomIteratorType = itk::ImageRandomIteratorWithIndex<ImgaeType>;

	ImageRandomConstIteratorType const_it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());

	//设置迭代器位置1 (设置到开始)
	const_it.GoToBegin();

	//设置迭代器位置2 (设置到中间某一位置)
	/*ImageRandomConstIteratorType::IndexType index;
	index[0] = 2;
	index[1] = 2;
	const_it.SetIndex(index);*/

	//设置迭代器位置3 (设置到结束)
	//const_it.GoToEnd();

	const_it.SetNumberOfSamples(16);   //设置数量

	while (!const_it.IsAtEnd())
	{
		std::cout << const_it.GetIndex() << ":" << const_it.Get() << " " << const_it.Value() << std::endl;
		++const_it;
	}


	ImageRandomIteratorType it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	it.GoToBegin();
	it.SetNumberOfSamples(16);
	while (!it.IsAtEnd())
	{
		//std::cout << it.GetIndex() << ":" << it.Get() << " " << it.Value() << std::endl;
		ImageRandomIteratorType::PixelType pixel;
		pixel[0] = 0;
		pixel[1] = 0;
		pixel[2] = 0;
		it.Set(pixel);
		++it;
	}

	ImageRandomConstIteratorType const_it2(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	const_it2.GoToBegin();
	const_it2.SetNumberOfSamples(16);
	while (!const_it2.IsAtEnd())
	{
		std::cout << const_it2.GetIndex() << ":" << const_it2.Get() << " " << const_it2.Value() << std::endl;
		++const_it2;
	}
}

void ImageRandomConstIteratorWithOnlyIndexTest()
{
	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();
	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\test.jpg");
	reader->Update();

	using ImageRandomConstIteratorType = itk::ImageRandomConstIteratorWithOnlyIndex<ImgaeType>;

	ImageRandomConstIteratorType const_it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());

	//设置迭代器位置1 (设置到开始)
	const_it.GoToBegin();

	//设置迭代器位置2 (设置到中间某一位置)
	/*ImageRandomConstIteratorType::IndexType index;
	index[0] = 2;
	index[1] = 2;
	const_it.SetIndex(index);*/

	//设置迭代器位置3 (设置到结束)
	//const_it.GoToEnd();

	const_it.SetNumberOfSamples(16);   //设置数量

	while (!const_it.IsAtEnd())
	{
		std::cout << const_it.GetIndex() << std::endl;
		++const_it;
	}
}

void ImageRandomNonRepeatingConstIteratorWithIndexTest()
{
	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	ImageIOType::Pointer io = ImageIOType::New();
	reader->SetImageIO(io);
	reader->SetFileName("D:\\huangjx\\resource\\test.jpg");
	reader->Update();

	using ImageRandomConstIteratorType = itk::ImageRandomNonRepeatingConstIteratorWithIndex<ImgaeType>;
	using ImageRandomIteratorType = itk::ImageRandomNonRepeatingIteratorWithIndex<ImgaeType>;

	ImageRandomConstIteratorType const_it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	const_it.SetNumberOfSamples(16);   //设置数量

	//设置迭代器位置1 (设置到开始)
	const_it.GoToBegin();

	//设置迭代器位置2 (设置到中间某一位置)
	/*ImageRandomConstIteratorType::IndexType index;
	index[0] = 2;
	index[1] = 2;
	const_it.SetIndex(index);*/

	//设置迭代器位置3 (设置到结束)
	//const_it.GoToEnd();


	while (!const_it.IsAtEnd())
	{
		std::cout << const_it.GetIndex() << ":" << const_it.Get() << " " << const_it.Value() << std::endl;
		++const_it;
	}


	ImageRandomIteratorType it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	it.SetNumberOfSamples(16);
	it.GoToBegin();
	while (!it.IsAtEnd())
	{
		//std::cout << it.GetIndex() << ":" << it.Get() << " " << it.Value() << std::endl;
		ImageRandomIteratorType::PixelType pixel;
		pixel[0] = 0;
		pixel[1] = 0;
		pixel[2] = 0;
		it.Set(pixel);
		++it;
	}

	ImageRandomConstIteratorType const_it2(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
	const_it2.SetNumberOfSamples(16);
	const_it2.GoToBegin();
	while (!const_it2.IsAtEnd())
	{
		std::cout << const_it2.GetIndex() << ":" << const_it2.Get() << " " << const_it2.Value() << std::endl;
		++const_it2;
	}



}