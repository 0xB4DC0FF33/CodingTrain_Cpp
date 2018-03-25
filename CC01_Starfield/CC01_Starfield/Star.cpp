#include "Star.h"
#include "ofMain.h"
#include "ofMath.h"

Star::Star()
{
	x = ofRandom(-ofGetWidth()/2, ofGetWidth()/2);
	y = ofRandom(-ofGetHeight()/2, ofGetHeight()/2);
	z = ofRandom(0, ofGetWidth());
	maxR = ofRandom(5, 15);
	pz = z;
}


Star::~Star()
{

}


void Star::update(int speed) {
	z -= speed;

	if (z < 1) {
		x = ofRandom(-ofGetWidth()/2, ofGetWidth()/2);
		y = ofRandom(-ofGetHeight()/2, ofGetHeight()/2);
		z = ofRandom(0, ofGetWidth());
		pz = z;
	}
}

void Star::show() {
	ofColor(255);

	ofPushMatrix();

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float sx = ofMap((float)x / (float)z, 0, 1, 0, ofGetWidth());
	float sy = ofMap((float)y / (float)z, 0, 1, 0, ofGetHeight());

	float r = ofMap(z, 0, ofGetWidth(), maxR, 0);
	ofDrawCircle(sx, sy, r);

	float px = ofMap((float)x / (float)pz, 0, 1, 0, ofGetWidth());
	float py = ofMap((float)y / (float)pz, 0, 1, 0, ofGetHeight());
	ofDrawLine(px, py, sx, sy);

	pz = z;

	ofPopMatrix();
}