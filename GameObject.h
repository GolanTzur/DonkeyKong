#pragma once
#include "Point.h"
class GameObject
{
protected :
	const char representation;
	Point pos;
public : 
	GameObject(char _representation, Point _pos) : pos(_pos), representation(_representation){}
	void draw() {
		gotoxy(pos.getX(), pos.getY());cout << representation;
	}
	char getRepresentation() { return representation; };
	Point getPos() { return pos; }
	void setPos(Point _newpos) { pos = _newpos; }

};

