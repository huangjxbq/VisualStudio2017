#include <itkTextOutput.h>
#include <itkWin32OutputWindow.h>
#include <itkLoggerOutput.h>
#include <itkFileOutputWindow.h>
#include <itkXMLFileOutputWindow.h>
#include <itkCommand.h>

void CallBack(itk::Object *obj, const itk::EventObject &event, void *)
{
	obj->Print(std::cout);
}

void ConstCallBack(const itk::Object *obj, const itk::EventObject &event, void *)
{
	obj->Print(std::cout);
}

void OutputWindowTest()
{
	//1.TextOutput
	itk::TextOutput::Pointer textoutput = itk::TextOutput::New();
	itk::CStyleCommand::Pointer cmd = itk::CStyleCommand::New();
	cmd->SetConstCallback(ConstCallBack);
	cmd->SetCallback(CallBack);
	textoutput->AddObserver(itk::DeleteEvent(), cmd);

	//2.Win32OutputWindow
	itk::Win32OutputWindow::Pointer win32output = itk::Win32OutputWindow::New();
	itk::CStyleCommand::Pointer cmd2 = itk::CStyleCommand::New();
	cmd2->SetConstCallback(ConstCallBack);
	cmd2->SetCallback(CallBack);
	win32output->AddObserver(itk::DeleteEvent(), cmd2);

	//3.LoggerOutput   需要设置一个Logger
	itk::LoggerOutput::Pointer loggeroutput = itk::LoggerOutput::New();
	itk::CStyleCommand::Pointer cmd3 = itk::CStyleCommand::New();
	cmd3->SetConstCallback(ConstCallBack);
	cmd3->SetCallback(CallBack);
	loggeroutput->AddObserver(itk::DeleteEvent(), cmd3);

	//4.FileOutputWindow
	itk::FileOutputWindow::Pointer fileoutput = itk::FileOutputWindow::New();
	itk::CStyleCommand::Pointer cmd4 = itk::CStyleCommand::New();
	cmd4->SetConstCallback(ConstCallBack);
	cmd4->SetCallback(CallBack);
	fileoutput->AddObserver(itk::DeleteEvent(), cmd4);
	fileoutput->SetFileName("log.txt");
	fileoutput->AppendOn();
	fileoutput->FlushOn();

	//5.XMLFileOutputWindow
	itk::XMLFileOutputWindow::Pointer xmlfileoutput = itk::XMLFileOutputWindow::New();
	itk::CStyleCommand::Pointer cmd5 = itk::CStyleCommand::New();
	cmd5->SetConstCallback(ConstCallBack);
	cmd5->SetCallback(CallBack);
	xmlfileoutput->AddObserver(itk::DeleteEvent(), cmd5);
	xmlfileoutput->SetFileName("log.xml");
	xmlfileoutput->AppendOn();
	xmlfileoutput->FlushOn();
	xmlfileoutput->DisplayTag("hhhhhhhhhhh");


	
	itk::OutputWindow::SetInstance(xmlfileoutput);
	itk::OutputWindow::GetInstance()->DisplayText("adsg ");
	itk::OutputWindow::GetInstance()->DisplayDebugText("debug");
	itk::OutputWindow::GetInstance()->DisplayErrorText("error");
	itk::OutputWindow::GetInstance()->DisplayWarningText("warning");
	itk::OutputWindow::GetInstance()->DisplayGenericOutputText("genericoutput");

	system("pause");
}