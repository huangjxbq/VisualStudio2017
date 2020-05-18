#pragma once

#include <QtWidgets/QWidget>
#include "ui_ObjectHandleInherit.h"
#include <Windows.h>



class ObjectHandleInherit : public QWidget
{
	Q_OBJECT

public:
	ObjectHandleInherit(QWidget *parent = Q_NULLPTR);
	~ObjectHandleInherit();

public slots:
	void on_pushButton_clicked();

private:
	Ui::ObjectHandleInheritClass ui;


	HANDLE m_hFile;
};
