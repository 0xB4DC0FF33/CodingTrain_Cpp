#include "ofApp.h"

// Get the timer variable from main.cpp
extern int timer;

//--------------------------------------------------------------
void ofApp::setup(){
	lastShot = 0;
	aliensPos = ofVec2f(200, 0);
	aliensDir = 1; // 1 = Move left   |  -1 = Move Right
	aliensLastDir = aliensDir;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 5; j++) {
			aliens.push_back(Alien(i * 50 + aliensPos.x, j*40));
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	timer = ofGetElapsedTimeMillis();
	// if aliens havn't move since 500ms
	if (timer - aliensLastMove > 500) {
		if ((aliensPos.x == 10 || aliensPos.x >= ofGetWidth()-(50*11+10)) && aliensLastDir == aliensDir) {
			move = ofVec2f(ofVec2f(0, 20));
			aliensLastDir = aliensDir;
			aliensDir = -aliensDir;
		} else {
			move = ofVec2f(-(10 * aliensDir), 0);
			aliensLastDir = aliensDir;
		}
		// move aliens
		for (size_t i = 0; i < aliens.size(); i++) {			
			aliens[i].pos = aliens[i].pos + move;
		}
		aliensPos = aliens[0].pos;
		aliensLastMove = timer;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(51);

	for (size_t i = 0; i < aliens.size(); i++) {
		aliens[i].show();
	}
	for (size_t i = 0; i < lasers.size(); i++){
		lasers[i].update();
		lasers[i].show();
		
		// Check collision between laser and any aliens 
		for (size_t j = 0; j < aliens.size() - 1; j++) {
			if (lasers[i].hits(aliens[j].pos, ofVec2f(40, 40)) && aliens[j].isAlive) {
				aliens[j].explosionTime = timer;
				aliens[j].isAlive = false;
				lasers[i].isActive = false; // Only deactivate the laser for the moment, cannot remove it now
			}
		}

		if (lasers[i].pos.y < -50) { // delete the laser if it go beyond the screen border
			lasers[i].isActive = false;
		}
	}
	ship.show();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case ' ':
		// if 0.5sec elapsed since the last fire
		if (timer-lastShot > 500)
		{
			lasers.push_back(Laser(ship.pos, -1));	// Fire 
			lastShot = timer;			// Reset the firerate counter
		}
		break;
	case OF_KEY_RIGHT:
		ship.move(+1);
		break;
	case OF_KEY_LEFT:
		ship.move(-1);
		break;
	}
}
