#include "Widget.h"
#include <QCursor>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

#include "resource.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.label_count->setAlignment(Qt::AlignCenter);

	m_hCursor = LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1));
	

	m_hWnd = (HWND)winId();
	GetClipCursor(&m_OldClipRect);

	
	//SetCursor(LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1)));
}

bool Widget::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	MSG *msg = (MSG*)message;

	if (WM_SETCURSOR == msg->message)
	{
		SetCursor(m_hCursor);
		//SetCursor(LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1)));
		return true;
	}
	else
	{
		return QWidget::nativeEvent(eventType, message, result);
	}
}

void Widget::on_pushButton_ArrowCursor_clicked()
{
	QCursor cursor(Qt::ArrowCursor);
	this->setCursor(cursor);
}
void Widget::on_pushButton_UpArrowCursor_clicked()
{
	QCursor cursor(Qt::UpArrowCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_CrossCursor_clicked()
{
	QCursor cursor(Qt::CrossCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_WaitCursor_clicked()
{
	QCursor cursor(Qt::WaitCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_IBeamCursor_clicked()
{
	QCursor cursor(Qt::IBeamCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SizeVerCursor_clicked()
{
	QCursor cursor(Qt::SizeVerCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SizeHorCursor_clicked()
{
	QCursor cursor(Qt::SizeHorCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SizeBDiagCursor_clicked()
{
	QCursor cursor(Qt::SizeBDiagCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SizeFDiagCursor_clicked()
{
	QCursor cursor(Qt::SizeFDiagCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SizeAllCursor_clicked()
{
	QCursor cursor(Qt::SizeAllCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_BlankCursor_clicked()
{
	QCursor cursor(Qt::BlankCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SplitVCursor_clicked()
{
	QCursor cursor(Qt::SplitVCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_SplitHCursor_clicked()
{
	QCursor cursor(Qt::SplitHCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_PointingHandCursor_clicked()
{
	QCursor cursor(Qt::PointingHandCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_ForbiddenCursor_clicked()
{
	QCursor cursor(Qt::ForbiddenCursor);
	this->setCursor(cursor);
}
void Widget::on_pushButton_WhatsThisCursor_clicked()
{
	QCursor cursor(Qt::WhatsThisCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_BusyCursor_clicked()
{
	QCursor cursor(Qt::BusyCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_OpenHandCursor_clicked() 
{
	QCursor cursor(Qt::OpenHandCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_ClosedHandCursor_clicked() 
{
	QCursor cursor(Qt::ClosedHandCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_DragCopyCursor_clicked() 
{
	QCursor cursor(Qt::DragCopyCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_DragMoveCursor_clicked()
{
	QCursor cursor(Qt::DragMoveCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_DragLinkCursor_clicked()
{
	QCursor cursor(Qt::DragLinkCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_LastCursor_clicked()
{
	QCursor cursor(Qt::LastCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_BitmapCursor_clicked()
{
	QCursor cursor(Qt::BitmapCursor);
	this->setCursor(cursor);
	
}
void Widget::on_pushButton_CustomCursor_clicked() 
{
	QCursor cursor(Qt::CustomCursor);
	this->setCursor(cursor);
	
}


void Widget::on_pushButton_clipCursor_clicked()
{
	GetWindowRect((HWND)winId(), &m_NewClipRect);
	ClipCursor(&m_NewClipRect);
}

void Widget::on_pushButton_cancleClipCursor_clicked()
{
	ClipCursor(&m_OldClipRect);
}

void Widget::on_pushButton_show_clicked()
{
	m_Count = ShowCursor(TRUE);
	ui.label_count->setText(QString::number(m_Count));
	
}

void Widget::on_pushButton_hide_clicked()
{
	m_Count = ShowCursor(FALSE);
	ui.label_count->setText(QString::number(m_Count));
}

void Widget::on_pushButton_appStarting_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_APPSTARTING);
}

void Widget::on_pushButton_arrow_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_ARROW);
}

void Widget::on_pushButton_cross_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_CROSS);
}
void Widget::on_pushButton_hand_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_HAND);
}
void Widget::on_pushButton_help_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_HELP);
}
void Widget::on_pushButton_ibeam_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_IBEAM);
}
void Widget::on_pushButton_icon_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_ICON);
}
void Widget::on_pushButton_no_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_NO);
}
void Widget::on_pushButton_person_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_PERSON);
}
void Widget::on_pushButton_pin_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_PIN);
}
void Widget::on_pushButton_size_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_SIZE);
}
void Widget::on_pushButton_sizeAll_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_SIZEALL);
}
void Widget::on_pushButton_sizeNesw_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_SIZENESW);
}
void Widget::on_pushButton_sizeNs_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_SIZENS);
}
void Widget::on_pushButton_sizeNwse_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_SIZENWSE);
}
void Widget::on_pushButton_sizeWe_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_SIZEWE);
}
void Widget::on_pushButton_upArrow_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_UPARROW);
}
void Widget::on_pushButton_wait_clicked()
{
	m_hCursor = LoadCursor(NULL, IDC_WAIT);
	qDebug() << m_hCursor;
}

void Widget::on_pushButton_cursor1_clicked()
{
	m_hCursor = LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1));
	qDebug() << m_hCursor;
}
void Widget::on_pushButton_cursor2_clicked()
{
	m_hCursor = LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR2));
	qDebug() << m_hCursor;
}
void Widget::on_pushButton_cursor3_clicked()
{
	m_hCursor = LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR3));
	qDebug() << m_hCursor;
}
void Widget::on_pushButton_cursor4_clicked()
{
	m_hCursor = NULL;
}

void Widget::on_pushButton_cursorFromFile_clicked()
{
	QFileDialog filedialog;
	filedialog.setLabelText(QFileDialog::Accept, u8"选择");
	filedialog.setNameFilter(u8"光标文件 (*.cur)");      //ttf RawTrueTypeFont
	//filedialog.setFileMode(QFileDialog::ExistingFiles); //设置多选
	if (QFileDialog::Accepted == filedialog.exec())
	{
		QString filename = QDir::toNativeSeparators(filedialog.selectedFiles()[0]);

#ifdef UNICODE
		m_hCursor = LoadCursorFromFile(filename.toStdWString().c_str());
#else
		m_hCursor = LoadCursorFromFile(filename.toStdString().c_str());
#endif // UNICODE

		if (NULL == m_hCursor)
		{
			GetLastError();
		}

		qDebug() << m_hCursor;
		
	}
}