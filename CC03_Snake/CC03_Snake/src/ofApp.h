#pragma once

#include "ofMain.h"
#include "../Snake.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		Snake s;
		Food f;

		bool gameIsRunning;
		ofTrueTypeFont PS2P_big;
		ofTrueTypeFont PS2P_small;
};
