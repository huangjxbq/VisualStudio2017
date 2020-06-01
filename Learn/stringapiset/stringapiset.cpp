#include <iostream>
#include <Windows.h>

int main()
{
	WCHAR source[64] = L"Windows核心编程";
	CHAR *dst = NULL;

	int requiredbytes = WideCharToMultiByte(CP_ACP, 0, source, -1, NULL, 0, NULL, NULL);

	if (requiredbytes > 0)
	{
		dst = new CHAR[requiredbytes /*+ 1*/]{ 0 };

		int res = WideCharToMultiByte(CP_ACP, 0, source, -1, dst, requiredbytes, NULL, NULL);

	}
	




    std::cout << "Hello World!\n";
}