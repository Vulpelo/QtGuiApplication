#pragma once

#include <QMessageBox>

#include <string>

enum ErrorType{
	E_FILE_NOT_OPENED,
	E_COMMAND_CREATE,
	W_ENTERED_DATA,
	MESSAGE
};

class ErrorHandle
{
public:

	ErrorHandle();
	static std::string getString(ErrorType type, std::string comment = "");
	static std::string getErrorString(ErrorType type);
	static void message(ErrorType type, std::string comment = "");
	~ErrorHandle();
};
