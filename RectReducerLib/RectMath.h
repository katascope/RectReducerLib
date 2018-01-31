#if !defined RECTMATH_DEF
#define RECTMATH_DEF
#include "Rect.h"

class RectMath
{
public:
	static double Width(Rect rect);
	static double Height(Rect rect);
	static double Depth(Rect rect);
	static double Volume(Rect rect);
	static void Combine(Rect &r1, Rect r2);
	static bool IsCompressableOnX(Rect r1, Rect r2);
	static bool IsCompressableOnY(Rect r1, Rect r2);
	static bool IsCompressableOnZ(Rect r1, Rect r2);
};

#endif