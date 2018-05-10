#ifndef __ENEMY_VERTICALSTRUCTURE_H__
#define __ENEMY_VERTICALSTRUCTURE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_VerticalStructure : public Enemy
{
private:
	float wave = -1.0f;
	bool stop = false;
	int original_y = 0;
	Animation fly, fly2;
	bool up;
	

public:

	Enemy_VerticalStructure(int x, int y, bool z);
	void OnCollision(Collider* collider);
	void Move();
};

#endif 

