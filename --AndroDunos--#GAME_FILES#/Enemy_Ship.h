#ifndef __ENEMY_SHIP_H__
#define __ENEMY_SHIP_H__

#include "Enemy.h"

class Enemy_Ship : public Enemy
{
private:
	int original_y = 0;
	Animation fly;


public:

	Enemy_Ship(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
