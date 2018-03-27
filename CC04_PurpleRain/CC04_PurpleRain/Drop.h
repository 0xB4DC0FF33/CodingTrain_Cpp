#pragma once

#include "ofMain.h"

class Drop
{
public:
	Drop();
	~Drop();

	ofVec3f pos;
	float len;
	float yspeed;
	float width;
	float alpha;

	void fall();
	void show();
};

