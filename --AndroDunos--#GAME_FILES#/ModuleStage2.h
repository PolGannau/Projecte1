#ifndef __MODULESTAGE2_H__
#define __MODULESTAGE2_H__

#include "Module.h"
#include "Globals.h"
#include "SDL_mixer/include/SDL_mixer.h"

#define TILEHIGHT 224
#define TILE_WIDTH2 302
#define UT_W 385

struct SDL_Texture;
struct SDL_Rect;

class ModuleStage2 : public Module
{
public:
	ModuleStage2();
	~ModuleStage2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * background1 = nullptr;
	SDL_Texture * map_p[4] = { nullptr };
	SDL_Texture * underground = nullptr;
	SDL_Texture * hud = nullptr;
	bool stop_p;
	bool left_move = false;

	Mix_Music* mus = nullptr;
};

#endif // __MODULESTAGE2_H__