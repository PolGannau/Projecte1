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
	void OnCollision(Collider* c1, Collider* c2);
	void Spawn();

public:

	SDL_Texture * graphics = nullptr;
	int font_score = -1;
	char score_text[10];
	int font_maxscore = -1;
	uint score = 0;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation stand_fire;
	Animation up;
	Animation down;
	iPoint position;
	unsigned int lastTime = 0, currentTime;
	Collider* coll = nullptr;
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
	int hp;
	bool a = false, x = false;
	bool Up = false;
	int life = 3;
	bool setcoll = false;
	int settcoll = 0;
};

#endif