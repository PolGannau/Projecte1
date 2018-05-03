#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleUi.h"
#include "ModuleEnemies.h"
#include "ModuleSceneSpace.h"
#include "ModulePowerUps.h"
#include "ModuleFadeToBlack.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");

	App->render->view.x = App->render->view.y = 0;

	stop_p = false;
	background1 = App->textures->Load("assets/level-1/background&floor/UpperBackground.png");
	map_p[0] = App->textures->Load("assets/Stage 2/map-part1stage2.png"); //ES EL INICI DEL FLOOR DEL STAGE 2
	//map_p[0] = App->textures->Load("assets/level-1/background&floor/map-part1.png"); //ES EL INICI DEL FLOOR DEL STAGE 1
	map_p[1] = App->textures->Load("assets/Stage 2/map-part2stage2.png");
	//map_p[1] = App->textures->Load("assets/level-1/background&floor/map-part2.png");
	map_p[2] = App->textures->Load("assets/Stage 2/map-part3stage2.png");
	//map_p[2] = App->textures->Load("assets/level-1/background&floor/map-part3.png");
	map_p[3] = App->textures->Load("assets/Stage 2/map-part4stage2.png");
	//map_p[3] = App->textures->Load("assets/level-1/background&floor/map-part4.png");
	//map_p[4] = App->textures->Load("assets/level-1/background&floor/map-part5.png");
	//map_p[5] = App->textures->Load("assets/level-1/background&floor/map-part6.png");
	underground = App->textures->Load("assets/level-1/background&floor/UnderBackground.png");
	underground_e = App->textures->Load("assets/level-1/background&floor/UnderBackground_end.png");
	underground_s = App->textures->Load("assets/level-1/background&floor/Underbackground_start.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->powerups->Enable();

	// Colliders ---
	App->collision->AddCollider({ 0,195,1098,39 }, COLLIDER_WALL); //Initial Floor
	App->collision->AddCollider({ 1491,195,1480,39 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1098,204,393,20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 905,184,103,11 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1560,189,103,6 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2362,189,103,6 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2601,184,103,11 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2971,187,39,214 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2960,401,114,47 }, COLLIDER_WALL);

	App->collision->AddCollider({ 3204,187 ,45,108 }, COLLIDER_WALL); //Top
	App->collision->AddCollider({ 3218,295 ,15,10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3249,215 ,90,50 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3339,215 ,90,35 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3429,190 ,635,45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4064,190 ,17,22 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4064,160 ,62,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4126,130 ,30,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4156, 90 ,30,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4186, 70 ,600,40 }, COLLIDER_WALL);

	App->collision->AddCollider({ 6286, 0, 30, 30 }, COLLIDER_WALL); //Top 2
	App->collision->AddCollider({ 6316, 30, 30, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6346, 60, 50, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6396, 90, 40, 50 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6426, 140, 40, 40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6466, 170, 40, 35 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6506, 205, 650, 35 }, COLLIDER_WALL);
	App->collision->AddCollider({ 7156, 185, 45, 105 }, COLLIDER_WALL);
	App->collision->AddCollider({ 7036, 240, 120, 20 }, COLLIDER_WALL);

	App->collision->AddCollider({ 3074,430,1006,18 }, COLLIDER_WALL); //Downfall
	App->collision->AddCollider({ 3893,418,64,12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4080,421,29,29 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4109,389,30,58 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4139,351,81,89 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4183,325,20,26 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4203,311,402,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4605,331,15,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4605,361,65,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4670,387,25,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4695,416,31,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4726,430,490,25 }, COLLIDER_WALL);

	App->collision->AddCollider({ 5216,415,32,25 }, COLLIDER_WALL); //Rise
	App->collision->AddCollider({ 5248,385,27,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5275,357,50,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5325,307,35,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5360,277,30,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5390,247,53,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5443,209,770,55 }, COLLIDER_WALL);

	App->collision->AddCollider({ 6213,247,53,55 }, COLLIDER_WALL);//Downfall
	App->collision->AddCollider({ 6266,277,30,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6296,307,35,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6331,357,50,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6381,385,27,55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6408,415,32,25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6440,435,910,25 }, COLLIDER_WALL);


	App->collision->AddCollider({ 7350,415,90,25 }, COLLIDER_WALL);//Rise
	App->collision->AddCollider({ 7370,400,90,15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 7400,200,90,200 }, COLLIDER_WALL);
	App->collision->AddCollider({ 7412,180,20,20 }, COLLIDER_WALL);

	App->collision->AddCollider({ 7490,200,1700,40 }, COLLIDER_WALL); // Final Floor
	App->collision->AddCollider({ 7780,190,105,10 }, COLLIDER_WALL); // End Crater 1
	App->collision->AddCollider({ 8410,190,105,10 }, COLLIDER_WALL); // End Crater 2
	App->collision->AddCollider({ 8650,190,105,10 }, COLLIDER_WALL); // End Crater 3


	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 350, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 368, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 386, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 404, 60);

	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 460, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 478, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 496, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 514, 140);

	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 560, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 578, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 596, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 614, 60);

	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 660, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 678, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 696, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 714, 140);

	App->powerups->AddPowerUp(POWERUPS_TYPES::SHIPPOWERUP, 775, 85);
	
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 900, 54);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 915, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 900, 86);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 980, 96);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 995, 112);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 980, 128);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1060, 54);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1075, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1060, 86);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1140, 86);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1155, 86);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1170, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1185, 54);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1170, 102);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1185, 118);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1250, 86);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1265, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1280, 54);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1250, 86);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1265, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1280, 54);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1330, 96);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1345, 112);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1360, 128);

	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 1450, 40);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 1470, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 1460, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 1480, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 1490, 160);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1600, 96);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1620, 112);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1640, 128);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 2000, 96);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 2020, 112);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 2040, 128);

	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 2200, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 2220, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 2240, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 2260, 140);

	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 2500, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 2520, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 2540, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 2560, 140);



	mus = App->audio->LoadMusic("assets/level-1/04_Stage_1 -The Moon-Loop.ogg");

	App->audio->PlayMusic(mus);

	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background1);
	App->textures->Unload(underground);
	App->textures->Unload(underground_e);
	App->textures->Unload(underground_s);
	App->textures->Unload(map_p[0]);
	App->textures->Unload(map_p[1]);
	App->textures->Unload(map_p[2]);
	App->textures->Unload(map_p[3]);
	//App->textures->Unload(map_p[4]);
	//App->textures->Unload(map_p[5]);
	App->audio->UnloadMusic(mus);
	App->enemies->Disable();
	App->powerups->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->player2->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{

	if (stop_p == false && App->render->camera.x <= 11257 * SCREEN_SIZE)
	{
		App->render->camera.x += 1 * SCREEN_SIZE; //speed in x axes
		App->player->position.x += 1;
		App->render->view.x += 1;
		if (App->player2->IsEnabled() == true)
		{
			App->player2->position.x += 1;
		}
	}

	if ((App->render->camera.x >= 3680 * SCREEN_SIZE && App->render->camera.x <= 3682 * SCREEN_SIZE && App->render->camera.y == 0)
		|| (App->render->camera.x >= 8945 * SCREEN_SIZE && App->render->camera.y >= 279))
	{
		stop_p = true; // stop scrolling in x axes
	}
	else if ((App->render->camera.x >= 3680 * SCREEN_SIZE && App->render->camera.x <= 3682 * SCREEN_SIZE && App->render->camera.y >= 279 * SCREEN_SIZE)
		|| (App->render->camera.x >= 8945 * SCREEN_SIZE && App->render->camera.x <= 8947 * SCREEN_SIZE && App->render->camera.y == 0)) stop_p = false; // enable scroll in x axes

	if ((App->render->camera.x >= 3680 * SCREEN_SIZE && App->render->camera.x <= 3682 * SCREEN_SIZE  && App->render->camera.y <= 279 * SCREEN_SIZE)
		|| (App->render->camera.x >= 5658 * SCREEN_SIZE && App->render->camera.x <= 5814 * SCREEN_SIZE)
		|| (App->render->camera.x >= 7580 * SCREEN_SIZE && App->render->camera.x <= 7857 * SCREEN_SIZE)) 
	{
		App->render->camera.y += 1 * SCREEN_SIZE; // speed in y axes
		App->player->position.y += 1;
		App->render->view.y += 1;
		if (App->player2->IsEnabled() == true)
		{
			App->player2->position.y += 1;
		}
	}
	else if ((App->render->camera.x >= 5022 * SCREEN_SIZE && App->render->camera.x <= 5178 * SCREEN_SIZE)
		|| (App->render->camera.x >= 6370 * SCREEN_SIZE && App->render->camera.x <= 6647 * SCREEN_SIZE)
		|| (App->render->camera.x >= 8945 * SCREEN_SIZE && stop_p == true))
	{
		App->render->camera.y -= 1 * SCREEN_SIZE; // speed in y axes
		App->player->position.y -= 1;
		App->render->view.y -= 1;
		if (App->player2->IsEnabled() == true)
		{
			App->player2->position.y -= 1;
		}
	}

	if (App->player->position.x >= 11200 || App->player2->position.x >= 11200)
	{
		App->fade->FadeToBlack(this, (Module*)App->stageclear, 1.0f);
	}



	// Draw everything --------------------------------------
	for (int i = 0; i < 29; ++i) if (!App->render->Blit(background1, TILE_WIDTH * i, 120, NULL, 0.6f)) return update_status::UPDATE_ERROR;
	if (App->render->camera.x > 3681 * SCREEN_SIZE && App->render->camera.x <= 8943 * SCREEN_SIZE) {
		if (!App->render->Blit(underground_s, 1435, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground, 2015, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground, 2014 + UT_W, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground, 2013 + UT_W * 2, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground, 2012 + UT_W * 3, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground_e, 2011 + UT_W * 4 - 64 * 3, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;//64 is the mesure of 1/6th of the under_tile_width here it's used to fit the end of the underground background into the previous tiles
	}
	if (!App->render->Blit(map_p[0], 0, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(map_p[1], 1639, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(map_p[2], 3279, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(map_p[3], 4935, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	//if (!App->render->Blit(map_p[4], 6591, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	//if (!App->render->Blit(map_p[5], 8230, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;

	return UPDATE_CONTINUE;
}