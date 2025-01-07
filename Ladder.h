#pragma once
#include "GameObject.h"
class Ladder : public GameObject
{
	int steps;
public:
	Ladder(Point _startpos, int _steps = 1) : GameObject('H',_startpos),steps(_steps){}
	void draw();
	int getSteps() { return steps; }
};
