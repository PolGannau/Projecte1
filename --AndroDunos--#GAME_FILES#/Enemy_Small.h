#ifndef __ENEMY_SMALL_H__
#define __ENEMY_SMALL_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Small : public Enemy
{
private:
	int original_y = 0;
	Animation fly;
	float x, y, m;
	iPoint original_pos;
	bool now = true;
	Path path;


public:

	Enemy_Small(int x, int y, int num);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
