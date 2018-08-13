#pragma once
#include <QtWidgets/QTextEdit>
#include "IAddSynonimContr.h"


class ICon
{
public:
	virtual void doCommendButtonPressed() = 0;
	virtual IAddSynonimContr *getIAddSynonimCtr() = 0;
};
