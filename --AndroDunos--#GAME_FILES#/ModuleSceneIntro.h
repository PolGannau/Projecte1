#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro();
	~ModuleSceneIntro();
	Animation* anim= nullptr;
	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * intro = nullptr;
	SDL_Rect neogeo;
	Animation Neogeo;
	Animation SNK;
	uint fx = 0;
	int time = 0;
	int time2 = 0;
	bool change = false;
	Mix_Music * music = nullptr;
};

#endif // __MODULESCENEINTRO_H__