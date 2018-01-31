#include "stdafx.h"
#include <vector>
#include <functional>
#include "Rect.h"
#include "RectMath.h"
#include "RectCompressionStrategy.h"

static bool IsCompressable(Rect r1, Rect r2)
{
	//Compressable if one of six edges is touching AND other dimensions are the same and that edge is same size
	if (RectMath::IsCompressableOnX(r1, r2))
		return true;
	if (RectMath::IsCompressableOnY(r1, r2))
		return true;
	if (RectMath::IsCompressableOnZ(r1, r2))
		return true;

	return false;
}

bool RectCompressionStrategy::Naive(std::vector<Rect> &rects)
{
	bool compressed = false;
	if (rects.size() == 1) return false;

	for (unsigned int r2 = 0; r2 < rects.size(); r2++)
	{
		for (unsigned int r1 = 0; r1 < rects.size(); r1++)
		{
			if (r1 != r2)
			{
				if (IsCompressable(rects[r1], rects[r2]))
				{
					RectMath::Combine(rects[r1], rects[r2]);
					rects.erase(rects.begin() + r2);
					r1 = 0;
					r2 = 0;
					compressed = true;
				}
			}
		}
	}
	return compressed;
}

