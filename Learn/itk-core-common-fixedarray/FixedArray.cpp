#include "FixedArray.h"
#include <itkFixedArray.h>

using DoubleFixedArray2D = itk::FixedArray<double, 2>;
using FloatFixedArray2D = itk::FixedArray<float, 2>;
using IntFixedArray2D = itk::FixedArray<int, 2>;

void ConstructTest();//�������

void AssignTest();   //��ֵ����

void AccessTest();   //���ʲ���

void FixedArrayTest()
{
	//ConstructTest(); 
	//AssignTest();
	AccessTest();
}

void ConstructTest()
{
	//1.Ĭ�Ϲ���
	DoubleFixedArray2D array;
	std::cout << array << std::endl;
	std::cout << "���鳤��:" << array.Length << std::endl;
	std::cout << "����ά��:" << array.Dimension << std::endl;
	std::cout << std::endl;

	//2.��һ��ValueType��ֵ����
	DoubleFixedArray2D array2(2.5);
	std::cout << array2 << std::endl << std::endl;

	//3.��һ��C���ValueType���鹹��
	DoubleFixedArray2D::ValueType data[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	DoubleFixedArray2D::ValueType data_error[1];  //ok
	DoubleFixedArray2D array3(data);
	std::cout << array3 << std::endl << std::endl;

	//4.��std::array<ValueType, Length>����
	std::array<DoubleFixedArray2D::ValueType, DoubleFixedArray2D::Length> stdarray;
	stdarray[0] = 5.2; stdarray[1] = 9.3;
	DoubleFixedArray2D array4(stdarray);
	std::cout << array4 << std::endl << std::endl;

	//5.��FixedArray<��������, Length>����
	IntFixedArray2D array_temp(20);
	DoubleFixedArray2D array5(array_temp);
	std::cout << array5 << std::endl << std::endl;

	//6.���������͵�C������鹹��
	IntFixedArray2D array6(data);
	std::cout << array6 << std::endl << std::endl;
}

void AssignTest()
{
	//1. const ValueType r[VLength] ��ֵ
	IntFixedArray2D::ValueType data[5] = { 5, 7, 21 };
	IntFixedArray2D array1;
	std::cout << "��ֵ֮ǰ��" << array1 << std::endl;
	array1 = data;
	std::cout << "��ֵ֮��" << array1 << std::endl;

	//2. FixedArray<��������, Length> ��ֵ
	DoubleFixedArray2D array2;
	std::cout << "��ֵ֮ǰ��" << array2 << std::endl;
	array2 = array1;
	std::cout << "��ֵ֮��" << array2 << std::endl;
}

void AccessTest()
{
	IntFixedArray2D array1;

	//ʹ��[]
	array1[0] = 100;
	array1[1] = 200;
	std::cout << array1 << std::endl;
	std::cout << "sum:" << array1[0] + array1[1] << std::endl;

	//ʹ��SetElement GetElement
	array1.SetElement(0, 20);
	array1.SetElement(1, 35);
	std::cout << array1 << std::endl;
	std::cout << "sum:" << array1.GetElement(0) + array1.GetElement(1) << std::endl;
}