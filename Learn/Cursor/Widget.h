#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"
#include <Windows.h>

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = Q_NULLPTR);


protected:
	virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result);



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
	//限制光标区域
	void on_pushButton_clipCursor_clicked();
	void on_pushButton_cancleClipCursor_clicked();

	//显隐
	void on_pushButton_show_clicked();
	void on_pushButton_hide_clicked();

	//设置系统预定义光标
	void on_pushButton_appStarting_clicked();
	void on_pushButton_arrow_clicked();
	void on_pushButton_cross_clicked();
	void on_pushButton_hand_clicked();
	void on_pushButton_help_clicked();
	void on_pushButton_ibeam_clicked();
	void on_pushButton_icon_clicked();
	void on_pushButton_no_clicked();
	void on_pushButton_person_clicked();
	void on_pushButton_pin_clicked();
	void on_pushButton_size_clicked();
	void on_pushButton_sizeAll_clicked();
	void on_pushButton_sizeNesw_clicked();
	void on_pushButton_sizeNs_clicked();
	void on_pushButton_sizeNwse_clicked();
	void on_pushButton_sizeWe_clicked();
	void on_pushButton_upArrow_clicked();
	void on_pushButton_wait_clicked();

	//设置自定义光标
	void on_pushButton_cursor1_clicked();
	void on_pushButton_cursor2_clicked();
	void on_pushButton_cursor3_clicked();
	void on_pushButton_cursor4_clicked();
	void on_pushButton_cursorFromFile_clicked();

private:
	Ui::WidgetClass ui;


	HWND m_hWnd;
	HCURSOR m_hCursor;

	RECT m_OldClipRect;
	RECT m_NewClipRect;

	int m_Count;
};
