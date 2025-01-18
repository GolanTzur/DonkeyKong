#include "Ghost.h"


Ghost::Ghost(Point _pos) : MovableObject('x', _pos, GameConfig::ARROWKEYS::STAY)
{
	//Generate rand number 0 or 1 for the starting moving direction
	char num = rand() % 2;
	num == 0 ? dir = GameConfig::ARROWKEYS::RIGHT : dir = GameConfig::ARROWKEYS::LEFT;
	pos = _pos;
	MovableObject('o', pos, dir);
}



