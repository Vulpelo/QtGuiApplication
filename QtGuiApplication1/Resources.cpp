#include "Resources.h"
//
//namespace Resources {
//	bool initialize()
//	{
//#ifdef linux
//		slowazmienne.open("./Resources/linux/slowa_zmienne.txt");
//		if (!slowazmienne.good())
//		{
//			//view->addOutText(ErrorHandle::getString(ErrorType::FILE_NOT_OPENED, "\"slowa_zmienne.txt\""));
//			return false;
//		}
//		slowapolecen.open("./Resources/linux/slowa_polecen.txt");
//		if (!slowapolecen.good())
//		{
//			//view->addOutText(ErrorHandle::getString(ErrorType::FILE_NOT_OPENED, "\"slowa_polecen.txt\""));
//			return false;
//		}
//		nrpolecen.open("./Resources/linux/nr_polecen.txt");
//		if (!nrpolecen.good())
//		{
//			//view->addOutText(ErrorHandle::getString(ErrorType::FILE_NOT_OPENED, "\"nr_polecen.txt\""));
//			return false;
//		}
//		deleteFindWords.open("./Resources/linux/wordsFindDelete.txt");
//		if (!deleteFindWords.good())
//		{
//			//view->addOutText(ErrorHandle::getString(ErrorType::FILE_NOT_OPENED, "\"wordsFindDelete.txt\""));
//			return false;
//		}
//#endif
//#ifdef _WIN32
//		slowazmienne.open("./Resources/win32/slowa_zmienne.txt");
//		if (!slowazmienne.good())
//		{
//			//view->addOutText(ErrorHandle::getString(ErrorType::E_FILE_NOT_OPENED, "\"slowa_zmienne.txt\""));
//			return false;
//		}
//		dsadsa->open("dsadsa.txt");
//		slowapolecen.open("./Resources/win32/slowa_polecen.txt");
//		if (!slowapolecen.good())
//		{
//			//view->addOutText(ErrorHandle::getString(ErrorType::E_FILE_NOT_OPENED, "\"slowa_polecen.txt\""));
//			return false;
//		}
//		nrpolecen.open("./Resources/win32/nr_polecen.txt");
//		if (!nrpolecen.good())
//		{
//			//view->addOutText(ErrorHandle::getString(ErrorType::E_FILE_NOT_OPENED, "\"nr_polecen.txt\""));
//			return false;
//		}
//		deleteFindWords.open("./Resources/win32/wordsFindDelete.txt");
//		if (!deleteFindWords.good())
//		{
//			//view->addOutText(ErrorHandle::getString(ErrorType::E_FILE_NOT_OPENED, "\"wordsFindDelete.txt\""));
//			return false;
//		}
//#endif
//		return true;
//	}
//
//	void exit() {
//		slowapolecen.close();
//		slowazmienne.close();
//		nrpolecen.close();
//		deleteFindWords.close();
//	}
//
//}

namespace res {
	std::fstream Resources::nrpolecen;
	std::fstream Resources::slowapolecen;
	std::fstream Resources::slowazmienne;
	std::fstream Resources::deleteFindWords;
}