#ifndef __MODULESCENESPACE_H__
#define __MODULESCENESPACE_H__

#include "Module.h"
#include "Globals.h"
#include "SDL_mixer/include/SDL_mixer.h"

#define UT_W 385

struct SDL_Texture;
struct SDL_Rect;

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
	SDL_Texture * map_p[6] = { nullptr };
	SDL_Texture * underground = nullptr;
	SDL_Texture * underground_s = nullptr;		//undeground background tiles start
	SDL_Texture * underground_e = nullptr;		//undergound background tiles end
	SDL_Texture * hud = nullptr;
	bool stop_p;

	Mix_Music* mus = nullptr;
};

#endif // __MODULESCENESPACE_H__