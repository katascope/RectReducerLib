#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\RectReducerLib\RectConverter.h"
#include "..\RectReducerLib\RectCompress.h"
#include "..\RectReducerLib\RectCompressionStrategy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectCompressUnitTests
{
	TEST_CLASS(UnitTestRectCompress)
	{
	public:

		TEST_METHOD(TestRectCompressRects)
		{
			int array[3][3][1] = { 0, 1, 0, 0, 1, 0, 1, 1, 1 };
			std::vector<Rect> rects = RectConverter::ArrayToRectangles(1, &array[0][0][0], 3, 3, 1);

			RectCompressionStrategy::XYZ(rects);

			Assert::AreEqual(rects.size(), (unsigned int)2);
		}

		TEST_METHOD(TestRectCompressRectsVector)
		{
			int matrixComplex[3][3][1] = {
				0, 1, 2,
				3, 1, 2,
				1, 1, 1
			};

			std::vector<std::vector<Rect>> rectVectors = RectConverter::ArrayToRectVectors(&matrixComplex[0][0][0], 3, 3, 1);
			Assert::AreEqual(rectVectors.size(), (unsigned int)4);

			RectCompress::Compress(rectVectors, RectCompressionStrategy::XYZ);

			Assert::AreEqual(rectVectors[0].size(), (unsigned int)1);
			Assert::AreEqual(rectVectors[1].size(), (unsigned int)2);
			Assert::AreEqual(rectVectors[2].size(), (unsigned int)1);
			Assert::AreEqual(rectVectors[3].size(), (unsigned int)1);
		}
	};
}
