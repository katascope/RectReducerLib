#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\RectReducerLib\RectConverter.h"
#include "..\RectReducerLib\RectCompress.h"
#include "..\RectReducerLib\RectCompressionStrategy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectCompressOptimalUnitTests
{
	TEST_CLASS(UnitTestRectCompressOptimal)
	{
	public:

		TEST_METHOD(TestRectCompressOptimalCase1)
		{
			int array[3][3][1] = { 
				0, 1, 0, 
				0, 1, 0, 
				1, 1, 1
			};
			std::vector<Rect> rects = RectConverter::ArrayToRectangles(1, &array[0][0][0], 3, 3, 1);
			RectCompressionStrategy::BestXYZ(rects);

			Assert::AreEqual(rects.size(), (unsigned int)2);
		}

		TEST_METHOD(TestRectCompressOptimalCase2)
		{
			int array[3][3][1] = {
				0, 0, 1,
				1, 1, 1,
				0, 0, 1
			};
			std::vector<Rect> rects = RectConverter::ArrayToRectangles(1, &array[0][0][0], 3, 3, 1);
			RectCompressionStrategy::BestXYZ(rects);

			Assert::AreEqual(rects.size(), (unsigned int)2);
		}
	};
}
