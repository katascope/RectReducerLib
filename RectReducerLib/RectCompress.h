#if !defined RECT_COMPRESS_DEF
#define RECT_COMPRESS_DEF
#include "Rect.h"
#include "RectMath.h"
#include <vector>
#include <functional>

class RectCompress
{
public:
	static bool Compress(std::vector<Rect> &rects);
	static bool Compress(std::vector<std::vector<Rect>> &rectsVector);
	static bool RectCompress::Compress(std::vector<std::vector<Rect>> &rectsVector, std::function<bool(std::vector<Rect> &rects)> strategy);
};

#endif
