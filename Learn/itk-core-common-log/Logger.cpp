#include <itkLogger.h>
#include <itkStdStreamLogOutput.h>

void LoggerTest()
{
	itk::StdStreamLogOutput::Pointer stdstreamoutput = itk::StdStreamLogOutput::New();
	stdstreamoutput->SetStream(std::cout);

	std::ofstream ofs("itklog.txt");
	itk::StdStreamLogOutput::Pointer stdfstreamoutput = itk::StdStreamLogOutput::New();
	stdfstreamoutput->SetStream(ofs);

	itk::MultipleLogOutput::Pointer multipleoutput = itk::MultipleLogOutput::New();
	multipleoutput->AddLogOutput(stdstreamoutput);
	multipleoutput->AddLogOutput(stdfstreamoutput);

	itk::Logger::Pointer logger = itk::Logger::New();
	logger->SetName("logger1");                                  //名称
	logger->SetTimeStampFormat(itk::LoggerBase::HUMANREADABLE);  //时间戳格式
	logger->SetPriorityLevel(itk::LoggerBase::CRITICAL);
	logger->SetLevelForFlushing(itk::LoggerBase::CRITICAL);
	logger->AddLogOutput(multipleoutput);


	logger->Debug("this is debug message\n");
	logger->Info("this is info message\n");
	logger->Warning("this is warning message\n");
	logger->Critical("this is critical message\n");
	//logger->Error("this is error message");
	logger->Fatal("this is fatal message\n");
}