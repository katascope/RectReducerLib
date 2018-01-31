#include "stdafx.h"
#include <vector>
#include <functional>
#include "Rect.h"
#include "RectMath.h"
#include "RectCompressionStrategy.h"

bool RectCompressionStrategy::XYZ(std::vector<Rect> &rects)
{
	bool compressed = true;
	if (rects.size() == 1) return false;

	if (CompressX(rects)) compressed = true;
	if (CompressY(rects)) compressed = true;
	if (CompressZ(rects)) compressed = true;

	return compressed;
}
