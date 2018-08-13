#include "AddSynonimCont.h"

using namespace res;

AddSynonimCont::AddSynonimCont()
{
}

void AddSynonimCont::addButtonPressed(string word, string newWord)
{
	Resources::slowazmienne.clear(); Resources::slowazmienne.seekp(0, ios_base::beg);
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
		if (znaleziono == false)
		{
			Resources::slowazmienne.clear(); Resources::slowazmienne.seekp(0, ios_base::beg);
			while (Resources::slowazmienne >> ccc && znaleziono == false)
			{
				if (ccc == MainWord)
				{
					znaleziono = true;
					//slowazmienne<<AddingWord;
				}
				//nrSlowa++;
			}
			if (znaleziono == true)
			{
				Resources::slowazmienne >> ccc;
				while (ccc != ";")
					Resources::slowazmienne >> ccc;
				// position in file where word should be added
				Resources::slowazmienne.seekp(-1, ios_base::cur);
				// TODO: End line for linux (\r)
				Resources::slowazmienne << AddingWord << " ; \n";
				ErrorHandle::message(ErrorType::MESSAGE, "Dodano nowy synonim do istniej¹cego s³owa");
			}
			else
				ErrorHandle::message(ErrorType::W_ENTERED_DATA, "W spisie Nieistnieje podane podstawowe s³owo");
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
