#include <vector>
#include <cmath>
#include "Box.h"
#include "ofMain.h"


Box::Box(float x, float y, float z, float s)
{
	pos.set(x, y, z);
	size = s;

}


Box::~Box()
{
}

void Box::show() {
	ofPushMatrix();

	ofTranslate(pos.x, pos.y, pos.z);
	ofDrawBox(size);

	ofPopMatrix();
}

std::vector<Box> Box::generate() {
	std::vector<Box> boxes;
	for (float i = -1; i < 2; i++) { // float here to match with the Box constructor
		for (float j = -1; j < 2; j++) {
			for (float k = -1; k < 2; k++) {
				if (abs(i)+abs(j)+abs(k) > 1)
				{
					float newSize = size / 3;
					Box b(pos.x + i*newSize, pos.y + j*newSize, pos.z + k*newSize, newSize);
					boxes.push_back(b);
				}
			}
		}
	}
	return boxes;
}