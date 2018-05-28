#ifndef __POWERUPRED_H__
#define __POWERUPRED_H__

#include "PowerUp.h"

class PowerUpRed : public PowerUp
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	
public:

	PowerUpRed(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif

