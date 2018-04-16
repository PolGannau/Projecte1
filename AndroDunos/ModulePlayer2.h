#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "ModuleCollision.h"
#include "SDL_mixer/include/SDL_mixer.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider*, Collider*);

public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Collider* coll = nullptr;
	Animation idle;
	Animation up;
	Animation down;
	iPoint position;
	Mix_Chunk* fx = nullptr;
	bool destroyed = false;
};

#endif