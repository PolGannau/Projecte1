#ifndef __MODULEVISCOGAMES_H__
#define __MODULEVISCOGAMES_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleViscoGames : public Module
{
public:
	ModuleViscoGames();
	~ModuleViscoGames();
	Animation* anim = nullptr;
	Animation* anim2 = nullptr;
	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * visco = nullptr;
	Animation Visco;
	Animation Games;
	uint fx = 0;
	Mix_Music * music = nullptr;
};

#endif // __MODULEVISCOGAMES_H__
