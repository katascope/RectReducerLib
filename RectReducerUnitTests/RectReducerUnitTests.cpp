#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\RectReducerLib\Rect.h"
#include "..\RectReducerLib\RectMath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectReducerUnitTests
{		
	TEST_CLASS(UnitTestRectReducer)
	{
	public:

		TEST_METHOD(TestRectAssign)
		{
			Rect rect(38, 0, 1, 2, 3, 4, 5);
			Assert::AreEqual(rect._id, 38);

			Assert::AreEqual(rect.p1.x, 0.0);
			Assert::AreEqual(rect.p1.y, 1.0);
			Assert::AreEqual(rect.p1.z, 2.0);
			Assert::AreEqual(rect.p2.x, 3.0);
			Assert::AreEqual(rect.p2.y, 4.0);
			Assert::AreEqual(rect.p2.z, 5.0);
		}

		TEST_METHOD(TestRectMathWidthHeightDepth)
		{
			Rect rect(1, 0, 0, 0, 1, 2, 3);			
			Assert::AreEqual(RectMath::Width(rect), 1.0);
			Assert::AreEqual(RectMath::Height(rect), 2.0);
			Assert::AreEqual(RectMath::Depth(rect), 3.0);
		}

		TEST_METHOD(TestRectMathVolume)
		{
			Rect rect(1, 0, 0, 0, 1, 1, 1);
			Assert::AreEqual(RectMath::Volume(rect), 1.0);
		}

	};
}