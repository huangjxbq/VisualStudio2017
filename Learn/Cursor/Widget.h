#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"
#include <Windows.h>

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = Q_NULLPTR);


private slots:
	void on_pushButton_ArrowCursor_clicked();
	void on_pushButton_UpArrowCursor_clicked();
	void on_pushButton_CrossCursor_clicked();
	void on_pushButton_WaitCursor_clicked();
	void on_pushButton_IBeamCursor_clicked();
	void on_pushButton_SizeVerCursor_clicked();
	void on_pushButton_SizeHorCursor_clicked();
	void on_pushButton_SizeBDiagCursor_clicked();
	void on_pushButton_SizeFDiagCursor_clicked();
	void on_pushButton_SizeAllCursor_clicked();
	void on_pushButton_BlankCursor_clicked();
	void on_pushButton_SplitVCursor_clicked();
	void on_pushButton_SplitHCursor_clicked();
	void on_pushButton_PointingHandCursor_clicked();
	void on_pushButton_ForbiddenCursor_clicked();
	void on_pushButton_WhatsThisCursor_clicked();
	void on_pushButton_BusyCursor_clicked();
	void on_pushButton_OpenHandCursor_clicked();
	void on_pushButton_ClosedHandCursor_clicked();
	void on_pushButton_DragCopyCursor_clicked();
	void on_pushButton_DragMoveCursor_clicked();
	void on_pushButton_DragLinkCursor_clicked();
	void on_pushButton_LastCursor_clicked();
	void on_pushButton_BitmapCursor_clicked();
	void on_pushButton_CustomCursor_clicked();


// Windows SDK
	//���ƹ������
	void on_pushButton_clipCursor_clicked();
	void on_pushButton_cancleClipCursor_clicked();

	//����
	void on_pushButton_show_clicked();
	void on_pushButton_hide_clicked();

	//����ϵͳԤ������
	void on_comboBox_cursor_currentIndexChanged(int index);


private:
	Ui::WidgetClass ui;


	HWND m_hWnd;


	RECT m_OldClipRect;
	RECT m_NewClipRect;

	int m_Count;
};
