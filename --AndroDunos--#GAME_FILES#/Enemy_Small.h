#ifndef __ENEMY_SMALL_H__
#define __ENEMY_SMALL_H__

#include "Enemy.h"

class Enemy_Small : public Enemy
{
private:
	int original_y = 0;
	Animation fly;


public:

	Enemy_Small(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
