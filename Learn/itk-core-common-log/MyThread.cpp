#include "MyThread.h"

MyThread::MyThread(QObject *parent)
	: QThread(parent)
{
}

MyThread::~MyThread()
{
}

void MyThread::run()
{
	m_Logger->Debug(QString::number((qint64)QThread::currentThreadId()).toStdString() + " this is debug message\n");
	m_Logger->Info(QString::number((qint64)QThread::currentThreadId()).toStdString() + " this is info message\n");
	m_Logger->Warning(QString::number((qint64)QThread::currentThreadId()).toStdString() + " this is warning message\n");
	m_Logger->Critical(QString::number((qint64)QThread::currentThreadId()).toStdString() + " this is critical message\n");
	//logger->Error("this is error message");
	m_Logger->Fatal(QString::number((qint64)QThread::currentThreadId()).toStdString() + " this is fatal message\n");
}