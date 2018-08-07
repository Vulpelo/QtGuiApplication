#include "Controler.h"

Controler::Controler(IView *nview)
{
	view = nview;
	slowazmienne.open("slowa_zmienne.txt");
	slowapolecen.open("slowa_polecen.txt");
	nrpolecen.open("nr_polecen.txt");
	deleteFindWords.open("wordsFindDelete.txt");
}

Controler::~Controler()
{
	slowapolecen.close();
	slowazmienne.close();
	nrpolecen.close();
	deleteFindWords.close();
}

void Controler::doCommendFun()
{
	numberOfErrors = 0;
	nrSlowa = 1;
	jestCzas = 0;
	polec = 0;/*!*/
	myTextW = 0; 

	for (int i = 0; i<100; i++)
		myText[i] = '\0';

	c= view->getCommendText();

	if (c.size() > 0)
	{
		DoKommendyPodstawowej(c);

		view->setLastEditedCommand(c);

		nrSlowa = 1;
		wordCommendCombination = "";

		//komenda "znajdz" "P002". (Linux)
		if (PobSlowZWiersza(c, 1) == "!000")
		{
			wordCommendCombination += "find ~";
			nrSlowa++;
			while (PobSlowZWiersza(c, nrSlowa) != " ")
			{
				if (PobSlowZWiersza(c, nrSlowa) == "obraz") //wyszukiwanie pliku graficznego
				{
					if (PobSlowZWiersza(c, nrSlowa + 1) == "$008")
					{
						wordCommendCombination += " -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.png'";
						wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.bmp'";
						wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.jpg'";
						wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.jpeg'";
						wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.gif'";
						wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.jps'";
						wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.tiff'";
						wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.flif'";
						wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.xcf'";
						wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.psd'";
						wordCommendCombination += " -o -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*.xpm' -a -iname '*'";
						nrSlowa += 2;
					}
					else
					{
						wordCommendCombination += " -iname '*.jpg' -o -iname '*.bmp' -o -iname '*.gif' -o -iname '*.jps' -o -iname '*.png' -o -iname '*.jpeg'";
						wordCommendCombination += " -o -iname '*.tiff' -o -iname '*.flif' -o -iname '*.xcf' -o -iname '*.xpm' -o -iname '*.psd'";
					}
				}
				else if (PobSlowZWiersza(c, nrSlowa) == "plik") //wyszukiwanie jakiegokolwiek typu pliku po nazwie
				{
					if (PobSlowZWiersza(c, nrSlowa + 1) == "$008")
					{
						wordCommendCombination += " -iname " + PobSlowZWiersza(c, nrSlowa + 2) + " -a -iname '*'";
						nrSlowa += 2;
					}
				}
				//wyszukiwanie po dacie modyfikacji
				else if (PobSlowZWiersza(c, nrSlowa) == "$009")
				{
					if (PobSlowZWiersza(c, nrSlowa + 1) == "$010") //przed
					{
						wordCommendCombination += " -not -newermt " + PobSlowZWiersza(c, nrSlowa + 2);
						nrSlowa += 2;
					}
					else if (PobSlowZWiersza(c, nrSlowa + 1) == "%000") //po
					{
						wordCommendCombination += " -newermt " + PobSlowZWiersza(c, nrSlowa + 2);
						nrSlowa += 2;
					}
					else if (PobSlowZWiersza(c, nrSlowa + 1) == "$011") // miedzy
					{
						if (PobSlowZWiersza(c, nrSlowa + 2) < PobSlowZWiersza(c, nrSlowa + 3))
						{
							wordCommendCombination += " -newermt " + PobSlowZWiersza(c, nrSlowa + 2);
							wordCommendCombination += " -not -newermt " + PobSlowZWiersza(c, nrSlowa + 3);
							nrSlowa += 3;
						}
						else
						{
							wordCommendCombination += " -newermt " + PobSlowZWiersza(c, nrSlowa + 3);
							wordCommendCombination += " -not -newermt " + PobSlowZWiersza(c, nrSlowa + 2);
							nrSlowa += 3;
						}
					}
				}
				//wyszukiwanie po rozmiarze
				else if (PobSlowZWiersza(c, nrSlowa) == "$00A")
				{
					if (PobSlowZWiersza(c, nrSlowa + 1) == "$00B") //do x
					{
						wordCommendCombination += " -size -" + PobSlowZWiersza(c, nrSlowa + 2) + PobSlowZWiersza(c, nrSlowa + 3);
						nrSlowa += 3;
					}
					else if (PobSlowZWiersza(c, nrSlowa + 1) == "$00C") //wiekszye od x
					{
						wordCommendCombination += " -size +" + PobSlowZWiersza(c, nrSlowa + 2) + PobSlowZWiersza(c, nrSlowa + 3);
						nrSlowa += 3;
					}
					else if (PobSlowZWiersza(c, nrSlowa + 1) == "$011")
					{
						if (PobSlowZWiersza(c, nrSlowa + 2) > PobSlowZWiersza(c, nrSlowa + 3))
							wordCommendCombination += " -size +" + PobSlowZWiersza(c, nrSlowa + 2) + PobSlowZWiersza(c, nrSlowa + 4) + "-not -size +" + PobSlowZWiersza(c, nrSlowa + 3) + PobSlowZWiersza(c, nrSlowa + 3);
						else
							wordCommendCombination += " -size +" + PobSlowZWiersza(c, nrSlowa + 3) + PobSlowZWiersza(c, nrSlowa + 4) + "-not -size +" + PobSlowZWiersza(c, nrSlowa + 2) + PobSlowZWiersza(c, nrSlowa + 3);
						nrSlowa += 4;
					}
				}

				nrSlowa++;
			}
			wordCommendCombination += "> out.txt ;";// gnome-open out.txt;";

			//tworzenie watku
			MyThread *t = new MyThread();

			t->data.commendMain = wordCommendCombination;
			t->data.commendNumber = "P002";
			t->data.commendVariables = "";
			t->data.sleepTime = 0;
			t->data.wskTextCtrlOut = view->getTextOutCtrl();
			t->data.nrPowiadomienia = 1;

			ThreadHandle th;
			th.setStart(t);

			view->addOutText("Wyszukiwanie...");
		}
		else
		{
			while (polec != 2 && PobSlowZWiersza(c, nrSlowa) != " ")
			{
				if (PobSlowZWiersza(c, nrSlowa)[0] == '$')
				{
					wordCommendCombination += PobSlowZWiersza(c, nrSlowa) + " ";
					nrSlowa++;
					polec = 1;
				}
				else if (polec != 1)
				{
					nrSlowa++;
				}
				else
					polec = 2;
			}
			// TODO: End line for linux += ";/r";
			tekst = ""; wordCommendCombination += ";";
			for (int i = 0; i < IloscZmiennychPolecenia(wordCommendCombination); i++)
			{
				tekst += PobSlowZWiersza(c, nrSlowa + i);
			}

			createThread();
		}
	}
}

