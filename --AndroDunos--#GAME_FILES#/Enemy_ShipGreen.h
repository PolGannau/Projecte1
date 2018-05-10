#ifndef __ENEMY_SHIPGREEN_H__
#define __ENEMY_SHIPGREEN_H__

#include "Enemy.h"

class Enemy_ShipGreen : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	int shot = 0;
	float x, y, m;


public:

	Enemy_ShipGreen(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif // __ENEMY_SHIPGREEN_H__