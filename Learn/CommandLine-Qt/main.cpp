#include <QtCore/QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>

//enum CommandLineParseResult
//{
//	CommandLineOk,
//	CommandLineError,
//	CommandLineVersionRequested,
//	CommandLineHelpRequested
//};
//
//CommandLineParseResult parseCommandLine(QCommandLineParser &parser, QString &errorMessage)
//{
//	parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
//	const QCommandLineOption nameServerOption("n", "The name server to use.", "nameserver");
//	parser.addOption(nameServerOption);
//	const QCommandLineOption typeOption("t", "The lookup type.", "type");
//	parser.addOption(typeOption);
//	parser.addPositionalArgument("name", "The name to look up.");
//	const QCommandLineOption helpOption = parser.addHelpOption();
//	const QCommandLineOption versionOption = parser.addVersionOption();
//
//	if (!parser.parse(QCoreApplication::arguments())) 
//	{
//		errorMessage = parser.errorText();
//		return CommandLineError;
//	}
//
//	if (parser.isSet(versionOption))
//	{
//		return CommandLineVersionRequested;
//	}
//
//	if (parser.isSet(helpOption))
//	{
//		return CommandLineHelpRequested;
//	}
//
//	if (parser.isSet(nameServerOption))
//	{
//		const QString nameserver = parser.value(nameServerOption);
//		query->nameServer = QHostAddress(nameserver);
//		if (query->nameServer.isNull() || query->nameServer.protocol() == QAbstractSocket::UnknownNetworkLayerProtocol) {
//			*errorMessage = "Bad nameserver address: " + nameserver;
//			return CommandLineError;
//		}
//	}
//
//	if (parser.isSet(typeOption)) 
//	{
//		const QString typeParameter = parser.value(typeOption);
//		const int type = typeFromParameter(typeParameter.toLower());
//		if (type < 0) {
//			*errorMessage = "Bad record type: " + typeParameter;
//			return CommandLineError;
//		}
//		query->type = static_cast<QDnsLookup::Type>(type);
//	}
//
//	const QStringList positionalArguments = parser.positionalArguments();
//	if (positionalArguments.isEmpty()) {
//		*errorMessage = "Argument 'name' missing.";
//		return CommandLineError;
//	}
//	if (positionalArguments.size() > 1) {
//		*errorMessage = "Several 'name' arguments specified.";
//		return CommandLineError;
//	}
//	query->name = positionalArguments.first();
//
//	return CommandLineOk;
//}


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QCoreApplication::setApplicationName("my-copy-program");
	QCoreApplication::setApplicationVersion("1.0");

	QCommandLineParser parser;
	parser.setApplicationDescription("Test helper");
	parser.addHelpOption();
	parser.addVersionOption();
	parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."), "[filename, filename...]");
	parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

	// A boolean option with a single name (-p)
	QCommandLineOption showProgressOption("p", QCoreApplication::translate("main", "Show progress during copy"));
	parser.addOption(showProgressOption);

	// A boolean option with multiple names (-f, --force)
	QCommandLineOption forceOption(QStringList() << "f" << "force",
		QCoreApplication::translate("main", "Overwrite existing files."));
	parser.addOption(forceOption);

	// An option with a value
	QCommandLineOption targetDirectoryOption(QStringList() << "t" << "target-directory",
		QCoreApplication::translate("main", "Copy all source files into <directory>."),
		QCoreApplication::translate("main", "directory"));
	parser.addOption(targetDirectoryOption);

	// Process the actual command line arguments given by the user
	parser.process(a);

	const QStringList args = parser.positionalArguments();
	// source is args.at(0), destination is args.at(1)

	bool showProgress = parser.isSet(showProgressOption);
	bool force = parser.isSet(forceOption);
	QString targetDir = parser.value(targetDirectoryOption);





	return a.exec();
}


void _7Z()
{
	QCommandLineParser parser;



}