string Controler::DoKommendyPodstawowej(string & c) 
{
	//Czyszczenie znakÃ³w poza literami(zamienianie ich z duÂ¿ych na maÂ³e) i cyframi
	for (int i = c.size() - 1; i >= 0; i--)
	{
		if (c[i] >= 'A' && c[i] <= 'Z') c[i] = c[i] + 32;
		//nieusuwanie określonych znaków i takich w pewnych sytuacjach
		else if ((c[i] == '.' && c[i + 1] >= 'a' && c[i + 1] <= 'z') || c[i] == '*' || c[i] == 39);
		else if ((c[i] >= 33 && c[i] <= 47) || (c[i] >= 58 && c[i] <= 64) || (c[i] >= 91 && c[i] <= 96) || (c[i] >= 123 && c[i] <= 126))
			c.erase(i, 1);
	};

	string sZc, p = "", tmpS, wierszSlowaZmienne;
	string lastSpecialWord;
	int wordNr = 1, g = 1, numberOfWordCombination = 0;
	bool znalezione = false;

	sZc = PobSlowZWiersza(c, wordNr);    //sÂ³owo z wiersza c
	tmpS = KodSlowaKluczowego(sZc);
	lastSpecialWord = tmpS;

	if (tmpS[0] == '!') 
		deleteWordsWithFile(c);
	while (sZc != " ") //pÃªtla dla sÂ³owa z zdania wprowadzonego przez uÂ¿ytkownika
	{
		if (tmpS != " " && tmpS != ";" && lastSpecialWord[0] == tmpS[0])
		{
			lastSpecialWord = tmpS;
			g = 1; nrpolecen.clear(); nrpolecen.seekg(0);
			ZamienianieSlow(c, tmpS, wordNr);
			numberOfWordCombination++;
			p += tmpS + " ";
		}
		else if (numberOfWordCombination>0)
		{
			// TODO: Inny znak końcowy w linux'sie
			p += ";"; //ustawia koncowy znak (windows)
			if (IloscZmiennychPolecenia(p) >0)
			{
				for (int i = IloscZmiennychPolecenia(p); i>0; i--) //and znalezione==0 ?!?
				{
					//Sprawdzanie sÂ³Ã³w z innego pliku (SÂ³owa_zmienne.txt)
					sZc = PobSlowZWiersza(c, wordNr); slowazmienne.clear(); slowazmienne.seekg(0);
					while (znalezione == false && getline(slowazmienne, wierszSlowaZmienne))
					{
						while (PobSlowZWiersza(wierszSlowaZmienne, g) != " " && znalezione == false)
						{
							if (sZc == PobSlowZWiersza(wierszSlowaZmienne, g))
							{
								ZamienianieSlow(c, PobSlowZWiersza(wierszSlowaZmienne, 1), wordNr); znalezione = true;
							}
							g++;
						}
						g = 1;
					}
					znalezione = false;
					wordNr++;
				}

				p = "";
				wordNr--;
				numberOfWordCombination = 0;
			}
			else
			{
				p = "";
				wordNr--;
				numberOfWordCombination = 0;
			}
		}
		else ZamienianieSlow(c, "/delete/", wordNr);

		wordNr++; g = 1; znalezione = false;
		sZc = PobSlowZWiersza(c, wordNr);
		tmpS = KodSlowaKluczowego(sZc);
		if (numberOfWordCombination == 0)
			lastSpecialWord = tmpS;
	}
	slowapolecen.clear(); nrpolecen.clear(); slowazmienne.clear();
	slowapolecen.seekg(0); nrpolecen.seekg(0); slowazmienne.seekg(0);
	if (numberOfErrors <= 0)
		view->addOutText("\n#Niewykryto problemow.");
	return c;
}

