#pragma once

#include "ofImage.h"
#include "ofMain.h"

class Laser
{
public:
	Laser(ofVec2f p, int d);
	~Laser();

	ofImage texture;
	ofVec2f pos;
	int dir;
	bool isActive;

	void show();
	void update();
	bool hits(ofVec2f pos, ofVec2f dim);

};

