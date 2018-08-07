#pragma once
#include <string>
#include <QtWidgets/QTextEdit>

using namespace std;

class ICon
{
public:
	virtual void doCommendButtonPressed() = 0;
};


class IView {
public:
	virtual string getCommendText() = 0;
	virtual void setLastEditedCommand(string) = 0;
	virtual QTextEdit * getTextOutCtrl() = 0;
	virtual void addOutText(string) = 0;
};
