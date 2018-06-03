#ifndef __ENEMY_TURRETRED_H__
#define __ENEMY_TURRETRED_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_TurretRed : public Enemy
{
private:
	int original_y = 0;
	Animation left;
	iPoint original_pos;
	Path path;

public:

	Enemy_TurretRed(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif

