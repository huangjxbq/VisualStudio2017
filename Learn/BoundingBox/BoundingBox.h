#pragma once

#include <QtWidgets/QWidget>
#include "ui_BoundingBox.h"

class BoundingBox : public QWidget
{
	Q_OBJECT

public:
	BoundingBox(QWidget *parent = Q_NULLPTR);

private:
	Ui::BoundingBoxClass ui;
};
