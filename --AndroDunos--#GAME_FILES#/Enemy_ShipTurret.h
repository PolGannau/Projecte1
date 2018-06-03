#ifndef __ENEMY_SHIPTURRET_H__
#define __ENEMY_SHIPTURRET_H__

#include "Enemy.h"

class Enemy_ShipTurret : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	float y = 5;
	bool z;
	int time = 0;

public:

	Enemy_ShipTurret(int x, int y, bool z);
	void OnCollision(Collider* collider);
	void Move();
};

#endif // __ENEMY_SHIPTURRET_H__
