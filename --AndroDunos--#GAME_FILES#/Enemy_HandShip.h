#ifndef __ENEMY_HANDSHIP_H__
#define __ENEMY_HANDSHIP_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_HandShip : public Enemy
{
private:
	int original_y = 0;
	Animation fly;
	float x, y, m;
	bool now = true;
	iPoint original_pos;

public:

	Enemy_HandShip(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
