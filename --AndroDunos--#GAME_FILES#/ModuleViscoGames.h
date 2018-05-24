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
	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * visco = nullptr;
	SDL_Texture * games = nullptr;
	SDL_Rect Visco;
	SDL_Rect Games;
	uint fx = 0;
	int time = 0;
	int time2 = 0;
	int x = 2;
	int y = 2;
	bool movement = false;
	Mix_Music * music = nullptr;
};

#endif // __MODULEVISCOGAMES_H__
