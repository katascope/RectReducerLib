#include "stdafx.h"
#include "RectCompress.h"

bool RectCompress::Compress(std::vector<std::vector<Rect>> &rectsVector, std::function<bool(std::vector<Rect> &rects)> strategy)
{
	bool compressed = false;
	for (unsigned int i = 0; i<rectsVector.size(); i++)
	{
		std::vector<Rect> r = rectsVector[i];
		if (strategy(rectsVector[i]))
			compressed = true;
	}
	return compressed;
}

