#include "AddSynonimCont.h"

using namespace res;

AddSynonimCont::AddSynonimCont()
{
}

void AddSynonimCont::addButtonPressed(string word, string newWord)
{
	Resources::begining_slowazmienne();
	string ccc, AddingWord, MainWord;
	bool znaleziono = false; int nrSlowa = 1;
	AddingWord = newWord;
	MainWord = word;
	if (MainWord == "")
	{
		ErrorHandle::message(ErrorType::W_ENTERED_DATA,"Brak wprowadzonego slowa podstawowego w celu okreslenia czego synonimem ma byc podane slowo");
	}
	else
	{
		while (Resources::slowazmienne >> ccc && znaleziono == false)
		{
			if (ccc == AddingWord)
				znaleziono = true;
		}
		if (!znaleziono)
		{
			int nrOfLine = 0;
			//begining of file
			Resources::begining_slowazmienne();
			while (!Resources::slowazmienne.eof() && znaleziono == false)
			{
				getline(Resources::slowazmienne, ccc);
				nrOfLine++;
				znaleziono = StringMod::stringContainWord(ccc, MainWord);
			}
			if (znaleziono)
			{
				ccc.insert(ccc.size()-2, AddingWord + " ");

				fstream tmpout;
				tmpout.open((Resources::filesPath + "tmp.txt").c_str(), 'w');

				Resources::begining_slowazmienne();
				{
					string tmp;
					int i = 0;
					while (getline(Resources::slowazmienne, tmp)) {
						i++;
						if (nrOfLine != i) {
							tmpout << (tmp + "\r\n");
						}
						else
							tmpout << (ccc + "\r\n");
					}
				}
				tmpout.close();		

				Resources::exit();
				remove((Resources::filesPath + "slowa_zmienne.txt").c_str());
				rename((Resources::filesPath + "tmp.txt").c_str(), (Resources::filesPath + "slowa_zmienne.txt").c_str());
				Resources::initialize();
				
				ErrorHandle::message(ErrorType::MESSAGE, "Dodano nowy synonim");
			}
			else
				ErrorHandle::message(ErrorType::W_ENTERED_DATA, "W spisie nieistnieje podane podstawowe s³owo");
		}
		else
			ErrorHandle::message(ErrorType::W_ENTERED_DATA, "Juz taki synonim zostal dodany");
		/*
		if(znaleziono==true)
		{
			if(nrSlowa>1)
				wxMessageBox(wxT("!\nTakie s³owo ju¿ zosta³o dodane jako synonim\n!"));
			else
				wxMessageBox(wxT("!\nTakie s³owo ju¿ zosta³o dodane jako s³owo podstawowe\n!"));
		}
		else
		{
			slowazmienne.clear();
			slowazmienne.seekp(0, ios_base::end);
			slowazmienne << AddingWord<<" ; \r";
			wxMessageBox(wxT("Nowe s³owo podstawowe zosta³o utworzone"));
		}
	//
	}
	slowazmienne.close();
	*/
	}
}
