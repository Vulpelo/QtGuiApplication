#pragma once

#include "IAddSynonimContr.h"

#include <string>
#include "Resources.h"

using namespace std;

class AddSynonimCont : public IAddSynonimContr 
{
public:
	AddSynonimCont();

#pragma region Interface
	void addButtonPressed(string word, string newWord);
#pragma endregion

};
