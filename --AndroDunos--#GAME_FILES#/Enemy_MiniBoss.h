#ifndef __ENEMY_MINIBOSS_H__
#define __ENEMY_MINIBOSS_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_MiniBoss : public Enemy
{
private:
	int original_y = 0;
	Animation fly;
	iPoint original_pos;
	Path path;
	int time = 0;
	float x, y, m;
	int time2 = 0;
	bool go = false;
	float mov = 0;
public:

	Enemy_MiniBoss(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
