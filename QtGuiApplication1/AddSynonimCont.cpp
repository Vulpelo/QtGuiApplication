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
		//wxMessageBox(wxT("!\nBrak wprowadzonego s³owa podstawowego w celu okreœlenia czego synonimem ma byæ podane s³owo\n!"));
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
				Resources::slowazmienne.seekp(-1, ios_base::cur);
				// TODO: End line for linux (\r)
				Resources::slowazmienne << AddingWord << " ; \n";
				//wxMessageBox(wxT("Dodano nowy synonim do istniej¹cego s³owa"));
			}
			//else
				//wxMessageBox(wxT("!\nWspisie Nieistnieje podane podstawowe s³owo\n!"));
		}
		//else
			//wxMessageBox(wxT("!\nJu¿ taki synonim zosta³ dodany\n!"));
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
