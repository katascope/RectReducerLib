#include "stdafx.h"
#include "Rect.h"
#include <stdio.h>

Rect::Rect(int id, int x1, int y1, int z1, int x2, int y2, int z2)
{
	_id = id;
	p1.x = x1;
	p1.y = y1;
	p1.z = z1;
	p2.x = x2;
	p2.y = y2;
	p2.z = z2;
}

void Rect::Display()
{
	printf("Rect (%3.0f,%3.0f,%3.0f) - (%3.0f,%3.0f,%3.0f)\n",
		p1.x, p1.y, p1.z,
		p2.x, p2.y, p2.z);
}
