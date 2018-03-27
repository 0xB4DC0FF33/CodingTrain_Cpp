#pragma once

#include <vector>

#include "ofMain.h"
#include "../Drop.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();		

		int dropCount;
		std::vector<Drop*> drops;
};
