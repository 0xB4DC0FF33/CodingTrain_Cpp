#pragma once

#include "ofImage.h"
#include "ofMain.h"

class Spaceship
{
public:
	Spaceship();
	~Spaceship();

	ofImage texture;
	ofVec2f pos;

	void show();
	void move(int dir);
};

