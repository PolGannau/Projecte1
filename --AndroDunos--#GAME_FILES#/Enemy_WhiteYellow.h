#ifndef __ENEMY_WHITEYELLOW_H__
#define __ENEMY_WHITEYELLOW_H__

#include "Enemy.h"

class Enemy_WhiteYellow : public Enemy
{
private:
	int original_y = 0;
	Animation fly;


public:

	Enemy_WhiteYellow(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif