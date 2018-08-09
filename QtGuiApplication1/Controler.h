#pragma once

#ifndef CONTROLER_H
#define CONTROLER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <ctime>

#include "ErrorHandle.h"
#include "ThreadData.h"
#include "ICon.h"
#include "IView.h"

class Controler : public ICon
{
#pragma region Variables
	IView *view;

	fstream slowazmienne;
	fstream slowapolecen;
	fstream nrpolecen;
	fstream deleteFindWords;

	char myText[100];
	string c, tekst;

	short numberOfErrors;
	int nrSlowa;
	bool jestCzas;
	short polec;/*!*/
	int myTextW;

	string wordCommendCombination;
#pragma endregion

private:
	string DoKommendyPodstawowej(string & c);
	void deleteWordsWithFile(string & c);
	void wait(int howLongInMs);
	long long TimeInMsec(int czas, string typCzasu);
	long long StringToInteger(string c);
	string KodSlowaKluczowego(string szukaneSlowo);
	int IloscZmiennychPolecenia(string szukanyNumer);
	string KomendaPoleceniaSystemu(string szukanyNumer);

	//Zwraca wybrane slowo z wiersza string
	string PobSlowZWiersza(string c, int nr); 

	//podmienia slowo string z slowem w zdaniu string
	string ZamienianieSlow(string & c, string nowe, int NumerSlowa); 

	//wyszukuje i zwraca kod polecenia dla danego numeru sÂ³owa
	string NumerPolecenia(string szukanyNumer); 

	void createThread();
	void doCommendFun();

public:
#pragma region ICon functions
	void doCommendButtonPressed();
#pragma endregion
	Controler(IView *nview);
	~Controler();
};

#endif // CONTROLER_H
