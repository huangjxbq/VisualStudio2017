#include <itkRGBPixel.h>
#include <itkImageFileReader.h>
#include <itkJPEGImageIO.h>
#include <itkImageSliceConstIteratorWithIndex.h>
#include <itkImageSliceIteratorWithIndex.h>

using PixelType = itk::RGBPixel<>;
using ImgaeType = itk::Image<PixelType, 2>;
using ImageFileReaderType = itk::ImageFileReader<ImgaeType>;
using ImageIOType = itk::JPEGImageIO;

void ImageSliceConstIteratorWithIndexTest()
{
	try
	{
		ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
		ImageIOType::Pointer io = ImageIOType::New();
		reader->SetImageIO(io);
		reader->SetFileName("D:\\huangjx\\resource\\test.jpg");
		reader->Update();

		using ImageSliceConstIteratorType = itk::ImageSliceConstIteratorWithIndex<ImgaeType>;
		using ImageSliceIteratorType = itk::ImageSliceIteratorWithIndex<ImgaeType>;

		ImageSliceConstIteratorType const_it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());

		//���õ�����λ��1 (���õ���ʼ)
		const_it.GoToBegin();

		//���õ�����λ��2 (���õ��м�ĳһλ��)
		ImageSliceConstIteratorType::IndexType index;
		index[0] = 2;
		index[1] = 2;
		//const_it.SetIndex(index);

		//���õ�����λ��3 (���õ�����)
		//const_it.GoToEnd();

		const_it.SetFirstDirection(0);
		const_it.SetSecondDirection(1);

		while (!const_it.IsAtEnd())
		{
			while (!const_it.IsAtEndOfSlice())
			{
				while (!const_it.IsAtEndOfLine())
				{
					std::cout << const_it.GetIndex() << ":" << const_it.Get() << " " << const_it.Value() << std::endl;
					++const_it;
				}
				const_it.NextLine();
			}
			const_it.NextSlice();
		}

		ImageSliceIteratorType it(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
		it.SetFirstDirection(0);
		it.SetSecondDirection(1);
		it.SetIndex(index);
		while (!it.IsAtEnd())
		{
			while (!it.IsAtEndOfSlice())
			{
				while (!it.IsAtEndOfLine())
				{
					//std::cout << it.GetIndex() << ":" << it.Get() << " " << it.Value() << std::endl;
					ImageSliceIteratorType::PixelType pixel;
					pixel[0] = 0;
					pixel[1] = 0;
					pixel[2] = 0;
					it.Set(pixel);
					++it;
				}
				it.NextLine();
			}
			it.NextSlice();
		}


		ImageSliceConstIteratorType const_it2(reader->GetOutput(), reader->GetOutput()->GetRequestedRegion());
		const_it2.GoToBegin();
		const_it2.SetFirstDirection(0);
		const_it2.SetSecondDirection(1);

		while (!const_it2.IsAtEnd())
		{
			while (!const_it2.IsAtEndOfSlice())
			{
				while (!const_it2.IsAtEndOfLine())
				{
					std::cout << const_it2.GetIndex() << ":" << const_it2.Get() << " " << const_it2.Value() << std::endl;
					++const_it2;
				}
				const_it2.NextLine();
			}
			const_it2.NextSlice();
		}



	}
	catch (const itk::ExceptionObject &e)
	{
		std::cout << e.GetDescription() << std::endl;
	}
}