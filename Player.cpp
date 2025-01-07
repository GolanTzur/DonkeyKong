#include "Player.h"
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <iostream>

using namespace std;




void Player::setDir(GameConfig::ARROWKEYS newdir)
{
	MovableObject::setDir(newdir);

	if (dirHammer != GameConfig::ARROWKEYS::STAY)
	{
		if (newdir == GameConfig::ARROWKEYS::LEFT)
			dirHammer = GameConfig::ARROWKEYS::LEFT;
		if (newdir == GameConfig::ARROWKEYS::RIGHT)
			dirHammer = GameConfig::ARROWKEYS::RIGHT;
	}
	
}
void Player::draw(bool&& climbmode) //We would like to show the hammer also
{
	GameObject::draw(); 
	
	if (dirHammer!=GameConfig::ARROWKEYS::STAY&&!climbmode&&(dir==GameConfig::STAY|| dir == GameConfig::LEFT|| dir == GameConfig::RIGHT))
	{

		if (dirHammer == GameConfig::ARROWKEYS::LEFT)
		{
			gotoxy(pos.getX() - 1, pos.getY() - 1);
			cout << 'P';
			
		}
		if (dirHammer == GameConfig::ARROWKEYS::RIGHT)
		{
			gotoxy(pos.getX() + 1, pos.getY() - 1);
			cout << 'P';
		}
			
	}
}

