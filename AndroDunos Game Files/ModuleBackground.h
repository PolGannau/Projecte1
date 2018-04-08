#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();

	bool Start();
	update_status Update();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background1;
	SDL_Rect background2;
	SDL_Rect background3;
	SDL_Rect background4;
	SDL_Rect background5;
	SDL_Rect background6;
	SDL_Rect background7;
	SDL_Rect background8;
	SDL_Rect background9;
	SDL_Rect background10;
	SDL_Rect background11;
	SDL_Rect background12;
	SDL_Rect background13;
	SDL_Rect background14;
	SDL_Rect background15;
	SDL_Rect background16;
};

#endif