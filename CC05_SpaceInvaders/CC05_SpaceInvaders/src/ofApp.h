#pragma once

#include "ofMain.h"
#include "../Spaceship.h"
#include "../Alien.h"
#include "../Laser.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);		

		Spaceship ship;

		vector<Alien> aliens; 
		vector<Laser> lasers;

		int aliensDir;
		int aliensLastDir;
		int lastShot;
		int aliensLastMove;
		ofVec2f aliensPos;
		ofVec2f move;
};
