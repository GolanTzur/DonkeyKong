#pragma once
#include "GameConfig.h"
#include "Point.h"
#include "general.h"
class GameObject
{

private:

	Point pos;
	char representation;
	GameConfig::ARROWKEYS dir;
	GameConfig::ARROWKEYS dirHammer;

public:
	GameObject(Point startpos, char representation);
	Point getPos() { return pos; };
	void setPos(int x, int y) { this->pos.setX(x); this->pos.setY(y); }
	char getRepresentation() { return representation; };
	GameConfig::ARROWKEYS getDir() { return dir; };
	void setDir(GameConfig::ARROWKEYS newdir);
	void setHammer(GameConfig::ARROWKEYS havinghammer) { dirHammer = havinghammer; };
	GameConfig::ARROWKEYS getHammer() { return dirHammer; };
	void draw();
	void move();
	int getCurrentFloor() { return (GameConfig::NUMFLOORS)-((pos.getY() - (GameConfig::MIN_Y - 1)) / GameConfig::FLOORDIFF); }
};
