#ifndef __GAMEOVER_H__
#define __GAMEOVER_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;

class ModuleGameover : public Module
{
public:
	ModuleGameover();
	~ModuleGameover();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * losescreen = nullptr;
	SDL_Rect gameover;

	uint fx = 0;

	Mix_Music * music = nullptr;
};

#endif // __MODULESCENEINTRO_H__