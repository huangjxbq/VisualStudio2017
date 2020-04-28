#include <QtCore/QCoreApplication>
#include "Logger.h"
#include "ThreadLogger.h"

// 1.LoggerBase

// 2.Logger

// 3.ThreadLogger

// 4.LoggerThreadWrapper

// 5.LogOutput

// 6.StdStreamLogOutput

// 7.MultipleLogOutput

// 8.LoggerManager

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//LoggerTest();

	ThreadLoggerTest();

	return a.exec();
}