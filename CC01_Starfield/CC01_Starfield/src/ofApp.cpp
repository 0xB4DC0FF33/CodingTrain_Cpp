#include "ofApp.h"
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	starCount = ofGetWidth()/4;
	stars = new Star[starCount];
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	int speed = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 50);

	for (int i = 0; i < starCount-1; i++)
	{
		stars[i].update(speed);
		stars[i].show();
	}
}

