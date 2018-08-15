#pragma once

#include "IAddMainWordCtr.h"

#include <string>

#include "StringMod.h"
#include "ErrorHandle.h"

#include "Resources.h"

class AddMainWordCtr : public IAddMainWordCtr
{
public:
	AddMainWordCtr();

#pragma region IAddMainWordCtr
	void addButtonPressed(std::string newWord);
#pragma endregion

	~AddMainWordCtr();
};
