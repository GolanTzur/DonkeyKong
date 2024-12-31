#pragma once
#include <iostream>
#include "Point.h"
#include "GameConfig.h"
#include "general.h"

using namespace std;

class Ghost
{
private:
	Point pos;
	GameConfig::ARROWKEYS dir;

public:
	Ghost(Point _pos); 
	Point getPos() { return pos; }
	GameConfig::ARROWKEYS getDir() { return dir; }
	void setPos(Point _pos) { pos = _pos; }
	void setDir(GameConfig::ARROWKEYS _dir) { dir = _dir; }
	void move();
	void draw();
};

