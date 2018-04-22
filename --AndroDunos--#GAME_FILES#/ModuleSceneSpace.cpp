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
#include "ModuleEnemies.h"
#include "ModuleSceneSpace.h"
#include "ModulePowerUps.h"

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
	map_p[0] = App->textures->Load("assets/level-1/background&floor/map-part1.png");
	map_p[1] = App->textures->Load("assets/level-1/background&floor/map-part2.png");
	map_p[2] = App->textures->Load("assets/level-1/background&floor/map-part3.png");
	map_p[3] = App->textures->Load("assets/level-1/background&floor/map-part4.png");
	map_p[4] = App->textures->Load("assets/level-1/background&floor/map-part5.png");
	map_p[5] = App->textures->Load("assets/level-1/background&floor/map-part6.png");
	underground = App->textures->Load("assets/level-1/background&floor/UnderBackground.png");
	underground_e = App->textures->Load("assets/level-1/background&floor/UnderBackground_end.png");
	underground_s = App->textures->Load("assets/level-1/background&floor/Underbackground_start.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->powerups->Enable();

	// Colliders ---
	App->collision->AddCollider({ 0, 204, 3670, 20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3670,204,40,300 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3970,204,40,150 }, COLLIDER_WALL);

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
	App->textures->Unload(map_p[4]);
	App->textures->Unload(map_p[5]);
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
	if (!App->render->Blit(map_p[4], 6591, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(map_p[5], 8230, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;

	return UPDATE_CONTINUE;
}