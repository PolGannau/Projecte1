#ifndef __ENEMY_GREENTURRET_H__
#define __ENEMY_GREENTURRET_H__

#include "Enemy.h"

class Enemy_GreenTurret : public Enemy
{
private:
	float wave = -1.0f;
	int original_y = 0;
	Animation lookingleft, lookingright;
	float bullet = 0;
	bool left;

public:

	unsigned int lastTime = 0, currentTime;
	Enemy_GreenTurret(int x, int y, bool left);
	void OnCollision(Collider* collider);
	void Move();
};

#endif // __ENEMY_GREENTURRET_H__