void Controler::deleteWordsWithFile(string & c)
{
	string sZc, sZdeleteWords;
	int nrSlowa = 1;
	bool found = false;
	sZc = PobSlowZWiersza(c, nrSlowa);
	while (sZc != " ")
	{
		deleteFindWords.clear(); deleteFindWords.seekg(0);
		deleteFindWords >> sZdeleteWords;
		while (deleteFindWords.good() && found == false)
		{
			if (sZc == sZdeleteWords)
			{
				ZamienianieSlow(c, "/delete/", nrSlowa);
				found = true;
			}
			deleteFindWords >> sZdeleteWords;
		}
		nrSlowa++;
		sZc = PobSlowZWiersza(c, nrSlowa);
		found = false;
	}
}

void Controler::wait(int howLongInMs)
{
	clock_t czas;
	czas = clock() + howLongInMs;
	while (czas>clock());
	return;
}

long long Controler::StringToInteger(string c)
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

string Controler::PobSlowZWiersza(string c, int nr)
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
	cout << "!!!Nie istnieje taki numer slowa!!!\n";
	return " ";
}

string Controler::ZamienianieSlow(string & c, string nowe, int NumerSlowa)
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

void Controler::createThread()
{
	MyThread* t = new MyThread();

	t->data.commendMain = KomendaPoleceniaSystemu(wordCommendCombination);
	t->data.commendNumber = NumerPolecenia(wordCommendCombination);
	t->data.commendVariables = tekst;
	t->data.wskTextCtrlOut = view->getTextOutCtrl();

	// TODO: End of line for linux
	if (wordCommendCombination == "$007 $006 ;")
		t->data.nrPowiadomienia = 2;

	// Finding specified time in commend (if there is)
	nrSlowa = 1;
	while (jestCzas == 0 && PobSlowZWiersza(c, nrSlowa) != " ")
	{
		if (PobSlowZWiersza(c, nrSlowa)[0] == '%')
			jestCzas = 1;
		else
			nrSlowa++;
	}
	if (jestCzas)
	{
		t->data.sleepTime = TimeInMsec(StringToInteger(PobSlowZWiersza(c, nrSlowa + 1)), PobSlowZWiersza(c, nrSlowa + 2));
		jestCzas = false;
	}
	else
		t->data.sleepTime = 0;

	ThreadHandle th;
	th.setStart(t);
}

