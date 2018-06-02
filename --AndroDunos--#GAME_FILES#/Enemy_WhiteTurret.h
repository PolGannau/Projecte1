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
	Animation turret;
	Path path;
	iPoint original_pos;
	float angle;
	int b, h;
	int Time, lastTime;
	bool Shoot;
	bool up;

public:

	Enemy_WhiteTurret(int x, int y, bool up);
	void OnCollision(Collider* collider);
	void Move();
};

#endif // __ENEMY_WHITETURRET_H__
