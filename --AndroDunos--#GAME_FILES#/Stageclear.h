#ifndef __STAGECLEAR_H__
#define __STAGECLEAR_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;

class ModuleStageclear : public Module
{
public:
	ModuleStageclear();
	~ModuleStageclear();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * winscreen = nullptr;
	SDL_Rect stageclear;

	uint fx = 0;

	Mix_Music * music = nullptr;
};

#endif // __MODULESCENEINTRO_H__