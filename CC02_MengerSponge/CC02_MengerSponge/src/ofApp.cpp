#include "ofApp.h"
#include "../Box.h"
#include "ofLight.h"
#include "ofMaterial.h"

std::vector<Box> sponge;

//--------------------------------------------------------------
void ofApp::setup(){
	a = 0;

	Box b(0, 0, 0, 200);
	sponge.push_back(b);

	ofEnableDepthTest();
	ofSetVerticalSync(true);
	ofEnableLighting();

	cam.setDistance(500);

	light.setDirectional();
	light.setPosition(-ofGetWidth()/2, -ofGetHeight()/2, 0);
	light.setOrientation(ofVec3f(45, 45, 45));

	material.begin();
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	light.enable();

	ofBackground(51);

	for (unsigned i = 0; i<sponge.size(); ++i) {
		sponge[i].show();
	}
	
	a += 0.01;
	
	light.disable(); 
	cam.end();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 2) {
		std::vector<Box> next;
		for (unsigned i = 0; i<sponge.size(); ++i) {
			std::vector<Box> newBoxes = sponge[i].generate();
			next.insert(next.end(), newBoxes.begin(), newBoxes.end());
		}
		sponge = next;
	}
}
