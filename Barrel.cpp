#include "Barrel.h"

using namespace std;


void Barrel::move()
{
	MovableObject::move();
	if (dir == GameConfig::DOWNANDLEFT || dir == GameConfig::DOWNANDRIGHT)
		fallsecs++;
}