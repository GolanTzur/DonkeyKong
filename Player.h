#pragma once
#include "MovableObject.h"
#include "general.h"
class Player :public MovableObject
{

private:
	GameConfig::ARROWKEYS dirHammer;
public:
	Player(char _representation, Point _pos) : MovableObject(_representation, _pos, GameConfig::ARROWKEYS::STAY) { dirHammer = GameConfig::ARROWKEYS::STAY; }
	void setDir(GameConfig::ARROWKEYS newdir);
	void setHammer(GameConfig::ARROWKEYS havinghammer) { dirHammer = havinghammer; };
	GameConfig::ARROWKEYS getHammer() { return dirHammer; };
	void draw(bool&& climbmode = false);
	//int getCurrentFloor() { return (GameConfig::NUMFLOORS)-((pos.getY() - (GameConfig::MIN_Y - 1)) / GameConfig::FLOORDIFF); }
};
