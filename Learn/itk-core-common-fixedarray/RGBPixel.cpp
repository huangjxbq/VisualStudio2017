#include <itkRGBPixel.h>

using DefaultRGBPixelType = itk::RGBPixel<>;

void RGBPixelArithmeticTest();   //运算

void SetGetRGBTest();     //设置获取颜色分量

void LuminanceTest();     //获取亮度(彩色转黑白)

void ScalarValueTest();   //欧几里得范数(模长)

void RGBPixelTest()
{
	//RGBPixelArithmeticTest();
	//SetGetRGBTest();
	//LuminanceTest();
	ScalarValueTest();
}

void RGBPixelArithmeticTest()
{
	DefaultRGBPixelType rgbpixel;
	rgbpixel[0] = 255;
	rgbpixel[1] = 255;
	rgbpixel[2] = 255;

	DefaultRGBPixelType rgbpixel2;
	rgbpixel2[0] = 10;
	rgbpixel2[1] = 10;
	rgbpixel2[2] = 10;

	std::cout << rgbpixel << std::endl;
	std::cout << rgbpixel * 2 << std::endl;
	std::cout << rgbpixel / 2 << std::endl;
	std::cout << rgbpixel + rgbpixel2 << std::endl;
	std::cout << rgbpixel - rgbpixel2 << std::endl;
}

void SetGetRGBTest()
{
	DefaultRGBPixelType rgbpixel;

	//Set
	rgbpixel.Set(100, 50, 20);
	std::cout << rgbpixel << std::endl;

	rgbpixel.SetRed(1);
	rgbpixel.SetGreen(2);
	rgbpixel.SetBlue(3);
	std::cout << rgbpixel << std::endl;

	rgbpixel.SetNthComponent(0, 33);
	rgbpixel.SetNthComponent(1, 44);
	rgbpixel.SetNthComponent(2, 55);
	std::cout << rgbpixel << std::endl;

	//Get
	rgbpixel.GetRed();
	rgbpixel.GetGreen();
	rgbpixel.GetBlue();

	rgbpixel.GetNthComponent(0);
	rgbpixel.GetNthComponent(1);
	rgbpixel.GetNthComponent(2);

}

void LuminanceTest()
{
	DefaultRGBPixelType rgbpixel;
	rgbpixel.Set(100, 50, 20);
	std::cout << "RGB:" << rgbpixel << std::endl;
	std::cout << "Luminance:" << rgbpixel.GetLuminance() << std::endl;
}

void ScalarValueTest()
{
	DefaultRGBPixelType rgbpixel;
	rgbpixel.Set(100, 50, 20);
	std::cout << "RGB:" << rgbpixel << std::endl;
	std::cout << "ScalarValue:" << rgbpixel.GetScalarValue() << std::endl;
}