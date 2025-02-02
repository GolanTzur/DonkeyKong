#pragma once
#include "Level.h"
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <experimental/filesystem>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cctype> // for std::isspace




namespace fs = std::experimental::filesystem;
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#define FILELEN 15


class FileHandler
{
private:
	
	 static int containValidNumber(const std::string& str);
	 static int checkFileNameValidity(const string& name);
	 static bool readFileContent(const string& name,Level& tobuild);
	 static int getFloorFile(int numline);
public:
	static bool loadAllFiles(map<int, Level>& alllevels);
	static void deleteDocFiles();
	static bool starts_with(const std::string& str, const std::string& prefix);
	static bool ends_with(const std::string& str, const std::string& suffix);

};

struct Step {
	int timeStep;                        // The in-game time counter (each iteration)
	GameConfig::ARROWKEYS move;            // The movement key (as defined in GameConfig)
	bool hammerUsed;                     // True if the hammer was used at this time step
};

struct Result {
	bool passed;
	vector <Point> lives; //Saves points of time when mario lost lives. x - numberoflives , y - the new value for lives
	int timefinished;
	int livesfinished;
	int scorefinished;
};

