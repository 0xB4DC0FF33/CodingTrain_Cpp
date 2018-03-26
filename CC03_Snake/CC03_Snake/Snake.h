#pragma once
#include <vector>
#include "ofMain.h"


class Food
{
public:
	Food();

	ofVec2f pos; // 2D vector storing the food current position

	void show();
	void reset();
};



class Snake
{
public:
	Snake();
	~Snake();
	
	void update();
	void show();
	void dir(ofVec2f newSpeed);
	bool isEating(ofVec2f testPos);
	void grow();
	
	ofVec2f pos;			// 2D vector storing the snake current position
	ofVec2f speed;			// 2D vector storing the snake current speed

	int size;				// Size of the snake
	vector<ofVec2f> tail;	// Store the position of each part of the tail 
};

