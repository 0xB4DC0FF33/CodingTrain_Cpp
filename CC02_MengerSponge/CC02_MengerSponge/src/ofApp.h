#pragma once

#include "../Box.h"
#include "ofMain.h"
#include "ofMaterial.h"
#include "ofLight.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();

		void mousePressed(int x, int y, int button);
		float a;

		ofLight light;
		ofMaterial material;
		ofEasyCam cam;
};