string Controler::KodSlowaKluczowego(string szukaneSlowo)
{
	slowapolecen.clear(); slowapolecen.seekg(0);
	string p;
	int g = 1;

	while (getline(slowapolecen, p))
	{
		while (PobSlowZWiersza(p, g + 1) != " ")  //SÂ³owo z wiersza z pliku
		{
			//Druga pÃªtla ktÃ³ra zamienia sÂ³owa zmiennych na sÂ³owa podstawowe(o ile istniejÂ±;sÂ± zapisane w pliku sÂ³owa_zmienne.txt)
			if (szukaneSlowo == PobSlowZWiersza(p, g + 1))
			{
				return PobSlowZWiersza(p, 1);
			};
			g++;
		}
		g = 1;
	}

	numberOfErrors++;
	string wyjError = "\n!#Blad w funkcji KodSlowaKluczowego &Brak danych w pliku 'slowa_polecen.txt' dla:'" + szukaneSlowo + "'";
	view->addOutText(wyjError);
	cout << "Nieznane slowo polecenia: " << szukaneSlowo << " . Nieodnalezione w \"slowa_polecen.txt\"" << endl;
	return " ";
}

int Controler::IloscZmiennychPolecenia(string szukanyNumer)
{
	string wiersz, wierszWyj;//int nr=1;
	nrpolecen.clear(); nrpolecen.seekg(0);//??//!!//
	while (getline(nrpolecen, wiersz))
	{
		if (wiersz == szukanyNumer)
		{
			getline(nrpolecen, wiersz);
			nrpolecen.clear(); nrpolecen.seekg(0);
			return StringToInteger(PobSlowZWiersza(wiersz, 1));
		}//PobSlowZWiersza(wiersz,2);
		else getline(nrpolecen, wiersz);
	}
	numberOfErrors++;
	string wyjError = "\n!#Blad w funkcji IloscZmiennychPolecenia &Brak danych w pliku 'nr_polecenia.txt' dla:'" + szukanyNumer + "'";
	view->addOutText(wyjError);
	cout << "ERROR!:IloscZmiennychPolecenia#Brak danych w pliku nr_polecenia.txt dla:" << szukanyNumer << endl;
	return 0;
}

long long Controler::TimeInMsec(int czas, string typCzasu)
{
	//if(typCzasu=="sek")czas=czas*1000;
	if (typCzasu == "min")czas = czas * 60;
	else if (typCzasu == "h")czas = czas * 3600;
	return czas;
}

string Controler::NumerPolecenia(string szukanyNumer)
{
	string wiersz;
	while (getline(nrpolecen, wiersz))
		if (wiersz == szukanyNumer)
		{
			getline(nrpolecen, wiersz);
			nrpolecen.clear(); nrpolecen.seekg(0);
			return PobSlowZWiersza(wiersz, 2);
		}
		else getline(nrpolecen, wiersz);
		numberOfErrors++;
		string wyjError = "\n!#Blad w funkcji NumerPolecenia &Nieznaleniono numeru polecenia w pliku 'nr_polecen.txt' dla:'" + szukanyNumer + "'";
		view->addOutText(wyjError);
		cout << "ERROR!:NumerPolecenia#Nieznaleziono numeru polecenia z pliku \"nr_polecenia.txt\" dla: " << szukanyNumer << endl;
		return "";
}

string Controler::KomendaPoleceniaSystemu(string szukanyNumer)
{
	string wiersz, wierszWyj = "";
	while (getline(nrpolecen, wiersz))
		if (wiersz == szukanyNumer)
		{
			getline(nrpolecen, wiersz);
			int nr = 3;
			while (PobSlowZWiersza(wiersz, nr) != ";" && PobSlowZWiersza(wiersz, nr) != " ")
			{
				wierszWyj += PobSlowZWiersza(wiersz, nr); nr++;
				wierszWyj += " ";
			}
		}
		else getline(nrpolecen, wiersz);
		nrpolecen.clear(); nrpolecen.seekg(0);
		return wierszWyj;
}

void Controler::doCommendButtonPressed() {
	doCommendFun();
}
