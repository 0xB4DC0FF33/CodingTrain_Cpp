#include "Drop.h"



Drop::Drop()
{
	pos = ofVec3f(ofRandom(ofGetWidth()), ofRandom(-ofGetHeight(), 0), ofRandom(0, 20));
	yspeed = ofMap(pos.z, 0, 20, 4, 10);
	len = ofMap(pos.z, 0, 20, 10, 20);
	width = ofMap(pos.z, 0, 20, 1, 3);
	alpha = ofRandom(50, 255);
}


Drop::~Drop()
{
}

void Drop::fall() 
{
	pos.y += yspeed;
	yspeed += ofMap(pos.z, 0, 20, 0.1, 0.2);

	if (pos.y > ofGetHeight())
	{
		yspeed = ofMap(pos.z, 0, 20, 4, 10);
		pos = ofVec3f(ofRandom(ofGetWidth()), ofRandom(-ofGetHeight(), 0), ofRandom(0, 20));
	}
}

void Drop::show()
{
	ofSetColor(138, 43, 226, alpha);
	glLineWidth(width);
	ofDrawLine(pos.x, pos.y, pos.x, pos.y+len);
}
