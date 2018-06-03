#ifndef __ENEMY_SHIP_H__
#define __ENEMY_SHIP_H__

#include "Enemy.h"
#include "path.h"

class Enemy_Ship : public Enemy
{
private:
	int original_y = 0;
	Animation fly;
	float x, y, m;
	bool now = true;
	iPoint original_pos;
	Path path;

public:

	Enemy_Ship(int x, int y, int num);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
