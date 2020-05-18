#include "ObjectHandleInherit.h"
#include <QDebug>

ObjectHandleInherit::ObjectHandleInherit(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	m_hFile = CreateFile(TEXT("test.txt"), 
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 
		&sa, 
		OPEN_ALWAYS, 
		0, 
		NULL);

	if (INVALID_HANDLE_VALUE == m_hFile)
	{
		ui.textEdit->append(u8"创建文件内核对象失败");
	}
	else
	{
		ui.textEdit->append(u8"创建文件内核对象成功");
		ui.textEdit->append(QString("DN:") + QString::number((qint64)m_hFile));

		DWORD count = 8;
		BOOL res = WriteFile(m_hFile, "Parent!\n", count, &count, NULL);

		if (FALSE == res)
		{
			ui.textEdit->append(u8"写文件失败");
		}
		else
		{
			ui.textEdit->append(u8"写文件成功");
		}
	}
}

ObjectHandleInherit::~ObjectHandleInherit()
{
	CloseHandle(m_hFile);
}

void ObjectHandleInherit::on_pushButton_clicked()
{
	TCHAR commandline[] = TEXT("Child.exe");
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;

	////为什么m_hFile变成了0;
	//QString str = QString::number((qint64)m_hFile);

	//DWORD count = 4;
	//BOOL res = WriteFile(m_hFile, TEXT("12345"), count, &count, NULL);
	//ui.textEdit->append(QString("DN:") + str);
	//const wchar_t *ss = str.toStdWString().c_str();

	SetEnvironmentVariable(TEXT("DN"), QString::number((qint64)m_hFile).toStdWString().c_str());
	CreateProcess(NULL, commandline, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
}