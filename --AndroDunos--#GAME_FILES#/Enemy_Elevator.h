#ifndef __ENEMY_ELEVATOR_H__
#define __ENEMY_ELEVATOR_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Elevator : public Enemy
{
private:
	int original_y = 0;
	Animation elevator;
	Path path;
	iPoint original_pos;

public:

	Enemy_Elevator(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif // __ENEMY_ELEVATOR_H__
