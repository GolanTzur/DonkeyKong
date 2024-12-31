#include "Hammer.h"
#include "general.h"
void Hammer::draw()
{
	if (isVisible)
	{
		gotoxy(pos.getX(), pos.getY());
		std::cout << 'P';
	}
}
