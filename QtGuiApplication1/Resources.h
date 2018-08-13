#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <ctime>

#ifndef RESOURCES_H
#define RESOURCES_H

namespace res
{
	class Resources {
	public:
		static std::string filesPath;
		static bool initialize()
		{
#ifdef linux
			Resources::filesPath = "./Resources/linux/";
			slowazmienne.open("./Resources/linux/slowa_zmienne.txt");
			if (!slowazmienne.good())
			{
				//view->addOutText(ErrorHandle::getString(ErrorType::FILE_NOT_OPENED, "\"slowa_zmienne.txt\""));
				return false;
			}
			slowapolecen.open("./Resources/linux/slowa_polecen.txt");
			if (!slowapolecen.good())
			{
				//view->addOutText(ErrorHandle::getString(ErrorType::FILE_NOT_OPENED, "\"slowa_polecen.txt\""));
				return false;
			}
			nrpolecen.open("./Resources/linux/nr_polecen.txt");
			if (!nrpolecen.good())
			{
				//view->addOutText(ErrorHandle::getString(ErrorType::FILE_NOT_OPENED, "\"nr_polecen.txt\""));
				return false;
			}
			deleteFindWords.open("./Resources/linux/wordsFindDelete.txt");
			if (!deleteFindWords.good())
			{
				//view->addOutText(ErrorHandle::getString(ErrorType::FILE_NOT_OPENED, "\"wordsFindDelete.txt\""));
				return false;
			}
#endif
#ifdef _WIN32
			Resources::filesPath = "./Resources/win32/";
			if(!slowazmienne.is_open())
				slowazmienne.open("./Resources/win32/slowa_zmienne.txt");
			if (!slowazmienne.good())
			{
				//view->addOutText(ErrorHandle::getString(ErrorType::E_FILE_NOT_OPENED, "\"slowa_zmienne.txt\""));
				return false;
			}
			if (!slowapolecen.is_open())
			slowapolecen.open("./Resources/win32/slowa_polecen.txt");
			if (!slowapolecen.good())
			{
				//view->addOutText(ErrorHandle::getString(ErrorType::E_FILE_NOT_OPENED, "\"slowa_polecen.txt\""));
				return false;
			}
			if (!nrpolecen.is_open())
				nrpolecen.open("./Resources/win32/nr_polecen.txt");
			if (!nrpolecen.good())
			{
				//view->addOutText(ErrorHandle::getString(ErrorType::E_FILE_NOT_OPENED, "\"nr_polecen.txt\""));
				return false;
			}
			if (!deleteFindWords.is_open())
				deleteFindWords.open("./Resources/win32/wordsFindDelete.txt");
			if (!deleteFindWords.good())
			{
				//view->addOutText(ErrorHandle::getString(ErrorType::E_FILE_NOT_OPENED, "\"wordsFindDelete.txt\""));
				return false;
			}
#endif
			return true;
		}
		static void exit() {
			slowapolecen.close();
			slowazmienne.close();
			nrpolecen.close();
			deleteFindWords.close();
		}
		static std::fstream slowazmienne;
		static std::fstream slowapolecen;
		static std::fstream nrpolecen;
		static std::fstream deleteFindWords;

		static void begining_slowazmienne();
		static void begining_slowapolecen();
		static void begining_nrpolecen();
		static void begining_deleteFindWords();
	};
};

#endif // !RESOURCES_H
