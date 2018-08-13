#include "ErrorHandle.h"

using namespace std;

ErrorHandle::ErrorHandle()
{
}

string ErrorHandle::getString(ErrorType type, string comment)
{
	string s = ErrorHandle::getErrorString(type);
	if (comment.size() > 0) {
		s += ": " + comment;
	}
	s += "\n";

	return s;
}

std::string ErrorHandle::getErrorString(ErrorType type) 
{
	switch (type)
	{
	case E_FILE_NOT_OPENED:
		return "File not opened. Program won't work properly";
	case E_COMMAND_CREATE:
		return "Command creating error";
	case W_ENTERED_DATA:
		return "Not enough data to execute";
	case MESSAGE:
		return "Message";
	default:
		return "Other Error";
	}
}

void ErrorHandle::message(ErrorType type, std::string comment)
{
	QMessageBox qmes;
	if(type == MESSAGE)
		qmes.setIcon(QMessageBox::Information);
	else
		qmes.setIcon(QMessageBox::Warning);

	QString qs;
	qs = qs.fromStdString(ErrorHandle::getErrorString(type));
	qmes.setWindowTitle(qs);

	qs = qs.fromStdString(comment);
	qmes.setText(qs);
	
	qmes.exec();
}

ErrorHandle::~ErrorHandle()
{
}
