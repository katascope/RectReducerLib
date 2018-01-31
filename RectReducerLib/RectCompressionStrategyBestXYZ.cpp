#include "stdafx.h"
#include <vector>
#include <functional>
#include "Rect.h"
#include "RectMath.h"
#include "RectCompressionStrategy.h"

bool RectCompressionStrategy::BestXYZ(std::vector<Rect> &rects)
{
	bool compressed = true;
	if (rects.size() == 1) return false;

	std::vector<Rect> rectsXYZ(rects.begin(), rects.end());
	std::vector<Rect> rectsYXZ(rects.begin(), rects.end());
	std::vector<Rect> rectsZXY(rects.begin(), rects.end());

	CompressX(rectsXYZ);
	CompressY(rectsXYZ);
	CompressZ(rectsXYZ);

	CompressY(rectsYXZ);
	CompressX(rectsYXZ);
	CompressZ(rectsYXZ);

	CompressZ(rectsZXY);
	CompressY(rectsZXY);
	CompressX(rectsZXY);

	if (rectsXYZ.size() < rectsYXZ.size() && rectsZXY.size())
	{
		//do xyz
		if (CompressX(rects)) compressed = true;
		if (CompressY(rects)) compressed = true;
		if (CompressZ(rects)) compressed = true;
		
	}
	else if (rectsYXZ.size() < rectsXYZ.size() && rectsZXY.size())
	{
		//do yxz
		if (CompressY(rects)) compressed = true;
		if (CompressX(rects)) compressed = true;
		if (CompressZ(rects)) compressed = true;
	}
	else 
	{
		//do zxy
		if (CompressZ(rects)) compressed = true;
		if (CompressX(rects)) compressed = true;
		if (CompressY(rects)) compressed = true;
	}

	return compressed;
}
