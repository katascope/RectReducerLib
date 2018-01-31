#include "stdafx.h"
#include "RectMath.h"
#include <math.h>

double RectMath::Width(Rect rect)
{
	return (rect.p2.x - rect.p1.x);
}

double RectMath::Height(Rect rect)
{
	return (rect.p2.y - rect.p1.y);
}

double RectMath::Depth(Rect rect)
{
	return (rect.p2.z - rect.p1.z);
}

double RectMath::Volume(Rect rect)
{
	return (Width(rect) * Height(rect)  * Depth(rect));
}

void RectMath::Combine(Rect &r1, Rect r2)
{
	r1.p1.x = fmin(r1.p1.x, r2.p1.x);
	r1.p1.y = fmin(r1.p1.y, r2.p1.y);
	r1.p1.z = fmin(r1.p1.z, r2.p1.z);
	r1.p2.x = fmax(r1.p2.x, r2.p2.x);
	r1.p2.y = fmax(r1.p2.y, r2.p2.y);
	r1.p2.z = fmax(r1.p2.z, r2.p2.z);
}

bool RectMath::IsCompressableOnX(Rect r1, Rect r2)
{
	//Compressable if one of six edges is touching AND other dimensions are the same and that edge is same size

	//Compressible on X
	if ((r1.p1.x == r2.p2.x) || //touches left
		(r1.p2.x == r2.p1.x)) //touches right
	{
		if (r1.p1.y == r2.p1.y && r1.p2.y == r2.p2.y &&  r1.p1.z == r2.p1.z && r1.p2.z == r2.p2.z)
			if ((RectMath::Height(r1) == RectMath::Height(r2)) && (RectMath::Depth(r1) == RectMath::Depth(r2)))
				return true;
	}
	return false;
}

bool RectMath::IsCompressableOnY(Rect r1, Rect r2)
{
	//Compressible on Y
	if ((r1.p1.y == r2.p2.y) || //touches front
		(r1.p2.y == r2.p1.y)) //touches back
	{
		if (r1.p1.x == r2.p1.x && r1.p2.x == r2.p2.x &&  r1.p1.z == r2.p1.z && r1.p2.z == r2.p2.z)
			if ((RectMath::Width(r1) == RectMath::Width(r2)) && (RectMath::Depth(r1) == RectMath::Depth(r2)))
				return true;
	}
	return false;
}

bool RectMath::IsCompressableOnZ(Rect r1, Rect r2)
{
//Compressible on Z
	if ((r1.p1.z == r2.p2.z) || //touches bottom
		(r1.p2.z == r2.p1.z)) //touches top
	{
		if (r1.p1.x == r2.p1.x && r1.p2.x == r2.p2.x &&  r1.p1.y == r2.p1.y && r1.p2.y == r2.p2.y)
			if ((RectMath::Width(r1) == RectMath::Width(r2)) && (RectMath::Height(r1) == RectMath::Height(r2)))
				return true;
	}
	return false;
}

