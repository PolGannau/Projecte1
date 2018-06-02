#ifndef __ENEMY_TRIPLETURRET_H__
#define __ENEMY_TRIPLETURRET_H__

#include "Enemy.h"

class Enemy_TripleTurret : public Enemy
{
private:
	int original_y = 0;
	Animation fly, idle;


public:

	Enemy_TripleTurret(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif // __ENEMY_TRIPLETURRET_H__

