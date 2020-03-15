#include "Widget.h"

#include <log4cplus/appender.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
#include <log4cplus/loglevel.h>
#include <log4cplus/ndc.h>



Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	
}
