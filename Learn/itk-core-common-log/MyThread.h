#pragma once
#include <QThread>
#include <itkLogger.h>

class MyThread : public QThread
{
	Q_OBJECT

public:
	MyThread(QObject *parent);
	~MyThread();

	void setLogger(itk::Logger *logger) { m_Logger = logger; }

protected:
	virtual void run();

private:
	itk::Logger::Pointer m_Logger;
};