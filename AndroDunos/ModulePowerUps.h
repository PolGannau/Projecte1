#ifndef __ModulePowerUps_H__
#define __ModulePowerUps_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "ModuleCollision.h"
#include "SDL_mixer/include/SDL_mixer.h"

struct SDL_Texture;
struct Collider;

class ModulePowerUps : public Module
{
public:
	ModulePowerUps();
	~ModulePowerUps();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider*, Collider*);

public:

	SDL_Texture * graphics = nullptr;
	Animation* current_animation = nullptr;
	Collider* coll = nullptr;
	Animation idle;
	Animation stand_fire;
	Animation up;
	Animation down;
	iPoint position;

};

#endif
