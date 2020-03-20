#include "Widget.h"
#include <log4cplus/log4cplus.h>
#include <log4cplus/win32consoleappender.h>
#include <log4cplus/win32debugappender.h>
//#include <log4cplus/helpers/property.h>
#include <Windows.h>


using namespace log4cplus;

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//log4cplus::helpers::Time  log4c
	//log4cplus::helpers::getFormattedTime("", );
	
	log4cplus::Logger root_logger = log4cplus::Logger::getRoot();

	const log4cplus::tstring root_logger_name = root_logger.getName(); //名称
	log4cplus::LogLevel log_level = root_logger.getLogLevel();         //级别

	log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("test_logger"));


	//文件日志
	log4cplus::SharedAppenderPtr appender1(new log4cplus::TimeBasedRollingFileAppender(LOG4CPLUS_TEXT(""), 
		LOG4CPLUS_TEXT("%d.log"), 2, false, true, false, false));
	appender1->setName(LOG4CPLUS_TEXT("TimeBasedRollingFileAppender"));

	//log4cplus::SharedAppenderPtr appender2(new log4cplus::DailyRollingFileAppender(LOG4CPLUS_TEXT("test.log")
	//	/*, log4cplus::MINUTELY, true, 10, false, false*//*, LOG4CPLUS_TEXT("yyyy-MM-dd")*/));
	//appender2->setName(LOG4CPLUS_TEXT("DailyRollingFileAppender"));

	//控制台
	log4cplus::helpers::Properties properties;
	properties.setProperty(LOG4CPLUS_TEXT("AllocConsole"), LOG4CPLUS_TEXT("true"));
	properties.setProperty(LOG4CPLUS_TEXT("logToStdErr"), LOG4CPLUS_TEXT("false"));
	properties.setProperty(LOG4CPLUS_TEXT("TextColor"), LOG4CPLUS_TEXT("1"));

	//log4cplus::SharedAppenderPtr appender3(new log4cplus::Win32ConsoleAppender(true, false));
	log4cplus::SharedAppenderPtr appender3(new log4cplus::Win32ConsoleAppender(properties));
	appender3->setName(LOG4CPLUS_TEXT("Win32ConsoleAppender"));

	//调试
	log4cplus::SharedAppenderPtr appender4(new log4cplus::Win32DebugAppender);
	appender4->setName(LOG4CPLUS_TEXT("Win32DebugAppender"));
	//Layout
	//log4cplus::Layout *simple_layout = new log4cplus::SimpleLayout;
	//std::unique_ptr<Layout> simple_layout((Layout *)new log4cplus::SimpleLayout);
	//std::unique_ptr<log4cplus::Layout> simple_layout(new log4cplus::SimpleLayout);
	//std::unique_ptr<log4cplus::Layout> simple_layout(new log4cplus::SimpleLayout);
	//appender->setLayout(simple_layout);
	//Layout *layout = appender->getLayout();


	logger.addAppender(appender1);
	//logger.addAppender(appender2);
	logger.addAppender(appender4);
	logger.setLogLevel(log4cplus::ALL_LOG_LEVEL);

	LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("info msg"));
	LOG4CPLUS_DEBUG(logger, LOG4CPLUS_TEXT("debug msg"));
}