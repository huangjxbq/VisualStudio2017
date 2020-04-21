#include "Point.h"
#include <itkPoint.h>

using DoublePoint2D = itk::Point<double, 2>;
using FloatPoint2D = itk::Point<float, 2>;
using IntPoint2D = itk::Point<int, 2>;

//构造，赋值，访问 见FixedArray

void ArithmeticTest();  //四则运算

void BarycentricTest(); //质心

void DistanceTest();    //距离

void CastFromTest();    //转换

void SwapTest();        //交换

void PointTest()
{
	//ArithmeticTest();
	//BarycentricTest();
	//DistanceTest();
	//CastFromTest();
	SwapTest();
}

void ArithmeticTest()
{
	//1.  点 +/- 向量 = 点
	IntPoint2D point;
	point[0] = 1;
	point[1] = 2;

	IntPoint2D::VectorType vector1;
	vector1[0] = 2;
	vector1[1] = 2;

	IntPoint2D::VectorType vector2;
	vector2[0] = 1;
	vector2[1] = 3;

	std::cout <<  point << std::endl;
	point += vector1;
	std::cout << point << std::endl;
	point -= vector2;
	std::cout <<  point << std::endl;

	//2.点 - 点 = 向量
	IntPoint2D point2;
	point2[0] = 1;
	point2[1] = 2;

	std::cout << point2 - point << std::endl;

	//3. 点 - 原点 = 向量
	std::cout << point2.GetVectorFromOrigin() << std::endl;
}

void BarycentricTest()
{
	DoublePoint2D point1;
	point1[0] = 1.4;
	point1[1] = 2.6;

	DoublePoint2D point2;
	point2[0] = 5.3;
	point2[1] = -2.3;

	DoublePoint2D point3;
	point3[0] = 6.4;
	point3[1] = 7.8;

	DoublePoint2D point;

	//取两个点的中点(p1 * 0.5 + p2 * 0.5)
	point.SetToMidPoint(point1, point2);   
	std::cout << point << std::endl;

	//p1 * 0.2 + p2 * 0.8
	point.SetToBarycentricCombination(point1, point2, 0.2); 
	std::cout << point << std::endl;

	//p1 * 0.1 + p2 * 0.2 + p3 * 0.7
	point.SetToBarycentricCombination(point1, point2, point3, 0.1, 0.2);
	std::cout << point << std::endl;


	// p1 * w1 + p2 * w2 + ... + pn * wn  (其中w1 + w2 + ... + wn = 1)
	DoublePoint2D points[10];
	double weight[10] = { 0.12, 0.01, 0.02, 0.05, 0.32, 0.06, 0.24, 0.12, 0.04 };

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < DoublePoint2D::Length; j++)
		{
			points[i][j] = sin(2 * i + j);	
		}
		std::cout << points[i] << std::endl;
	}
	point.SetToBarycentricCombination(points, weight, 10);
	std::cout << point << std::endl;
}

void DistanceTest()
{
	IntPoint2D point;
	point[0] = 1;
	point[1] = 1;

	DoublePoint2D point2;
	point2[0] = 1.1;
	point2[1] = 1.1;

	std::cout << "欧式距离的平方:" << point.SquaredEuclideanDistanceTo(point2) << std::endl;
	std::cout << "欧式距离:" << point.EuclideanDistanceTo(point2) << std::endl;
}

void CastFromTest()
{
	DoublePoint2D point2;
	point2[0] = 1.1;
	point2[1] = 1.1;

	IntPoint2D point;
	point.CastFrom(point2);
	std::cout << point << std::endl;
}

void SwapTest()
{
	DoublePoint2D point1;
	point1[0] = 1.4;
	point1[1] = 2.6;

	DoublePoint2D point2;
	point2[0] = 5.3;
	point2[1] = -2.3;

	itk::swap(point1, point2); //交换内存中的内容

}