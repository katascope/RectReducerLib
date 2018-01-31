#include "stdafx.h"
#include "RectConverter.h"

std::vector<Rect> RectConverter::ArrayToRectangles(int id, int *matrix, int width, int height, int depth)
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
				if (matrix[offset] == id)
				{
					//printf("Creating rect %u,%u,%u\n", x, y, z);
					Rect *rect = new Rect(id, x, y, z, x + 1, y + 1, z + 1);
					rects.push_back(*rect);
				}
			}
		}
	}
	return rects;
}

std::set<int> RectConverter::ArrayToIds(int *matrix, int width, int height, int depth)
{
	std::set<int> ids;
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
				int value = matrix[offset];
				ids.insert(value);
			}
		}
	}
	return ids;
}

std::vector<std::vector<Rect>> RectConverter::ArrayToRectVectors(int *matrix, int width, int height, int depth)
{
	std::vector<std::vector<Rect>> vectors;

	std::set<int> ids = ArrayToIds(matrix, width, height, depth);

	for (int id : ids)
	{
		std::vector<Rect> rects = ArrayToRectangles(id, matrix, width, height, depth);
		vectors.push_back(rects);
	}

	return vectors;
}
