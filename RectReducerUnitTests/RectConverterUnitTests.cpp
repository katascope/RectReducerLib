#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\RectReducerLib\RectConverter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectConverterUnitTests
{
	TEST_CLASS(UnitTestRectConverter)
	{
	public:

		TEST_METHOD(TestRectConverterArray)
		{
			int array[3][3][1] =
			{
				0, 1, 0,
				0, 1, 0,
				1, 1, 1
			};

			std::vector<Rect> rects = RectConverter::ArrayToRectangles(1, &array[0][0][0], 3, 3, 1);

			Assert::AreEqual((unsigned long)rects.size(), (unsigned long)5);
		}
	};
}