#include "Child.h"
#include <QDebug>


Child::Child(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	DWORD count = 0;
	count = GetEnvironmentVariable(TEXT("DN"), NULL, 0);

	if (0 != count)
	{
		ui.textEdit->append(QString::number(count));
		TCHAR *value = new TCHAR[count]{0};
		GetEnvironmentVariable(TEXT("DN"), value, count);
		QString ev = QString::fromWCharArray(value);
		delete[]value;

		ui.textEdit->append(u8"��ȡ���������ɹ�");
		ui.textEdit->append(QString("DN:") + ev);

		HANDLE file = (HANDLE)636;

		DWORD number = 6;
		BOOL res = WriteFile(file, "Child!", number, &number, NULL);
		if (FALSE == res)
		{
			ui.textEdit->append(u8"д�ļ�ʧ��");
		}
		else
		{
			ui.textEdit->append(u8"д�ļ��ɹ�");
		}

		CloseHandle(file);
	}
	else
	{
		ui.textEdit->append(u8"��ȡ��������ʧ��");
	}
}