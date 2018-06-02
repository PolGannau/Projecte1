#ifndef __ENEMY_LASER_H__
#define __ENEMY_LASER_H__

#include "Enemy.h"

class Enemy_Laser : public Enemy
{
private:
	int original_y = 0;
	Animation enemy;


public:

	Enemy_Laser(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif

