#include "stdafx.h"
#include "RectCompress.h"

class RectCompressionStrategy
{
public:
	static bool CompressX(std::vector<Rect> &rects);
	static bool CompressY(std::vector<Rect> &rects);
	static bool CompressZ(std::vector<Rect> &rects);

	static bool Naive(std::vector<Rect> &rects);
	static bool XYZ(std::vector<Rect> &rects);
	static bool BestXYZ(std::vector<Rect> &rects);
};

