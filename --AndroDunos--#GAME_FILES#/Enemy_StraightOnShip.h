#ifndef __ENEMY_STRAIGHTONSHIP_H__
#define __ENEMY_STRAIGHTONSHIP_H__

#include "Enemy.h"

class Enemy_StraightOnShip : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_StraightOnShip(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif 
