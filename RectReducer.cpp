// RectReducer.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "RectReducerLib\Rect.h"
#include "RectReducerLib\RectMath.h"
#include "RectReducerLib\RectConverter.h"
#include "RectReducerLib\RectCompress.h"
#include "RectReducerLib\RectCompressionStrategy.h"
#include <list>

int _tmain(int argc, _TCHAR* argv[])
{
	//Need to also include flood fill separation

	printf("RectReducer\n");

	int matrix[3][3][1] = {	0,1,0,	0,1,0,	1,1,1 };
	std::vector<Rect> rects = RectConverter::ArrayToRectangles(1, &matrix[0][0][0], 3, 3, 1);

	RectCompressionStrategy::Naive(rects);

	//Next
	int matrixComplex[3][3][1] = { 
		0, 1, 0, 
		0, 1, 0, 
		1, 1, 1 
	};	

	std::vector<std::vector<Rect>> rectVectors = RectConverter::ArrayToRectVectors(&matrixComplex[0][0][0], 3, 3, 1);	
	RectCompress::Compress(rectVectors, RectCompressionStrategy::Naive);
	for (std::vector<Rect> rects: rectVectors)
		printf("Result (Naive) = %u\n", rects.size());

	std::vector<std::vector<Rect>> rectVectors2 = RectConverter::ArrayToRectVectors(&matrixComplex[0][0][0], 3, 3, 1);
	RectCompress::Compress(rectVectors2, RectCompressionStrategy::XYZ);
	for (std::vector<Rect> rects : rectVectors2)
		printf("Result (XYZ) = %u\n", rects.size());

	std::vector<std::vector<Rect>> rectVectors3 = RectConverter::ArrayToRectVectors(&matrixComplex[0][0][0], 3, 3, 1);
	RectCompress::Compress(rectVectors3, RectCompressionStrategy::BestXYZ);
	for (std::vector<Rect> rects : rectVectors3)
		printf("Result (BestXYZ) = %u\n", rects.size());
	return 0;
}

