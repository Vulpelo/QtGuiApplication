#include "AddMainWordCtr.h"

using namespace res;

AddMainWordCtr::AddMainWordCtr()
{
}

void AddMainWordCtr::addButtonPressed(std::string newWord)
{
	Resources::begining_slowazmienne;
	std::string ccc;
	bool znaleziono = false; int nrSlowa = 1;
	if (newWord.size() > 0) {
		while (getline(Resources::slowazmienne, ccc) && znaleziono == false)
		{
			nrSlowa = 1;
			while (StringMod::PobSlowZWiersza(ccc, nrSlowa) != " " && znaleziono == false)
			{
				if (StringMod::PobSlowZWiersza(ccc, nrSlowa) == newWord) znaleziono = true;
				nrSlowa++;
			}
		}
		if (znaleziono == true)
		{
			if (nrSlowa > 1)
				ErrorHandle::message(ErrorType::MESSAGE, "Takie slowo ju¿ zostalo dodane jako synonim");
			else
				ErrorHandle::message(ErrorType::MESSAGE, "Takie slowo ju¿ zostalo dodane jako slowo podstawowe");
		}
		else
		{
			Resources::ending_slowazmienne();
			Resources::slowazmienne << newWord << " ; \r\n";

			//reopening files
			Resources::exit();
			Resources::initialize();

			ErrorHandle::message(ErrorType::MESSAGE, "Nowe slowo podstawowe zostalo utworzone");
		}
	}
	else {
		ErrorHandle::message(ErrorType::W_ENTERED_DATA, "Brak slowa do dodania");
	}
}


AddMainWordCtr::~AddMainWordCtr()
{
}
