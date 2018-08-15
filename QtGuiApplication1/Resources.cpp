#include "Resources.h"

namespace res {
	std::fstream Resources::nrpolecen;
	std::fstream Resources::slowapolecen;
	std::fstream Resources::slowazmienne;
	std::fstream Resources::deleteFindWords;
	std::string Resources::filesPath;

	void Resources::begining_slowazmienne()
	{
		Resources::slowazmienne.clear();
		Resources::slowazmienne.seekp(0, std::ios_base::beg);
	}
	void Resources::begining_slowapolecen()
	{
		Resources::slowapolecen.clear();
		Resources::slowapolecen.seekp(0, std::ios_base::beg);
	}
	void Resources::begining_nrpolecen()
	{
		Resources::nrpolecen.clear();
		Resources::nrpolecen.seekp(0, std::ios_base::beg);
	}
	void Resources::begining_deleteFindWords()
	{
		Resources::deleteFindWords.clear();
		Resources::deleteFindWords.seekp(0, std::ios_base::beg);
	}

	void Resources::ending_slowazmienne()
	{
		Resources::slowazmienne.clear();
		Resources::slowazmienne.seekp(0, std::ios_base::end);
	}
	void Resources::ending_slowapolecen()
	{
		Resources::slowapolecen.clear();
		Resources::slowapolecen.seekp(0, std::ios_base::end);
	}
	void Resources::ending_nrpolecen()
	{
		Resources::nrpolecen.clear();
		Resources::nrpolecen.seekp(0, std::ios_base::end);
	}
	void Resources::ending_deleteFindWords()
	{
		Resources::deleteFindWords.clear();
		Resources::deleteFindWords.seekp(0, std::ios_base::end);
	}
}
