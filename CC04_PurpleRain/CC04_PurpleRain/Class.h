#pragma once
class Class
{
public:
	Class();
	~Class();

	ofVec2f pos;
	float yspeed;

	void fall();
	void show();
};

