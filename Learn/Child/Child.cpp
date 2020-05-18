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

		ui.textEdit->append(u8"获取环境变量成功");
		ui.textEdit->append(QString("DN:") + ev);

		DWORD number = 7;
		BOOL res = WriteFile((HANDLE)ev.toInt(), "Child!\n", number, &number, NULL);
		if (FALSE == res)
		{
			ui.textEdit->append(u8"写文件失败");
		}
		else
		{
			ui.textEdit->append(u8"写文件成功");
		}

		CloseHandle((HANDLE)ev.toInt());
	}
	else
	{
		ui.textEdit->append(u8"获取环境变量失败");
	}
}