#include <iostream>
#include <Windows.h>

int main()
{
	LANGID langid = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US);

	//FORMAT_MESSAGE_ALLOCATE_BUFFER
	{
		//HLOCAL buffer = NULL;
		//DWORD res = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		//	NULL, ERROR_SUCCESS, 0, (LPTSTR)&buffer, 0, NULL);

		//if (0 == res)
		//{
		//	DWORD err = GetLastError();
		//}
		//else
		//{
		//	std::cout << (TCHAR*)(buffer) << std::endl;
		//	LocalFree(buffer);
		//}
	}

	//not set FORMAT_MESSAGE_ALLOCATE_BUFFER
	{
		//TCHAR buffer[256] = { 0 };

		//DWORD res = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		//	NULL, ERROR_SUCCESS, langid, buffer, 256, NULL);

		//if (0 == res)
		//{
		//	DWORD err = GetLastError();
		//}
		//else
		//{
		//	//std::cout << (TCHAR*)(buffer) << std::endl;
		//}
	
	}


	{
		TCHAR buffer[256] = { 0 };
		TCHAR source[256] = TEXT("自定义的");

		DWORD res = FormatMessage(FORMAT_MESSAGE_FROM_STRING | FORMAT_MESSAGE_IGNORE_INSERTS,
			source, ERROR_SUCCESS, langid, buffer, 256, NULL);

		if (0 == res)
		{
			DWORD err = GetLastError();
		}
		else
		{
			//std::cout << (TCHAR*)(buffer) << std::endl;
		}

	}
}