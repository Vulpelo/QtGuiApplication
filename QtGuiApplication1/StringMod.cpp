#include "StringMod.h"

StringMod::StringMod()
{
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

string StringMod::PobSlowZWiersza(string c, int nr)
{
	int pozp = 0, pozk = 0, anr = 0;
	string s;
	while (pozk<c.size())
	{
		while (c[pozk] != ' ' && c[pozk] != '\0' && c[pozk] != '\n' && c[pozk] != '\r')
			pozk++;
		anr++;
		if (anr == nr)
			return s.insert(0, c, pozp, pozk - pozp);
		else
		{
			pozk++;
			pozp = pozk;
		};
	}
	return " ";
}

string StringMod::ZamienianieSlow(string & c, string nowe, int NumerSlowa)
{
	int pozp = 0, pozk = 0, anr = 0;
	while (pozk<c.size())
	{
		while (c[pozk] != ' ' && c[pozk] != '\0')
			pozk++;
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
