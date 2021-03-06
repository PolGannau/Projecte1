#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Enemy
{
protected:
	Animation * animation;
	Collider* collider;

public:
	iPoint position;
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	bool hit = false;
	bool dead = false;
	int stop;
public:
	Enemy(int x, int y);
	virtual ~Enemy();

	const Collider* GetCollider() const;
	virtual void OnCollision(Collider* collider);

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);

};

#endif // __ENEMY_H__