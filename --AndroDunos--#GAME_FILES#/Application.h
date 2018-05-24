#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 19

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
class ModuleStageclear;
class ModuleCollision;
class ModuleEnemies;
class ModuleFonts;
class Module;
class ModulePowerUps;
class ModuleGameover;
class ModuleStage2;
class ModuleViscoGames;


class Application
{
public:

	Module * modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleAudio* audio;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneSpace* scene_space;
	ModuleSceneIntro* scene_intro;
	ModuleViscoGames* viscogames;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModuleFonts* fonts;
	ModuleStageclear* stageclear;
	ModulePowerUps* powerups;
	ModuleGameover* gameover;
	ModuleStage2* stage2;


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