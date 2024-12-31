#include "Ghost.h"


Ghost::Ghost(Point _pos): pos(_pos) 
{
	//Generate rand number 0 or 1 for the starting moving direction
	char num = rand() % 2;
	num == 0 ? dir = GameConfig::ARROWKEYS::RIGHT : dir = GameConfig::ARROWKEYS::LEFT;
}

void Ghost::draw()
{
	gotoxy(pos.getX(), pos.getY());
	cout << 'x';
}
void Ghost::move()
{
	if ((pos.getX() > GameConfig::MIN_X + GameConfig::WIDTH - 2)|| (pos.getX() < GameConfig::MIN_X + 2)) //reached the bounds 
		pos.getX() > GameConfig::MIN_X + GameConfig::WIDTH - 2 ? dir = GameConfig::ARROWKEYS::LEFT : dir = GameConfig::ARROWKEYS::RIGHT;
	else // change the direction with 0.95 chance
	{
		char num = rand() % 20;
		if (num == 0)
			dir == GameConfig::ARROWKEYS::RIGHT ? dir = GameConfig::ARROWKEYS::LEFT : dir = GameConfig::ARROWKEYS::RIGHT;
		//cout << dir;
	}

	switch (dir)
	{
	case GameConfig::RIGHT:
		(pos.setX(pos.getX() + 1));
		break;
	case GameConfig::LEFT:
		(pos.setX(pos.getX() - 1));
		break;
	}
}
