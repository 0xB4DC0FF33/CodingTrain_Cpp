#pragma once
class Star
{
	public:
		Star();
		~Star();

		void update(int);
		void show();

		int x;
		int y;
		int z;
		int pz;
		int maxR;
};
