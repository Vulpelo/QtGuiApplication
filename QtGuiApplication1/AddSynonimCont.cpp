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
		//wxMessageBox(wxT("!\nBrak wprowadzonego s�owa podstawowego w celu okre�lenia czego synonimem ma by� podane s�owo\n!"));
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
				//wxMessageBox(wxT("Dodano nowy synonim do istniej�cego s�owa"));
			}
			//else
				//wxMessageBox(wxT("!\nWspisie Nieistnieje podane podstawowe s�owo\n!"));
		}
		//else
			//wxMessageBox(wxT("!\nJu� taki synonim zosta� dodany\n!"));
		/*
		if(znaleziono==true)
		{
			if(nrSlowa>1)
				wxMessageBox(wxT("!\nTakie s�owo ju� zosta�o dodane jako synonim\n!"));
			else
				wxMessageBox(wxT("!\nTakie s�owo ju� zosta�o dodane jako s�owo podstawowe\n!"));
		}
		else
		{
			slowazmienne.clear();
			slowazmienne.seekp(0, ios_base::end);
			slowazmienne << AddingWord<<" ; \r";
			wxMessageBox(wxT("Nowe s�owo podstawowe zosta�o utworzone"));
		}
	//
	}
	slowazmienne.close();
	*/
	}
}
