#ifndef __ENEMY_MOVEMENTLASER_H__
#define __ENEMY_MOVEMENTLASER_H__

#include "Enemy.h"

class Enemy_MovementLaser : public Enemy
{
private:
	int original_y = 0;
	Animation elevator;


public:

	Enemy_MovementLaser(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
