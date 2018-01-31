#if !defined RECT_CONVERTER_DEF
#define RECT_CONVERTER_DEF
#include <vector>
#include <set>
#include "Rect.h"

class RectConverter
{
public:
	static unsigned int RectanglesToDistinctIdCount(std::vector<Rect> rects);
	static std::vector<std::vector<Rect>> RectanglesToSeparatedRectangles(std::vector<Rect> rects);

	static std::vector<Rect> ArrayToRectangles(int *matrix, int width, int height, int depth);
};

#endif