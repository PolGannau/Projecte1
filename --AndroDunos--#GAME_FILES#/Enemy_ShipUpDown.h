#ifndef __ENEMY_SHIPUPDOWN_H__
#define __ENEMY_SHIPUPDOWN_H__

#include "Enemy.h"

class Enemy_ShipUpDown : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_ShipUpDown(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif // __ENEMY_SHIPUPDOWN_H__
