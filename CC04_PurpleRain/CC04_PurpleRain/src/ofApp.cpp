#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	dropCount = 300;
	for (int i = 0; i < dropCount; i++) {
		drops.push_back(new Drop());
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (Drop* d: drops)
	{
		d->fall();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(230, 230, 250);
	
	for (Drop* d : drops)
	{
		
		d->show();
	}
}