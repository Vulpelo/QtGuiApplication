#pragma once

#include <string>

class IAddMainWordCtr {
public:
	virtual void addButtonPressed(std::string newWord) = 0;
};
