#include <itkMatrix.h>



using IntMat3x3 = itk::Matrix<int, 2, 3>;

using VectorType = itk::Vector<int, 3>;
using ResVectorType = itk::Vector<int, 2>;

void MatrixTest()
{
	IntMat3x3 mat1;
	std::cout << mat1 << std::endl;

	mat1(0, 0) = 1; mat1(0, 1) = 2; mat1(0, 2) = 3;
	mat1(1, 0) = 4; mat1(1, 1) = 5; mat1(1, 2) = 6;
	std::cout << mat1 << std::endl;
	std::cout << mat1.GetTranspose() << std::endl;
	//std::cout << mat1.GetInverse() << std::endl;


	//¾ØÕó³Ë·¨
	VectorType vector;
	vector[0] = 2; vector[1] = 3; vector[2] = 1;
	std::cout << mat1 * vector << std::endl;



}