#include "ErrorHandle.h"

using namespace std;

ErrorHandle::ErrorHandle()
{
}

string ErrorHandle::getString(ErrorType type, string comment)
{
	string s = "-!-";
	switch (type)
	{
	case E_FILE_NOT_OPENED:
		s += "File not opened. Program won't work properly";
		break;
	case E_COMMAND_CREATE:
		s += "Command creating error";
		break;
	default:
		break;
	}
	if (comment.size() > 0) {
		s += ": " + comment;
	}
	s += "\n";

	return s;
}

ErrorHandle::~ErrorHandle()
{
}
