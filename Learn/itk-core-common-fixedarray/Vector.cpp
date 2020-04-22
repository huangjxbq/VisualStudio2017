#include <itkVector.h>

using DoubleVector2D = itk::Vector<double, 2>;
using FloatVector2D = itk::Vector<float, 2>;
using IntVector2D = itk::Vector<int, 2>;

void VectorArithmeticTest();  //��������

void NormTest();              //ģ

void CrossProductTest();      //���

void VectorTest()
{
	//VectorArithmeticTest();

	//NormTest();

	CrossProductTest();
}

void VectorArithmeticTest()
{
	DoubleVector2D vector;
	vector[0] = 1.38;
	vector[1] = 2.24;

	DoubleVector2D vector2;
	vector2[0] = 3.25;
	vector2[1] = -5.24;

	//1. ���Ի��߳���һ����
	std::cout << vector * 2 << std::endl;
	vector *= 2;
	std::cout << vector << std::endl;

	std::cout << vector / 3 << std::endl;
	vector /= 3;
	std::cout << vector << std::endl;

	//2. �Ӽ�һ������
	std::cout << vector + vector2 << std::endl;
	vector += vector2;
	std::cout << vector << std::endl;

	std::cout << vector - vector2 << std::endl;
	vector -= vector2;
	std::cout << vector << std::endl;

	//3. -��
	std::cout << - vector << std::endl;

	//4. �ڻ�
	std::cout << vector * vector2 << std::endl;
}

void NormTest()
{
	DoubleVector2D vector;
	vector[0] = 1;
	vector[1] = 2;

	std::cout << vector << std::endl;
	std::cout << "Norm:" << vector.GetNorm() << std::endl;
	std::cout << "GetSquaredNorm:" << vector.GetSquaredNorm() << std::endl;

	std::cout << "��һ��" << vector.Normalize() << std::endl;
	std::cout << vector << std::endl;
}

void CrossProductTest()
{
	itk::Vector<int, 3> vector1;
	vector1[0] = 1;
	vector1[1] = 0;
	vector1[2] = 0;

	itk::Vector<int, 3> vector2;
	vector2[0] = 0;
	vector2[1] = 1;
	vector2[2] = 0;

	std::cout << vector1 << std::endl;
	std::cout << vector2 << std::endl;
	std::cout << itk::CrossProduct(vector1, vector2) << std::endl;
}