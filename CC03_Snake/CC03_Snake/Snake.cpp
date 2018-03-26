#include "Snake.h"
#include "ofMain.h"
#include "ofMath.h"

extern int scl; // Get the grid scale from main.cpp

Snake::Snake()
{
	pos = ofVec2f(0, 0);
	speed = ofVec2f(1, 0);
	size = 0;	// Size of the snake 
}


Snake::~Snake()
{
}

// Update the snake location
void Snake::update() {
	ofVec2f pPos = pos; // Keeps track of the previous position of the snake

	pos += speed;

	// Constrains the X value between 0 and the windows width
	if (pos.x >= ofGetWidth()/scl-1){
		pos.x = ofGetWidth()/scl-1;
	} else if (pos.x <= 0) {
		pos.x = 0;
	}
	// Same thing but on the y value
	if (pos.y >= ofGetHeight()/scl-1) {
		pos.y = ofGetHeight()/scl-1;
	}
	else if (pos.y <= 0) {
		pos.y = 0;
	}

	// makes the tail "follow" the head only if the snake is moving
	if (pPos != pos) {
		tail.push_back(pPos);
		tail.erase(tail.begin());
	}
}

// Draws the snake
void Snake::show() {
	ofSetColor(255);

	// Iterate over the tail and prints every square of the tail
	for (auto const& t : tail) {
		ofDrawRectangle(t.x*scl, t.y*scl, scl, scl);
	}
	// Prints the Head of the snake
	ofDrawRectangle(pos.x*scl, pos.y*scl, scl, scl);
}


// Change the snake direction
void Snake::dir(ofVec2f newSpeed) {
	speed = newSpeed;
}

// Checks if the snake is actually eating food
bool Snake::isEating(ofVec2f testPos) {
	return (pos == testPos);
}

// Make the snake bigger by addin the current head position to the tail
void Snake::grow() {
	size++;
	tail.push_back(pos);
}





// Food constructor : Set the food to a random position 
Food::Food() {
	pos = ofVec2f(roundf(ofRandom(ofGetWidth() / scl)), roundf(ofRandom(ofGetHeight() / scl)));
}

// Simply draws the food as a red rectangle 
void Food::show() { 
	ofSetColor(255, 0, 0);
	ofDrawRectangle(pos.x*scl, pos.y*scl, scl, scl);
}

void Food::reset() {
	pos = ofVec2f(roundf(ofRandom((ofGetWidth() / scl)-1)), roundf(ofRandom((ofGetHeight() / scl)-1)));
}