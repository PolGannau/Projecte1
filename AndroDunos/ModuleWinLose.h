#ifndef __MODULEWINLOSE_H__
#define __MODULEWINLOSE_H__

#include "Module.h"
#include "Globals.h"
#include "SDL_mixer/include/SDL_mixer.h"

struct SDL_Texture;

class ModuleWinLose : public Module
{
public:
	ModuleWinLose();
	~ModuleWinLose();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * stageclear = nullptr;
	SDL_Rect winlose;

	uint fx = 0;

	Mix_Music* mus = nullptr;
};

#endif // __MODULESCENEINTRO_H__