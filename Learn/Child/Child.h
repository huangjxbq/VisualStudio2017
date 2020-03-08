#pragma once

#include <QtWidgets/QWidget>
#include "ui_Child.h"
#include <Windows.h>


class Child : public QWidget
{
	Q_OBJECT

public:
	Child(QWidget *parent = Q_NULLPTR);

private:
	Ui::ChildClass ui;
};
