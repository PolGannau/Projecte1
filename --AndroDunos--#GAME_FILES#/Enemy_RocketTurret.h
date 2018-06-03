#ifndef __ENEMY_ROCKETTURRET_H__
#define __ENEMY_ROCKETTURRET_H__

#include "Enemy.h"

class Enemy_RocketTurret : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	float y = 5;
	int time = 0;
public:

	Enemy_RocketTurret(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif
