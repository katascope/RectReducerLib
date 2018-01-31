#include "stdafx.h"
/*class TaggedFloodFill
{
	static void TagByFloodFill(int x, int y, int[, ] srcData, int[, ] dstData, int search, int tag)
	{
		//Return if out of range
		if (x < 0 || y < 0 || x >= srcData.GetLength(1) || y >= srcData.GetLength(0))
			return;

		if (srcData[y, x] != search)//return if not correct cell value
			return;

		if (dstData[y, x] != 0)//return if already tagged
			return;

		dstData[y, x] = tag;

		TagByFloodFill(x, y - 1, srcData, dstData, search, tag);
		TagByFloodFill(x - 1, y, srcData, dstData, search, tag);
		TagByFloodFill(x + 1, y, srcData, dstData, search, tag);
		TagByFloodFill(x, y + 1, srcData, dstData, search, tag);
	}

	public static int[, ] TagArray(int[, ] srcData, ref int maxTag)
	{
		int[, ] newData = new int[srcData.GetLength(0), srcData.GetLength(1)];

		maxTag = 0;
		for (int y = 0; y < srcData.GetLength(0); y++)
		{
			for (int x = 0; x < srcData.GetLength(1); x++)
			{
				if (newData[y, x] == 0)
					maxTag++;
				int search = srcData[y, x];
				TagByFloodFill(x, y, srcData, newData, search, maxTag);
			}
		}
		return newData;
	}
}
*/