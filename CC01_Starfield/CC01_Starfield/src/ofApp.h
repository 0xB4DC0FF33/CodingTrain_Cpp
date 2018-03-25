#pragma once

#include "ofMain.h"
#include "../Star.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();

		int starCount;
		Star* stars;
};
