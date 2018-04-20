#ifndef __MODULESCENESPACE_H__
#define __MODULESCENESPACE_H__

#include "Module.h"
#include "Globals.h"
#include "SDL_mixer/include/SDL_mixer.h"

struct SDL_Texture;

class ModuleSceneSpace : public Module
{
public:
	ModuleSceneSpace();
	~ModuleSceneSpace();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * background1 = nullptr;
	SDL_Texture* floor = nullptr;
	SDL_Texture* stars = nullptr;
	SDL_Texture* hud = nullptr;

	Mix_Music* mus = nullptr;
};

#endif // __MODULESCENESPACE_H__