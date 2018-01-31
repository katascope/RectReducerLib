#include "stdafx.h"
#include "RectConverter.h"
#include <map>

std::vector<Rect> RectConverter::ArrayToRectangles(int *matrix, int width, int height, int depth)
{
	std::vector<Rect> rects;

	for (int z = 0; z < depth; z++)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				unsigned int offset =
					z * (height * width) +
					y * (width)+
					x;
				Rect rect(matrix[offset], x, y, z, x + 1, y + 1, z + 1);
				rects.push_back(rect);
			}
		}
	}
	return rects;
}

unsigned int RectConverter::RectanglesToDistinctIdCount(std::vector<Rect> rects)
{
	std::set<int> ids;

	for (Rect rect : rects)
		ids.emplace(rect._id);

	return ids.size();
}

std::vector<std::vector<Rect>> RectConverter::RectanglesToSeparatedRectangles(std::vector<Rect> rects)
{
	std::vector<std::vector<Rect>> separated;

	unsigned int types = RectanglesToDistinctIdCount(rects);

	std::map<unsigned int, std::vector<Rect>> maps;

	for (unsigned int rect = 0; rect < rects.size();rect++)
	{
		maps[rects[rect]._id].push_back(rects[rect]);
	}

	for (unsigned int rect = 0; rect < maps.size(); rect++)
	{
		separated.push_back(maps[rect]);
	}

	return separated;
}
