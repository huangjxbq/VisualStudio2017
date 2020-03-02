#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = Q_NULLPTR);

	void showPixmapSizeInfo(const QPixmap &pixmap);
	void showPixmapColorInfo(const QPixmap &pixmap);

private:
	Ui::WidgetClass ui;
};
