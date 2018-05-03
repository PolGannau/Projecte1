#ifndef __ENEMY_WHITESHIP_H__
#define __ENEMY_WHITESHIP_H__

#include "enemy.h"
#include "Path.h"

class Enemy_WhiteShip : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	Path path;
	iPoint original_pos;

public:

	Enemy_WhiteShip(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif // __ENEMY_WHITESHIP_H__