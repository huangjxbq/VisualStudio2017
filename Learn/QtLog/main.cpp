#include "Widget.h"
#include <QtWidgets/QApplication>
#include <QDateTime>
#include <QStandardPaths>
#include <QThread>
#include <QDir>
#include <QTextStream>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	QByteArray localMsg = msg.toLocal8Bit();

	QString log;

	switch (type)
	{
	case QtDebugMsg:
		log = QString("[Debug]");
		break;
	case QtInfoMsg:
		log = QString("[Info]");
		break;
	case QtWarningMsg:
		log = QString("[Warning]");
		break;
	case QtCriticalMsg:
		log = QString("[Critical]");
		break;
	case QtFatalMsg:
		log = QString("[Fatal]");
		abort();
	}
	log.append(QDateTime::currentDateTime().toString(Qt::ISODate) +
		QString::number((quint64)QThread::currentThreadId()) +
		context.file + context.line + context.function + ":"
		+ localMsg.constData());

	QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/log";
	QString filename = path + "/" + QDate::currentDate().toString("yyyyMMdd") + ".log";

	if (QDir().mkpath(path))
	{
		QFile file(filename);
		if (file.open(QIODevice::WriteOnly | QIODevice::Append))
		{
			QTextStream outstream(&file);
			outstream << log << endl;
			file.flush();
			file.close();
		}
		else
		{
			QString error = file.errorString();
		}
	}
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	qInstallMessageHandler(myMessageOutput);
	qDebug("This is a debug message");
	qInfo("This is a info message");
	qWarning("This is a warning message");


	Widget w;
	w.show();
	return a.exec();
}
