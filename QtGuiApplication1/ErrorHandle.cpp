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
	case FILE_NOT_OPENED:
		s += "File not opened";
		break;
	case COMMAND_CREATE_ERROR:
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
