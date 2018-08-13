#include "StringMod.h"

StringMod::StringMod()
{
}

char * StringMod::toChar(string c)
{
	return nullptr;
}

StringMod::~StringMod()
{
}

long long StringMod::StringToInteger(string c)
{
	int liczba = 0, tmp = 0;
	for (int i = c.size() - 1, j = 1; i >= 0; i--, j *= 10)
	{
		tmp = c[i] - 48;
		tmp = tmp*j;
		liczba += tmp;
	}
	return liczba;
}

int StringMod::endPositionOfWordInString(string c, int start)
{
	int pozk = start;
	bool ignoreNextSeparator = false;
	while (c[pozk] != '\0' && c[pozk] != '\n' && c[pozk] != '\r')
	{
		// if there isn't space between words
		if (c[pozk] != ' ')
		{
			pozk++;
			if (c[pozk] == '\"')
			{
				if (ignoreNextSeparator) // closing ..."
					ignoreNextSeparator = false;
				else // opening "...
					ignoreNextSeparator = true;
			}
		}
		// if there is space between words
		else {
			// if words are in quotes "..."
			if (ignoreNextSeparator) {
				pozk++;
			}
			// else end loop
			else
				break;
		}
	}
	return pozk;
}

string StringMod::PobSlowZWiersza(string c, int nr)
{
	int pozp = 0, pozk = 0, actualNr = 0;
	bool ignoreNextSeparator = false;
	string s;
	while (pozk<c.size())
	{
		pozk = endPositionOfWordInString(c, pozp);
		actualNr++;
		if (actualNr == nr)
			return s.insert(0, c, pozp, pozk - pozp);
		else
		{
			pozk++;
			pozp = pozk;
		};
	}
	return " ";
}

bool StringMod::stringContainWord(string c, string word)
{
	int pozp = 0, pozk = 0, actualNr = 0;
	bool ignoreNextSeparator = false;
	string s;
	while (pozk < c.size())
	{
		pozk = endPositionOfWordInString(c, pozp);
		actualNr++;
		if (word == s.insert(0, c, pozp, pozk - pozp))
			return true;
		else
		{
			s = "";
			pozk++;
			pozp = pozk;
		};
	}
	return false;
}

string StringMod::ZamienianieSlow(string & c, string nowe, int NumerSlowa)
{
	int pozp = 0, pozk = 0, anr = 0;
	bool ignoreNextSeparator = false;
	while (pozk<c.size())
	{
		pozk = endPositionOfWordInString(c, pozp);
		anr++;
		if (anr == NumerSlowa)
		{
			if (nowe == "/delete/")
				return c.erase(pozp, pozk - pozp + 1);
			c.erase(pozp, pozk - pozp);
			return c.insert(pozp, nowe);
		}
		else
		{
			pozp = pozk + 1;
			pozk++;
		};
	}
}
