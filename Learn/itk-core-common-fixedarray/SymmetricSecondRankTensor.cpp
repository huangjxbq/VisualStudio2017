#include <itkSymmetricSecondRankTensor.h>
#include <iomanip>

using IntSymmetricSecondRankTensor = itk::SymmetricSecondRankTensor<int, 3>;
using DoubleSymmetricSecondRankTensor = itk::SymmetricSecondRankTensor<double, 3>;

template<typename T, unsigned int d>
void Show(const itk::SymmetricSecondRankTensor<T, d> &tensor);   //��ʾ ����ֵ ���� 

void TensorAccessTest();

void TensorArithmeticTest();   

void SymmetricSecondRankTensorTest()
{
	//TensorAccessTest();
	TensorArithmeticTest();
}

template<typename T, unsigned int d>
void Show(const itk::SymmetricSecondRankTensor<T, d> &tensor)
{
	for (size_t i = 0; i < itk::SymmetricSecondRankTensor<T, d>::Dimension; i++)
	{
		for (size_t j = 0; j < itk::SymmetricSecondRankTensor<T, d>::Dimension; j++)
		{
			std::cout << std::fixed << std::setprecision(8) << tensor(i, j) << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "����:" << tensor.GetTrace() << std::endl;

	using EigenValuesArrayType = typename itk::SymmetricSecondRankTensor<T, d>::EigenValuesArrayType;
	using EigenVectorsMatrixType = typename itk::SymmetricSecondRankTensor<T, d>::EigenVectorsMatrixType;

	EigenValuesArrayType eigenvalues;
	tensor.ComputeEigenValues(eigenvalues);
	std::cout << "����ֵ:" << eigenvalues << std::endl;

	EigenVectorsMatrixType eigenmatrix;
	tensor.ComputeEigenAnalysis(eigenvalues, eigenmatrix);
	std::cout << "����ֵ:" << eigenvalues << std::endl;
	std::cout << "��������:" << eigenmatrix << std::endl;
}

void TensorAccessTest()
{
	DoubleSymmetricSecondRankTensor tensor;
	for (size_t i = 0; i < DoubleSymmetricSecondRankTensor::Dimension; i++)
	{
		for (size_t j = 0; j < DoubleSymmetricSecondRankTensor::Dimension; j++)
		{
			tensor(i, j) = 3 * i + j + 1;
		}
	}

	Show(tensor);
}

void TensorArithmeticTest()
{
	DoubleSymmetricSecondRankTensor tensor;

	tensor.SetIdentity();

	tensor *= 2;

	Show(tensor);

	tensor /= 4;

	Show(tensor);

	tensor += 7.7;
	Show(tensor);
}