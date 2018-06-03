#ifndef __ENEMY_SMALLGREEN_H__
#define __ENEMY_SMALLGREEN_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_SmallGreen : public Enemy
{
private:

	Animation fly;
	iPoint original_pos;
	Path path;


public:

	Enemy_SmallGreen(int x, int y, int num);
	void OnCollision(Collider* collider);
	void Move();
};
#endif