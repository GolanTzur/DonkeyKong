#include <iostream>
#include "general.h"
#include "Ladder.h"

using namespace std;


void Ladder::draw() //Overrides original function
{

	for (int i = this->getPos().getY();i > this->getPos().getY() - steps;i--)
	{
		gotoxy(this->getPos().getX(), i);
		cout << representation;
	}

}