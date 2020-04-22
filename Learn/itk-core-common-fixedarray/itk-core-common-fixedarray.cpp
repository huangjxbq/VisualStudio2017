#include <cstdlib>
#include "FixedArray.h"
#include "Point.h"
#include "Vector.h"
#include "RGBPixel.h"
#include "SymmetricSecondRankTensor.h"
#include "DiffusionTensor3D.h"

//1.FixedArray                  定长数组     构造、赋值、访问

//2.Vector                      向量         继承自FixedArray     四则运算、内积、外积、模长、转换(见Point转换)、交换(见Point交换)

//3.CovariantVector             协变向量     继承自FixedArray     函数与Vector相同，用法见Vector

//4.Point                       点          继承自FixedArray     运算(点 +/- 向量 = 点、 点 - 点 = 向量)、质心、距离、转换、交换

//5.ContinuousIndex             连续索引     继承自Point          只能是float或者double

//6.RGBPixel                    RGB        继承自FixedArray      运算、设置获取颜色分量、获取亮度(彩色转黑白)、欧几里得范数(模长)

//7.RGBAPixel                   RGBA       继承自FixedArray      见RGBPixel

//8.SymmetricSecondRankTensor   二阶对称张量 继承自FixedArray  访问 运算 迹数 特征值 特征矩阵  旋转(需要学习Matrix) 矩阵相乘(需要学习Matrix)

//9.DiffusionTensor3D           扩散张量     继承自SymmetricSecondRankTensor    各向异性分数 相对各向异性 内标积

int main()
{
	//FixedArrayTest();  //定长数组测试

	//PointTest();         //点测试

	//VectorTest();        //向量测试

	//RGBPixelTest();        //RGB测试

	//SymmetricSecondRankTensorTest();   //二阶对称张量

	DiffusionTensor3DTest();

	system("pause");
}