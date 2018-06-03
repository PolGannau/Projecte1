#ifndef __ENEMY_STRUCTURE_H__
#define __ENEMY_STRUCTURE_H__

#include "Enemy.h"

class Enemy_Structure : public Enemy
{
private:
	int original_y = 0;
	Animation fly, idle;


public:

	Enemy_Structure(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
