#include "ofMath.h"
#pragma once


class Box
{
public:
	Box(float x, float y, float z, float s);
	~Box();

	void show();
	std::vector<Box> generate();

	ofVec3f pos;
	float size;
};

