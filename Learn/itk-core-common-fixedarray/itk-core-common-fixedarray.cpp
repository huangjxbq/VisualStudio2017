#include <cstdlib>
#include "FixedArray.h"
#include "Point.h"
#include "Vector.h"
#include "RGBPixel.h"

//1.FixedArray 定长数组  构造、赋值、访问

//2.Vector     向量   继承自FixedArray     四则运算、内积、外积、模长、转换(见Point转换)、交换(见Point交换)

//3.Point      点    继承自FixedArray      运算(点 +/- 向量 = 点、 点 - 点 = 向量)、质心、距离、转换、交换

//4.RGBPixel   RGB   继承自FixedArray     运算、设置获取颜色分量、获取亮度(彩色转黑白)、欧几里得范数(模长)

//5.RGBAPixel  RGBA   继承自FixedArray    见RGBPixel

int main()
{
	//FixedArrayTest();  //定长数组测试

	//PointTest();         //点测试

	//VectorTest();        //向量测试

	RGBPixelTest();

	system("pause");
}