#include "Widget.h"
#include <log4cplus/log4cplus.h>
//#include <memory>

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

	log4cplus::SharedAppenderPtr appender2(new log4cplus::DailyRollingFileAppender(LOG4CPLUS_TEXT("test.log")
		/*, log4cplus::MINUTELY, true, 10, false, false*//*, LOG4CPLUS_TEXT("yyyy-MM-dd")*/));
	appender2->setName(LOG4CPLUS_TEXT("DailyRollingFileAppender"));

	//Layout
	//log4cplus::Layout *simple_layout = new log4cplus::SimpleLayout;
	//std::unique_ptr<Layout> simple_layout((Layout *)new log4cplus::SimpleLayout);
	//std::unique_ptr<log4cplus::Layout> simple_layout(new log4cplus::SimpleLayout);
	//std::unique_ptr<log4cplus::Layout> simple_layout(new log4cplus::SimpleLayout);
	//appender->setLayout(simple_layout);
	//Layout *layout = appender->getLayout();


	logger.addAppender(appender1);
	logger.addAppender(appender2);
	logger.setLogLevel(log4cplus::ALL_LOG_LEVEL);

	LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("info msg"));
	LOG4CPLUS_DEBUG(logger, LOG4CPLUS_TEXT("debug msg"));
}