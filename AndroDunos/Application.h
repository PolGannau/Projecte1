#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 1

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleAudio;
class ModuleParticles;
class ModuleSceneSpace;
class ModuleSceneIntro;
class ModulePlayer;
class ModulePlayer2;
class ModuleFadeToBlack;
class ModuleCollision;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleAudio* audio;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneSpace* scene_space;
	ModuleSceneIntro* scene_intro;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__