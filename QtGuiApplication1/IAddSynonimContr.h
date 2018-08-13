#pragma once

#ifndef IADDSYNONIMCONTR_H
#define IADDSYNONIMCONTR_H

#include <string>

using namespace std;

class IAddSynonimContr {
public:
	virtual void addButtonPressed(string word, string newWord) = 0;
};

#endif // !IADDSYNONIMCONTR_H
