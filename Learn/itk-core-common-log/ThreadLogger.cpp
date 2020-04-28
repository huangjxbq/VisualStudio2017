#include <itkThreadLogger.h>
#include <itkStdStreamLogOutput.h>
#include "MyThread.h"

void ThreadLoggerTest()
{
	itk::StdStreamLogOutput::Pointer stdstreamoutput = itk::StdStreamLogOutput::New();
	stdstreamoutput->SetStream(std::cout);

	std::ofstream ofs("itklog2.txt");
	itk::StdStreamLogOutput::Pointer stdfstreamoutput = itk::StdStreamLogOutput::New();
	stdfstreamoutput->SetStream(ofs);

	itk::MultipleLogOutput::Pointer multipleoutput = itk::MultipleLogOutput::New();
	multipleoutput->AddLogOutput(stdstreamoutput);
	multipleoutput->AddLogOutput(stdfstreamoutput);

	itk::ThreadLogger::Pointer logger2 = itk::ThreadLogger::New();
	logger2->SetName("logger2");                                  //名称
	logger2->SetTimeStampFormat(itk::LoggerBase::HUMANREADABLE);  //时间戳格式
	logger2->SetPriorityLevel(itk::LoggerBase::DEBUG);
	logger2->SetLevelForFlushing(itk::LoggerBase::DEBUG);
	logger2->AddLogOutput(multipleoutput);

	itk::ThreadLogger::Pointer logger3 = itk::ThreadLogger::New();
	logger3->SetName("logger3");                                  //名称
	logger3->SetTimeStampFormat(itk::LoggerBase::HUMANREADABLE);  //时间戳格式
	logger3->SetPriorityLevel(itk::LoggerBase::DEBUG);
	logger3->SetLevelForFlushing(itk::LoggerBase::MUSTFLUSH);
	logger3->AddLogOutput(multipleoutput);


	//logger2->Debug("this is debug message\n");
	//logger2->Info("this is info message\n");
	//logger2->Warning("this is warning message\n");
	//logger2->Critical("this is critical message\n");
	//logger2->Fatal("this is fatal message\n");

	logger3->Debug("this is debug message\n");
	logger3->Info("this is info message\n");
	logger3->Warning("this is warning message\n");
	logger3->Critical("this is critical message\n");
	logger3->Fatal("this is fatal message\n");
}