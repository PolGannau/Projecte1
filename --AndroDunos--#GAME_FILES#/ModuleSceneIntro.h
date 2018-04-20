#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro();
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * intro = nullptr;
	SDL_Rect neogeo;

	uint fx = 0;

	Mix_Music * music = nullptr;
};

#endif // __MODULESCENEINTRO_H__