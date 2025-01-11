#include "FileHandler.h"
#include <fstream>
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
bool FileHandler:: lookForLegend(const Point& startpos, const string& str, Point* legendPos) 
{ 
	size_t pos = str.find("Lives", startpos.getX());
	
	if (pos != string::npos) //Found
	{
		legendPos->setY(startpos.getY());
		legendPos->setX(pos);
		return true;
	}

	false;
}

bool FileHandler:: readFileContent(const string& name,Level& tobuild)
{
	string line;
	bool valid = false;
	ifstream myFile(name, ios::in);
	int currsize,currrow=7,currcol=0,numlines=0;
	Point boardPos;

	while (getline(myFile, line)&&line.empty()==true)
	{
		//Empty Lines in the start of the file should increase the y coordinate of the beginning of the board
			boardPos.setY(boardPos.getY() + 1);
	}
	if (myFile.eof())
		return false;

	//Looking for the upper bound of the board
	while (line[boardPos.getX()] != ' '&& boardPos.getX()<line.length()-GameConfig::WIDTH)
		boardPos.setX(boardPos.getX()+1);

	if (!(boardPos.getX() < line.length() - GameConfig::WIDTH))
		return false;

	for (int i = 0;i < GameConfig::WIDTH;i++)
	{
		if (line[boardPos.getX() + i] != 'Q')
			return false;
	}

	do
	{
		
		if(numlines==0)
		while(line[i]!=' ')
		numlines++;
	} while (getline(myFile, line));


	return valid;
}