#include "Widget.h"
#include <QPixmap>
#include <QDebug>
#include <QtMath>
#include <QMatrix>
#include <QBitmap>
//#include <qmath.h>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//QPixmap pixmap("C:\\Users\\hjx\\Desktop\\IMG_20190324_160629.jpg");
	//QPixmap pixmap("D:\\huangjx\\resource\\lena.jpg", "JPG", Qt::MonoOnly);
	//QPixmap pixmap(24, 24);
	QPixmap pixmap;

	//加载
	pixmap.load("D:\\huangjx\\resource\\lena.jpg", "JPG", Qt::MonoOnly);

	//提取感兴趣区域
	QPixmap roi = pixmap.copy(0, 0, 20, 20);

	roi.fill(Qt::white);

	//scroll
	QRegion region;
	//pixmap.scroll(50, -70, pixmap.rect(), &region);
	pixmap.scroll(128, 128, QRect(128, 128, 256, 256), &region);
	pixmap.scroll(-256, 256, pixmap.rect(), &region);
	qDebug() << region;

	//设置掩码
	QBitmap bitmap(pixmap.size());
	bitmap.fill(Qt::color0);
	pixmap.setMask(bitmap);

	//保存
	pixmap.save("D:\\huangjx\\resource\\lena.png", "PNG", 0);


	qDebug() << "isNull:" << pixmap.isNull();
	qDebug() << "isQBitmap:" << pixmap.isQBitmap();
	qDebug() << "isDetached:" << pixmap.isDetached();
	qDebug() << "devType:" << pixmap.devType();
	qDebug() << "cacheKey:" << pixmap.cacheKey();

	showPixmapSizeInfo(pixmap);
	showPixmapColorInfo(pixmap);

	
	//***************************缩放**************************
	
	pixmap.scaled(48, 48);

	//1
	//showPixmapSizeInfo(pixmap.scaled(50, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	//showPixmapSizeInfo(pixmap.scaled(50, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	//showPixmapSizeInfo(pixmap.scaled(50, 20, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

	//2
	//showPixmapSizeInfo(pixmap.scaledToWidth(50, Qt::SmoothTransformation));  //宽高比例不变
	//showPixmapSizeInfo(pixmap.scaledToHeight(50, Qt::SmoothTransformation));  //宽高比例不变


	//****************************坐标转换*************************

	// 1.使用QTransform
	QTransform transform;
	//transform.translate(10, 10);
	transform.rotate(30);
	//transform.scale(1.0, 1.0);

	// 2.使用QMatrix
	QMatrix matrix;
	//matrix.translate(10, 10);
	//matrix.rotate(45);	  //顺时针旋转90
	matrix.scale(0.5, 0.5);   //长宽都变为原来的1/2

	QPixmap pixmap_tr = pixmap.transformed(transform);
	showPixmapSizeInfo(pixmap_tr);
	showPixmapColorInfo(pixmap_tr);


	ui.label->setPixmap(pixmap);
	
	//qDebug() << pixmap.handle();
}

void Widget::showPixmapSizeInfo(const QPixmap &pixmap)
{
	qDebug() << "width:" << pixmap.width();
	qDebug() << "height:" << pixmap.height();
	qDebug() << "size:" << pixmap.size();
	qDebug() << "rect:" << pixmap.rect();
}

void Widget::showPixmapColorInfo(const QPixmap &pixmap)
{
	qDebug() << "depth:" << pixmap.depth();
	qDebug() << "hasAlpha:" << pixmap.hasAlpha();
	qDebug() << "hasAlphaChannel:" << pixmap.hasAlphaChannel();
}