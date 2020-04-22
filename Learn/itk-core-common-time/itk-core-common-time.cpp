#include <iostream>
#include "TimeStamp.h"
#include "RealTimeInterval.h"
#include "RealTimeStamp.h"

//1.TimeStamp         时间戳(次数戳) GetMTime() Modified()  < >

//2.RealTimeInterval  时间间隔(单位秒)   +-  比较 单位转换

//3.RealTimeStamp     真实时间戳    本质是时间间隔

//4.RealTimeClock     时钟         提供一个真实时间戳

int main()
{
	//TimeStampTest();

	//RealTimeIntervalTest();

	RealTimeStampTest();

	system("pause");
}