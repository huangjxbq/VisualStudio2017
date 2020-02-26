#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"
#include <Windows.h>

class QMenu;

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = Q_NULLPTR);
	~Widget();

private slots:
	//Qt安装卸载字体
	void on_pushButton_Install_Qt_clicked();  //安装字体

	void on_tableWidget_install_qt_customContextMenuRequested(const QPoint &pos);  //右键菜单

	void on_action_uninstall_qt_triggered();  //卸载字体

	void on_pushButton_enum_qt_clicked();     //枚举字体

private:
	//Qt 
	void InstallFontUseQt(const QStringList &files);  //Qt安装字体

	void updateListWidget();   //更新列表

	void EnumFontUseQt();      //Qt枚举字体


	//Windows SDK






	void EnumFontUseWin32();

	void InstallFontUseWin32();  //Win32安装字体

	void RemoveFontUseWin32();   //Win32卸载字体

	static int CALLBACK CallBackEnumFontFamExProc(
		const LOGFONT    *lpelfe,
		const TEXTMETRIC *lpntme,
		DWORD      FontType,
		LPARAM     lParam
	);


	Ui::WidgetClass ui;

	//Qt 
	QMap<QString, int> m_InstalledFontFile; //!<-已经安装的字体文件

	QMenu *m_pUninstallMenuQt;     //卸载菜单

	int m_win_font_1;
	int m_win_font_2;
	int m_win_font_3;
};