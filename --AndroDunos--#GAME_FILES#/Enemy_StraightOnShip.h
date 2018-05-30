#ifndef __ENEMY_STRAIGHTONSHIP_H__
#define __ENEMY_STRAIGHTONSHIP_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_StraightOnShip : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	int movement;
	Path path;
	iPoint original_pos;

public:

	Enemy_StraightOnShip(int x, int y, int num);
	void OnCollision(Collider* collider);
	void Move();
};

#endif 
