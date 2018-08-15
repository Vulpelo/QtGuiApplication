#include "Controler.h"

using namespace res;

Controler::Controler(IView *nview)
{
	view = nview;
	Resources::initialize();
}

Controler::~Controler()
{
	Resources::exit();
}

void Controler::doCommendFun()
{
	numberOfErrors = 0;
	int nrSlowa = 1;
	polec = 0;/*!*/
	myTextW = 0; 
	for (int i = 0; i < 100; i++)
		myText[i] = '\0';

	c= view->getCommendText();

	if (c.size() > 0)
	{
		DoKommendyPodstawowej(c);

		view->setLastEditedCommand(c);

		nrSlowa = 1;
		wordCommendCombination = "";

		//komenda "znajdz" "P002". (Linux)
		if (StringMod::PobSlowZWiersza(c, 1) == "!000")
		{
			// find logic for linux and windows32
#ifdef linux
			wordCommendCombination += "find ~";
			nrSlowa++;
			while (PobSlowZWiersza(c, nrSlowa) != " ")
			{
				//wyszukiwanie pliku graficznego
				if (PobSlowZWiersza(c, nrSlowa) == "obraz") 
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
#endif

#ifdef _WIN32
			view->addOutText("-!-FIND COMMAND NOT SUPPORTED ON WINDOWS\n");
			return;
			/*
			wordCommendCombination += "where c:\\";
			nrSlowa++;
			while (PobSlowZWiersza(c, nrSlowa) != " ")
			{
				//wyszukiwanie pliku graficznego
				if (PobSlowZWiersza(c, nrSlowa) == "obraz")
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
			wordCommendCombination += "> out.txt ;";
			*/
#endif

			ThreadData data;
			data.commendMain = wordCommendCombination;
			data.commendNumber = "P002";
			data.commendVariables = "";
			data.sleepTime = 0;
			data.view = view;
			data.nrPowiadomienia = 1;

			view->addOutText("Wyszukiwanie...");

			createThread(data);
		}
		else
		{
			while (polec != 2 && StringMod::PobSlowZWiersza(c, nrSlowa) != " ")
			{
				if (StringMod::PobSlowZWiersza(c, nrSlowa)[0] == '$')
				{
					wordCommendCombination += StringMod::PobSlowZWiersza(c, nrSlowa) + " ";
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
				tekst += StringMod::PobSlowZWiersza(c, nrSlowa + i);
			}

			ThreadData data;
			data.commendMain = KomendaPoleceniaSystemu(wordCommendCombination);
			data.commendNumber = NumerPolecenia(wordCommendCombination);
			data.commendVariables = tekst;
			data.view = view;
			// TODO: End of line for linux
			if (wordCommendCombination == "$007 $006 ;")
				data.nrPowiadomienia = 2;
			data.sleepTime = getTimeFromString(c);
			createThread(data);
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

	sZc = StringMod::PobSlowZWiersza(c, wordNr);    //sÂ³owo z wiersza c
	tmpS = KodSlowaKluczowego(sZc);
	lastSpecialWord = tmpS;

	if (tmpS[0] == '!') 
		deleteWordsWithFile(c);
	while (sZc != " ") //pÃªtla dla sÂ³owa z zdania wprowadzonego przez uÂ¿ytkownika
	{
		if (tmpS != " " && tmpS != ";" && lastSpecialWord[0] == tmpS[0])
		{
			lastSpecialWord = tmpS;
			g = 1; Resources::nrpolecen.clear(); Resources::nrpolecen.seekg(0);
			StringMod::ZamienianieSlow(c, tmpS, wordNr);
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
					sZc = StringMod::PobSlowZWiersza(c, wordNr); 
					Resources::slowazmienne.clear(); Resources::slowazmienne.seekg(0);
					while (znalezione == false && getline(Resources::slowazmienne, wierszSlowaZmienne))
					{
						while (StringMod::PobSlowZWiersza(wierszSlowaZmienne, g) != " " && znalezione == false)
						{
							if (sZc == StringMod::PobSlowZWiersza(wierszSlowaZmienne, g))
							{
								StringMod::ZamienianieSlow(c, StringMod::PobSlowZWiersza(wierszSlowaZmienne, 1), wordNr); znalezione = true;
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
		else StringMod::ZamienianieSlow(c, "/delete/", wordNr);

		wordNr++; g = 1; znalezione = false;
		sZc = StringMod::PobSlowZWiersza(c, wordNr);
		tmpS = KodSlowaKluczowego(sZc);
		if (numberOfWordCombination == 0)
			lastSpecialWord = tmpS;
	}
	Resources::slowapolecen.clear(); Resources::nrpolecen.clear(); Resources::slowazmienne.clear();
	Resources::slowapolecen.seekg(0); Resources::nrpolecen.seekg(0); Resources::slowazmienne.seekg(0);
	if (numberOfErrors <= 0)
		view->addOutText("\n#Niewykryto problemow.");
	return c;
}

void Controler::deleteWordsWithFile(string & c)
{
	string sZc, sZdeleteWords;
	int nrSlowa = 1;
	bool found = false;
	sZc = StringMod::PobSlowZWiersza(c, nrSlowa);
	while (sZc != " ")
	{
		Resources::deleteFindWords.clear(); Resources::deleteFindWords.seekg(0);
		Resources::deleteFindWords >> sZdeleteWords;
		while (Resources::deleteFindWords.good() && found == false)
		{
			if (sZc == sZdeleteWords)
			{
				StringMod::ZamienianieSlow(c, "/delete/", nrSlowa);
				found = true;
			}
			Resources::deleteFindWords >> sZdeleteWords;
		}
		nrSlowa++;
		sZc = StringMod::PobSlowZWiersza(c, nrSlowa);
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

void Controler::createThread(ThreadData ndata)
{
	MyThread* t = new MyThread();

	t->data = ndata;

	ThreadHandle th;
	th.setStart(t);
}

long Controler::getTimeFromString(string c)
{
	bool hasTime = false;
	long sleepTime = 0;
	// Finding specified time in commend (if there is)
	int wordNr = 1;
	while (!hasTime && StringMod::PobSlowZWiersza(c, wordNr) != " ")
	{
		if (StringMod::PobSlowZWiersza(c, wordNr)[0] == '%')
			hasTime = 1;
		else
			wordNr++;
	}
	if (hasTime)
	{
		sleepTime = TimeInMsec(StringMod::StringToInteger(StringMod::PobSlowZWiersza(c, wordNr + 1)), StringMod::PobSlowZWiersza(c, wordNr + 2));
		hasTime = false;
	}
	else
		sleepTime = 0;
	return sleepTime;
}

string Controler::KodSlowaKluczowego(string szukaneSlowo)
{
	Resources::slowapolecen.clear(); Resources::slowapolecen.seekg(0);
	string p;
	int g = 1;

	while (getline(Resources::slowapolecen, p))
	{
		while (StringMod::PobSlowZWiersza(p, g + 1) != " ")  //SÂ³owo z wiersza z pliku
		{
			//Druga pÃªtla ktÃ³ra zamienia sÂ³owa zmiennych na sÂ³owa podstawowe(o ile istniejÂ±;sÂ± zapisane w pliku sÂ³owa_zmienne.txt)
			if (szukaneSlowo == StringMod::PobSlowZWiersza(p, g + 1))
			{
				return StringMod::PobSlowZWiersza(p, 1);
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
	Resources::nrpolecen.clear(); Resources::nrpolecen.seekg(0);//??//!!//
	while (getline(Resources::nrpolecen, wiersz))
	{
		if (wiersz == szukanyNumer)
		{
			getline(Resources::nrpolecen, wiersz);
			Resources::nrpolecen.clear(); Resources::nrpolecen.seekg(0);
			return StringMod::StringToInteger(StringMod::PobSlowZWiersza(wiersz, 1));
		}//PobSlowZWiersza(wiersz,2);
		else getline(Resources::nrpolecen, wiersz);
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
	while (getline(Resources::nrpolecen, wiersz))
		if (wiersz == szukanyNumer)
		{
			getline(Resources::nrpolecen, wiersz);
			Resources::nrpolecen.clear(); Resources::nrpolecen.seekg(0);
			return StringMod::PobSlowZWiersza(wiersz, 2);
		}
		else getline(Resources::nrpolecen, wiersz);
		numberOfErrors++;
		string wyjError = "\n!#Blad w funkcji NumerPolecenia &Nieznaleniono numeru polecenia w pliku 'nr_polecen.txt' dla:'" + szukanyNumer + "'";
		view->addOutText(wyjError);
		cout << "ERROR!:NumerPolecenia#Nieznaleziono numeru polecenia z pliku \"nr_polecenia.txt\" dla: " << szukanyNumer << endl;
		return "";
}

string Controler::KomendaPoleceniaSystemu(string szukanyNumer)
{
	string wiersz, wierszWyj = "";
	while (getline(Resources::nrpolecen, wiersz))
		if (wiersz == szukanyNumer)
		{
			getline(Resources::nrpolecen, wiersz);
			int nr = 3;
			while (StringMod::PobSlowZWiersza(wiersz, nr) != ";" && StringMod::PobSlowZWiersza(wiersz, nr) != " ")
			{
				wierszWyj += StringMod::PobSlowZWiersza(wiersz, nr); nr++;
				wierszWyj += " ";
			}
		}
		else getline(Resources::nrpolecen, wiersz);
		Resources::nrpolecen.clear(); Resources::nrpolecen.seekg(0);
		return wierszWyj;
}

void Controler::doCommendButtonPressed() {
	doCommendFun();
}

IAddSynonimContr * Controler::getIAddSynonimCtr()
{
	IAddSynonimContr *asc = new AddSynonimCont;
	return asc;
}

IAddMainWordCtr * Controler::getIAddMainWordCtr()
{
	IAddMainWordCtr *ctr = new AddMainWordCtr;
	return ctr;
}
