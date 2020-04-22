#include <itkDiffusionTensor3D.h>

using DoubleDiffusionTensor3D = itk::DiffusionTensor3D<double>;

template<typename T, unsigned int d>
void Show(const itk::SymmetricSecondRankTensor<T, d> &tensor);

void DiffusionTensor3DTest()
{
	DoubleDiffusionTensor3D tensor;

	for (size_t i = 0; i < DoubleDiffusionTensor3D::Dimension; i++)
	{
		for (size_t j = 0; j < DoubleDiffusionTensor3D::Dimension; j++)
		{
			tensor(i, j) = 3 * i + j + 1;
		}
	}

	Show(tensor);

	std::cout << "" << tensor.GetFractionalAnisotropy() << std::endl;  //�������Է���
	std::cout << "" << tensor.GetInnerScalarProduct() << std::endl;    //�ڱ��
	std::cout << "" << tensor.GetRelativeAnisotropy() << std::endl;    //��Ը�������
}