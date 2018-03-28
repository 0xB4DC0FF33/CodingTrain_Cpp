#include "Spaceship.h"



Spaceship::Spaceship()
{
	texture.load("Images/spaceship.png");
	pos = ofVec2f(ofGetWidth() / 2, ofGetHeight()-40);
}


Spaceship::~Spaceship()
{
}

void Spaceship::show() {
	texture.draw(pos.x, pos.y, 40, 40);
}

void Spaceship::move(int dir) {
	pos.x += dir*4;
}