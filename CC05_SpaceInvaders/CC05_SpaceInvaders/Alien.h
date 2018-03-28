#pragma once

#include "ofImage.h"
#include "ofMain.h"

class Alien
{
public:
	Alien(int x, int y);
	~Alien();

	ofImage texture;
	ofImage explosion;
	ofVec2f pos;

	void show();
	//void move(int dir);

	bool isAlive;
	int explosionTime; // Keeps tracks of when the alien was destroyed
};

