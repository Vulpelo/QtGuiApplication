#pragma once

#include <string>

enum ErrorType{
	E_FILE_NOT_OPENED,
	E_COMMAND_CREATE
};

class ErrorHandle
{
public:
	ErrorHandle();
	static std::string getString(ErrorType type, std::string comment = "");
	~ErrorHandle();
};
