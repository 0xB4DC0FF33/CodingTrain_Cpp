#include "ofApp.h"
#include <string> 



//--------------------------------------------------------------
void ofApp::setup(){
	PS2P_big.load("PressStart2P.ttf", 30);
	PS2P_small.load("PressStart2P.ttf", 15);
	ofSetVerticalSync(false);
	ofSetFrameRate(10);
	gameIsRunning = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetWindowTitle("Score : "+ std::to_string(s.size));
	if (gameIsRunning)
	{
		// Checks if the snake eat itself
		int i = 0;
		for (std::vector<ofVec2f>::iterator it = s.tail.begin(); it != s.tail.end(); ++it) 
		{
			if (s.isEating(*it) && i != s.size-1) // i != s.size to avoid detection of the snake own head 
			{
				gameIsRunning = false;
			}
			i++;
		}
		s.update();
		// if the snake touch the food, the snake grows and the food position is reset
		if (s.isEating(f.pos)) 
		{
			s.grow();
			f.reset();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(51);
	// prints the snake and the food
	s.show();
	f.show();
	if (!gameIsRunning)
	{
		ofSetColor(0);
		PS2P_big.drawString("Game Over !", 110, 300);
		PS2P_small.drawString("Press Enter to restart", 100, 400);
		PS2P_small.drawString("Press Escape to quit the game", 5, 450);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	// ifs are here to avoid going backwards and directly eat the tail
	case OF_KEY_DOWN: 
		if(s.speed != ofVec2f(0, -1)) s.dir(ofVec2f(0, 1));
		break;
	case OF_KEY_UP:
		if (s.speed != ofVec2f(0, 1)) s.dir(ofVec2f(0, -1));
		break;
	case OF_KEY_LEFT: 
		if (s.speed != ofVec2f(1, 0)) s.dir(ofVec2f(-1, 0));
		break;
	case OF_KEY_RIGHT: 
		if (s.speed != ofVec2f(-1, 0)) s.dir(ofVec2f(1, 0));
		break;
	case OF_KEY_RETURN:
		if (!gameIsRunning) // Reset the game
		{
			s.pos = ofVec2f(0, 0);
			s.speed = ofVec2f(1, 0);
			s.size = 0;
			s.tail.clear();
			f.reset();
			gameIsRunning = true;
		}
		break;
	default:
		break;
	}
}
