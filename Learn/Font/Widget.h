#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"
#include <Windows.h>

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = Q_NULLPTR);
	~Widget();



private slots:
	//Qt��װж������
	void on_pushButton_Install_Qt_clicked();  //��װ����



private:
	//Qt 
	void updateListWidget();   //�����б�




	//Windows SDK


	void EnumFontUseQt();    //Qtö������

	void InstallFontUseQt(const QStringList &files);  //Qt��װ����

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


	QMap<QString, int> m_InstalledFontFile; //!<-�Ѿ���װ�������ļ�

	int m_win_font_1;
	int m_win_font_2;
	int m_win_font_3;
};