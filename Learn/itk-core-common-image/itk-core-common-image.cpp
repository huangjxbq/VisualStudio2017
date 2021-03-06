﻿#include <iostream>
#include "ImageBase.h"
#include "ImageRegion.h"

#include "ImageRegionIterator.h"
#include "ImageRandomIterator.h"
#include "ImageSliceIterator.h"
#include "ImageScanlineIterator.h"

#include "ImageOperate.h"

//图像相关概念
#include "ImageIndex.h"

//1.ImageConstIterator
//|
//|--2.ImageRegionConstIterator
//|  |
//|  |--3.ImageRegionIterator
//|
//|--4.ImageIterator
//|
//|--5.ImageScanlineConstIterator
//|  |
//|  |--6.ImageScanlineIterator

//1.ImageConstIteratorWithIndex
//|
//|--2.ImageIteratorWithIndex
//|
//|--3.ImageRegionConstIteratorWithIndex
//|  |
//|  |--4.ImageRegionIteratorWithIndex
//|  |
//|  |--5.ImageRegionExclusionConstIteratorWithIndex
//|     |
//|     |--6.ImageRegionExclusionIteratorWithIndex
//|
//|--7.ImageRandomConstIteratorWithIndex
//|  |
//|  |--8.ImageRandomIteratorWithIndex
//|
//|--9.ImageRandomNonRepeatingConstIteratorWithIndex
//|  |
//|  |--10.ImageRandomNonRepeatingIteratorWithIndex
//|
//|--11.ImageSliceConstIteratorWithIndex
//|  |
//|  |--12.ImageSliceIteratorWithIndex
//|
//|--13.ImageLinearConstIteratorWithIndex
//   |
//   |--14.ImageLinearIteratorWithIndex

//1.ImageConstIteratorWithOnlyIndex
//|
//|--2.ImageRegionConstIteratorWithOnlyIndex
//|
//|--3.ImageRandomConstIteratorWithOnlyIndex

//1.ImageReverseConstIterator
//|
//|--2.ImageRegionReverseConstIterator
//   |
//   |--3.ImageRegionReverseIterator
//   |
//   |--4.ImageReverseIterator

//1.LineConstIterator
//|
//|--2.LineIterator


int main()
{
	//ImageBaseTest();

	//ImageTest();

	//ImageRegionTest();

	//区域分割
	//ImageRegionSplitterTest();

	

	//ImageRegionConstIteratorTest();

	//ImageRegionConstIteratorWithIndexTest();

	//ImageRegionExclusionConstIteratorWithIndexTest();

	//ImageRegionConstIteratorWithOnlyIndexTest();

	//ImageRegionReverseConstIteratorTest();

	//随机迭代器
	//ImageRandomConstIteratorWithIndexTest();

	//ImageRandomConstIteratorWithOnlyIndexTest();

	//ImageRandomNonRepeatingConstIteratorWithIndexTest();

	//切片迭代器
	//ImageSliceConstIteratorWithIndexTest();


	//ImageScanlineIteratorTest();


	//图像操作
	//ImageCopyRegion();

	//ImageDuplicator();

	//ImageEnlargeRegionOverBox();


	//==========图像相关概念==========
	ImageIndex();


	system("pause");
}