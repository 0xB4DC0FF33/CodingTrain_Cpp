#include "Laser.h"


Laser::Laser(ofVec2f p, int d) {
	if (d > 0) {
		texture.load("Images/laserRed.png");
	}
	else if (d < 0) {
		texture.load("Images/laserGreen.png");
	}

	isActive = true;
	pos.x = p.x+15;
	pos.y = p.y-(d * 30);
	dir = d;
}


Laser::~Laser()
{
}

void Laser::show() {
	if (isActive) {
		texture.draw(pos.x, pos.y);
	}
}

void Laser::update() {
	pos.y += dir;
}

bool Laser::hits(ofVec2f p, ofVec2f dim) {
	ofVec2f s1 = ofVec2f(pos.x + 9, pos.y + 33);
	ofVec2f s2 = p + dim;
	return (pos.x < s2.x && s1.x > p.x && pos.y < s2.y && s1.y > p.y && isActive);
}
