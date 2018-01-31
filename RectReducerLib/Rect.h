#if !defined RECTREDUCER_RECT
#define RECTREDUCER_RECT
#include "Point.h"

class Rect
{
public:
	int _id;
	Point p1;
	Point p2;
public:
	Rect(int id, int x1, int y1, int z1, int x2, int y2, int z2);

	void Display();
};


#endif