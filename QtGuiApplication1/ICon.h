#pragma once
#include <QtWidgets/QTextEdit>
#include "IAddSynonimContr.h"
#include "IAddMainWordCtr.h"

class ICon
{
public:
	virtual void doCommendButtonPressed() = 0;
	virtual IAddSynonimContr *getIAddSynonimCtr() = 0;
	virtual IAddMainWordCtr *getIAddMainWordCtr() = 0;
};
