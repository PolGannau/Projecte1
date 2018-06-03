#ifndef __ENEMY_BOSS2_H__
#define __ENEMY_BOSS2_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Boss2 : public Enemy
{
private:
	int original_y = 0;
	Animation nomove, boss;
	Path path;
	iPoint original_pos;

public:

	Enemy_Boss2(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
