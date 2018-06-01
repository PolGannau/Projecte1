#ifndef __ENEMY_MULTICOLOR_H__
#define __ENEMY_MULTICOLOR_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_MultiColor : public Enemy
{
private:
	int original_y = 0;
	Animation fly;
	float x, y, m;
	bool now = true;
	iPoint original_pos;
	Path path;

public:

	Enemy_MultiColor(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
