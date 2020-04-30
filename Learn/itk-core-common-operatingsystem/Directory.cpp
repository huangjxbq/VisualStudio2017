#include <itkDirectory.h>

void DirectoryTest()
{
	itk::Directory::Pointer dir = itk::Directory::New();
	dir->Load("D:\\Software");

	std::cout << "NumberOfFiles:" << dir->GetNumberOfFiles() << std::endl;

	for (size_t i = 0; i < dir->GetNumberOfFiles(); i++)
	{
		std::cout << dir->GetFile(i) << std::endl;
	}
}