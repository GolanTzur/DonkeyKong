#pragma once
#include "Point.h"
#include <iostream>
class Hammer
{
private:
	Point pos;
	bool isVisible;
public:
	Hammer(Point _pos) : pos(_pos) { isVisible = true; }
	Point getPos() { return pos; }
	bool getIsVisible() { return isVisible; }
	void setIsVisible(bool _isVisible) { isVisible = _isVisible; }
	void draw();
};

