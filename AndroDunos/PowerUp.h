#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class PowerUp
{
protected:
	Animation * animation = nullptr;
	Collider* collider = nullptr;

public:
	iPoint position;

public:
	PowerUp(int x, int y);
	virtual ~PowerUp();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider);
};

#endif // __POWERUP_H__
