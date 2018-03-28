#include "ofApp.h"

// Get the timer variable from main.cpp
extern int timer;

//--------------------------------------------------------------
void ofApp::setup(){
	lastShot = 0;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 5; j++) {
			aliens.push_back(Alien(i * 40 + 200 + (i * 10), j*40));
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	timer = ofGetElapsedTimeMillis();
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
				cout << "GOOD !" << endl;
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
