#include "Widget.h"
#include <QCommandLineParser>
#include <QDebug>
#include <iostream>

#include <Windows.h>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QCommandLineParser parser;

	parser.setApplicationDescription("This is a commandlineparser program.");
	parser.addHelpOption();

	QCoreApplication::setApplicationVersion("1.0.1");
	parser.addVersionOption();
	

	parser.addPositionalArgument("source", QCoreApplication::translate("Widget", "Source file to copy."));
	parser.addPositionalArgument("destination", QCoreApplication::translate("Widget", "Destination directory."));


	parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);

	// A boolean option with a single name (-p)
	QCommandLineOption showProgressOption("p", QCoreApplication::translate("main", "Show progress during copy"));
	parser.addOption(showProgressOption);

	// A boolean option with multiple names (-f, --force)
	QCommandLineOption forceOption(QStringList() << "f" << "force",
		QCoreApplication::translate("main", "Overwrite existing files."));
	parser.addOption(forceOption);

	// An option with a value
	QCommandLineOption targetDirectoryOption(QStringList() << "t" << "target-directory",
		QCoreApplication::translate("Widget", "Copy all source files into <directory>."),
		QCoreApplication::translate("Widget", "directory"));
	parser.addOption(targetDirectoryOption);

	// Process the actual command line arguments given by the user
	parser.process(*QCoreApplication::instance());

	bool showProgress = parser.isSet(showProgressOption);
	bool force = parser.isSet(forceOption);
	QString targetDir = parser.value(targetDirectoryOption);

	QString str = showProgress ? "showProgressOption:true" : "showProgressOption:false";
	ui.textEdit->append(str);
	str = force ? "forceOption:true" : "forceOption:false";
	ui.textEdit->append(str);
	ui.textEdit->append(targetDir);

	const QStringList args = parser.positionalArguments();
	for each (const QString arg in args)
	{
		ui.textEdit->append(arg);
	}

	
	//qDebug() << parser.applicationDescription();
}