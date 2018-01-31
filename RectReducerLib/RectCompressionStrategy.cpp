#include "stdafx.h"
#include <vector>
#include <functional>
#include "Rect.h"
#include "RectMath.h"
#include "RectCompressionStrategy.h"

bool RectCompressionStrategy::CompressX(std::vector<Rect> &rects)
{
	bool compressed = true;
	if (rects.size() == 1) return false;

	for (unsigned int r2 = 0; r2 < rects.size(); r2++)
	{
		for (unsigned int r1 = 0; r1 < rects.size(); r1++)
		{
			if (r1 != r2)
			{
				if (RectMath::IsCompressableOnX(rects[r1], rects[r2]))
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
	return false;
}

bool RectCompressionStrategy::CompressY(std::vector<Rect> &rects)
{
	bool compressed = true;
	if (rects.size() == 1) return false;

	for (unsigned int r2 = 0; r2 < rects.size(); r2++)
	{
		for (unsigned int r1 = 0; r1 < rects.size(); r1++)
		{
			if (r1 != r2)
			{
				if (RectMath::IsCompressableOnY(rects[r1], rects[r2]))
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
	return false;
}

bool RectCompressionStrategy::CompressZ(std::vector<Rect> &rects)
{
	bool compressed = true;
	if (rects.size() == 1) return false;

	for (unsigned int r2 = 0; r2 < rects.size(); r2++)
	{
		for (unsigned int r1 = 0; r1 < rects.size(); r1++)
		{
			if (r1 != r2)
			{
				if (RectMath::IsCompressableOnZ(rects[r1], rects[r2]))
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
	return false;
}
