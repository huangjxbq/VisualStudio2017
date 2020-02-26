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
	//Qt��װж������
	void on_pushButton_Install_Qt_clicked();  //��װ����

	void on_tableWidget_install_qt_customContextMenuRequested(const QPoint &pos);  //�Ҽ��˵�

	void on_action_uninstall_qt_triggered();  //ж������

	void on_pushButton_enum_qt_clicked();     //ö������

private:
	//Qt 
	void InstallFontUseQt(const QStringList &files);  //Qt��װ����

	void updateListWidget();   //�����б�

	void EnumFontUseQt();      //Qtö������


	//Windows SDK






	void EnumFontUseWin32();

	void InstallFontUseWin32();  //Win32��װ����

	void RemoveFontUseWin32();   //Win32ж������

	static int CALLBACK CallBackEnumFontFamExProc(
		const LOGFONT    *lpelfe,
		const TEXTMETRIC *lpntme,
		DWORD      FontType,
		LPARAM     lParam
	);


	Ui::WidgetClass ui;

	//Qt 
	QMap<QString, int> m_InstalledFontFile; //!<-�Ѿ���װ�������ļ�

	QMenu *m_pUninstallMenuQt;     //ж�ز˵�

	int m_win_font_1;
	int m_win_font_2;
	int m_win_font_3;
};