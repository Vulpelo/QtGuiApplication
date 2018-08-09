#pragma once

#include <string>


enum ErrorType{
	FILE_NOT_OPENED
};

class ErrorHandle
{
public:
	ErrorHandle();
	static std::string getString(ErrorType type, std::string comment = "");
	~ErrorHandle();
};

