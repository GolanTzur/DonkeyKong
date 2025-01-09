#include "FileHandler.h"
bool FileHandler::starts_with(const std::string& str, const std::string& prefix)
{
	return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}
bool FileHandler::ends_with(const std::string& str, const std::string& suffix)
{
	return str.size() >= suffix.size() &&
		str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}
int FileHandler::containValidNumber(const std::string& str)
{
	int mul = 1;
	int sum = 0;
	if (str[6] < '0' || str[6]>'9' || str[7] < '0' || str[7] > '9')
		return -1;

	sum += (str[6] - '0') + (str[7] - '0') * 10;
		return sum;
	
}
int FileHandler::checkFileNameValidity(const string& name)
{
	if (name.size() == FILELEN && starts_with(name, "dkong_") && ends_with(name, ".screen"))
	{
		return containValidNumber(name);
	}
	return 0;
}
bool FileHandler::loadAllFiles(map<int, Level>& alllevels)
{
	bool res=false;

	for (const auto& entry : fs::directory_iterator(fs::current_path()))
	{
		int curLevel;
		if ((curLevel = checkFileNameValidity(entry.path().filename().string())) != 0)
		{
			if (!readFileContent(entry.path().filename().string(), alllevels[curLevel]))
				alllevels.erase(curLevel);
			else
				res = true;
		}
	}

	return res;
}
bool FileHandler:: readFileContent(const string& name,Level& tobuild)
{

}