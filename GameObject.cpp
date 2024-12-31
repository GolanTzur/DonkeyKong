#include "GameObject.h"
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <iostream>

using namespace std;

GameObject::GameObject(Point startpos, char representation)
{
	this->dir = GameConfig::ARROWKEYS::STAY;
	this->pos = startpos;
	this->representation = representation;
	dirHammer = GameConfig::ARROWKEYS::STAY;
}

void GameObject::move()
{
	
	switch (dir)
	{
	case GameConfig::UP:
		(pos.setY(pos.getY() - 1));
		break;
	case GameConfig::DOWN:
		(pos.setY(pos.getY() + 1));
		break;
	case GameConfig::RIGHT:
		(pos.setX(pos.getX() + 1));
		break;
	case GameConfig::LEFT:
		(pos.setX(pos.getX() - 1));
		break;
	case GameConfig::STAY:
		break;
	case GameConfig::DOWNANDLEFT:
		(pos.setY(pos.getY() + 1));
		(pos.setX(pos.getX() - 1));
		break;
	case GameConfig::DOWNANDRIGHT:
		(pos.setY(pos.getY() + 1));
		(pos.setX(pos.getX() + 1));
		break;
	case GameConfig::UPANDLEFT:
		(pos.setY(pos.getY() - 1));
		(pos.setX(pos.getX() - 1));
		break;
	case GameConfig::UPANDRIGHT:
		(pos.setY(pos.getY() - 1));
		(pos.setX(pos.getX() + 1));
		break;
	}
}
void GameObject::setDir(GameConfig::ARROWKEYS newdir)
{
	if (dirHammer != GameConfig::ARROWKEYS::STAY)
	{
		if (newdir == GameConfig::ARROWKEYS::LEFT)
			dirHammer = GameConfig::ARROWKEYS::LEFT;
		if (newdir == GameConfig::ARROWKEYS::RIGHT)
			dirHammer = GameConfig::ARROWKEYS::RIGHT;
	}
	dir = newdir;
}
void GameObject::draw()
{
	gotoxy(pos.getX(), pos.getY());
	cout << representation;
	static GameConfig::ARROWKEYS lastdir=GameConfig::STAY;
    

	if (dirHammer!=GameConfig::ARROWKEYS::STAY)
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

