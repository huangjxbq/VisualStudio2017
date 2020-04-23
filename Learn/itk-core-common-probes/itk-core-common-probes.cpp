#include <iostream>
#include "TimeProbe.h"
#include "TimeProbesCollectorBase.h"
#include "MemoryProbe.h"
#include "MemoryProbesCollectorBase.h"

//1.ResourceProbe                资源监测器 

//2.ResourceProbesCollectorBase  资源监测器集合

//3.TimeProbe                     时间监测器        从ResourceProbe派生

//4.TimeProbesCollectorBase       时间监测器集合    从ResourceProbesCollectorBase派生    

//5.MemoryProbe                   内存监测器       从ResourceProbe派生

//6.MemoryProbesCollectorBase     内存监测器集合    从ResourceProbesCollectorBase派生

int main()
{
	//TimeProbeTest();

	//TimeProbesCollectorBaseTest();

	//MemoryProbeTest();

	MemoryProbesCollectorBaseTest();

	system("pause");
}