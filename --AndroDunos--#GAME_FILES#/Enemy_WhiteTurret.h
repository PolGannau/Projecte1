#ifndef __ENEMY_WHITETURRET_H__
#define __ENEMY_WHITETURRET_H__

#include "enemy.h"
#include "Path.h"

class Enemy_WhiteTurret : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation left, right;
	Path path;
	iPoint original_pos;
	bool leftt = true, leftup = false, leftup2 = false, upleft = false, up = false;
	bool upright = false, rightup2 = false, rightup = false, rightt = false;
	bool leftdown = false, leftdown2 = false, downleft = false, down = false;
	bool downright = false, rightdown2 = false, rightdown = false;

public:

	Enemy_WhiteTurret(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif // __ENEMY_WHITETURRET_H__
