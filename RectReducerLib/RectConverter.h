#if !defined RECT_CONVERTER_DEF
#define RECT_CONVERTER_DEF
#include <vector>
#include <set>
#include "Rect.h"

class RectConverter
{
public:
	static std::vector<Rect> ArrayToRectangles(int id, int *matrix, int width, int height, int depth);
	static std::set<int> ArrayToIds(int *matrix, int width, int height, int depth);
	static std::vector<std::vector<Rect>> ArrayToRectVectors(int *matrix, int width, int height, int depth);
};

#endif