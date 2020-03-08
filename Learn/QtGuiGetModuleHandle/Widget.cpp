#include "Widget.h"
#include <Windows.h>
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	IMAGE_DOS_HEADER __ImageBase;
	ui.textEdit->append(QString::number((qint64)&__ImageBase, 16));

	ui.textEdit->append(QString::number((qint64)GetModuleHandle(NULL), 16));
	ui.textEdit->append(QString::number((qint64)GetModuleHandle(TEXT("Qt5Widgets")), 16));
	ui.textEdit->append(QString::number((qint64)GetModuleHandle(TEXT("Qt5Gui")), 16));
	ui.textEdit->append(QString::number((qint64)GetModuleHandle(TEXT("Qt5Core")), 16));
	ui.textEdit->append(QString::number((qint64)GetModuleHandle(TEXT("D3Dcompiler_47")), 16));
	ui.textEdit->append(QString::number((qint64)GetModuleHandle(TEXT("libEGL")), 16));
	ui.textEdit->append(QString::number((qint64)GetModuleHandle(TEXT("libGLESV2")), 16));
	ui.textEdit->append(QString::number((qint64)GetModuleHandle(TEXT("opengl32sw")), 16));
}
