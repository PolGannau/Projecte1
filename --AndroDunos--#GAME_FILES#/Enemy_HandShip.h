#ifndef __ENEMY_HANDSHIP_H__
#define __ENEMY_HANDSHIP_H__

#include "Enemy.h"

class Enemy_HandShip : public Enemy
{
private:
	int original_y = 0;
	Animation fly;



public:

	Enemy_HandShip(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
