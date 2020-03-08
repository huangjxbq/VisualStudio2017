#include <itkVersion.h>
#include <itkBuildInformation.h>


void Version();

void BuildInformation();

int main()
{
	Version();

	BuildInformation();
	
	system("pause");
}

void Version()
{
	std::cout << "======================itkVersion======================" << std::endl;

	//5个静态函数
	std::cout << "************************静态函数***********************" << std::endl;
	std::cout << "ITKVersion:" << itk::Version::GetITKVersion() << std::endl;
	std::cout << "ITKMajorVersion:" << itk::Version::GetITKMajorVersion() << std::endl;
	std::cout << "ITKMinorVersion:" << itk::Version::GetITKMinorVersion() << std::endl;
	std::cout << "ITKBuildVersion:" << itk::Version::GetITKBuildVersion() << std::endl;
	std::cout << "ITKSourceVersion:" << itk::Version::GetITKSourceVersion() << std::endl;

	// 通过宏
	std::cout << "**************************宏***************************" << std::endl;
	std::cout << "ITK_VERSION:" << ITK_VERSION << std::endl;
	std::cout << "ITK_VERSION_MAJOR:" << ITK_VERSION_MAJOR << std::endl;
	std::cout << "ITK_VERSION_MINOR:" << ITK_VERSION_MINOR << std::endl;
	std::cout << "ITK_VERSION_PATCH:" << ITK_VERSION_PATCH << std::endl;
	std::cout << "ITK_SOURCE_VERSION:" << ITK_SOURCE_VERSION << std::endl;
	std::cout << "ITK_VERSION_STRING:" << ITK_VERSION_STRING << std::endl;
}

void BuildInformation()
{
	using BuildInformationMapType = itk::BuildInformation::MapType;
	using MapKeyType = itk::BuildInformation::MapKeyType;


	BuildInformationMapType map = itk::BuildInformation::GetMap();

	std::vector<MapKeyType> keys = itk::BuildInformation::GetAllKeys();


	for (int i = 0; i < keys.size(); i++)
	{
		itk::BuildInformation::GetValue((keys.at(i)));
		itk::BuildInformation::GetDescription(keys[i]);
	}
}