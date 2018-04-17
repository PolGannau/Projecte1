#ifndef __ENEMY_WHITESHIP_H__
#define __ENEMY_WHITESHIP_H__

#include "Enemy.h"

class Enemy_WhiteShip : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_WhiteShip(int x, int y);

	void Move();
};

#endif // __ENEMY_WHITESHIP_H__