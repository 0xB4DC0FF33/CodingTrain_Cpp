#include "Alien.h"

extern int timer;

Alien::Alien(int x, int y)
{
	texture.load("Images/alien.png");
	explosion.load("Images/boom.png");
	pos = ofVec2f(x, y);
	isAlive = true;
}


Alien::~Alien()
{
}

void Alien::show() {
	if (isAlive) {
		texture.draw(pos.x, pos.y, 40, 40);
	}
	else {
		if (timer - explosionTime < 2000 && (timer - explosionTime) % 500 < 250) {
			explosion.draw(pos.x, pos.y, 40, 40);
		}
	}
	
}

void Alien::move(int dir) {
	pos.x += dir * 4;
}