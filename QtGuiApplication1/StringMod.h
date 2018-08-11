#pragma once

#include <string>

using namespace std;

class StringMod
{
private:
	static int StringMod::endPositionOfWordInString(string c, int start);
public:
	StringMod();
	static long long StringToInteger(string c);
	static string PobSlowZWiersza(string c, int nr);
	static string ZamienianieSlow(string & c, string nowe, int NumerSlowa);
	~StringMod();
};

