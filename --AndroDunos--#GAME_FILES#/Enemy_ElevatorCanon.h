#ifndef __ENEMY_ELEVATORCANON_H__
#define __ENEMY_ELEVATORCANON_H__

#include "Enemy.h"

class Enemy_ElevatorCanon : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation appear, disappear;
	float y = 5;
	int time = 0;
	int num;
	bool now = true;
public:

	Enemy_ElevatorCanon(int x, int y, int num);
	void OnCollision(Collider* collider);
	void Move();
};

#endif