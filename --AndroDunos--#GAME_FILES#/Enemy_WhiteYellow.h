#ifndef __ENEMY_WHITEYELLOW_H__
#define __ENEMY_WHITEYELLOW_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_WhiteYellow : public Enemy
{
private:
	int original_y = 0;
	Animation fly;
	Path path;
	iPoint original_pos;

public:

	Enemy_WhiteYellow(int x, int y, int mov);
	void OnCollision(Collider* collider);
	void Move();
};

#endif