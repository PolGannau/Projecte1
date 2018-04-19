#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "ModuleCollision.h"
#include "SDL_mixer/include/SDL_mixer.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

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
	Mix_Chunk* fx_1 = nullptr;
	Mix_Chunk* fx_2 = nullptr;
	Mix_Chunk* fx_3 = nullptr;
	Mix_Chunk* fx_4 = nullptr;
	bool destroyed = false;
	bool collision = false;
	bool weapon1 = true;
	bool weapon2 = false;
	bool weapon3 = false;
	bool weapon4 = false;
};

#endif