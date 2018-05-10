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
#include "ModuleStage2.h"
#include "ModulePowerUps.h"
#include "ModuleFadeToBlack.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleStage2::ModuleStage2()
{}

ModuleStage2::~ModuleStage2()
{}

// Load assets
bool ModuleStage2::Start()
{
	LOG("Loading space scene");

	App->render->view.x = App->render->view.y = 0;

	stop_p = false;
	background1 = App->textures->Load("assets/level-1/background&floor/UpperBackground.png");
	map_p[0] = App->textures->Load("assets/Stage-2/map-part1stage2.png"); //ES EL INICI DEL FLOOR DEL STAGE 2
	map_p[1] = App->textures->Load("assets/Stage-2/map-part2stage2.png");
	map_p[2] = App->textures->Load("assets/Stage-2/map-part3stage2.png");
	map_p[3] = App->textures->Load("assets/Stage-2/map-part4stage2.png");

	underground = App->textures->Load("assets/level-1/background&floor/UnderBackground.png");
	underground_e = App->textures->Load("assets/level-1/background&floor/UnderBackground_end.png");
	underground_s = App->textures->Load("assets/level-1/background&floor/Underbackground_start.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->powerups->Enable();

	// Colliders --- App->collision->AddCollider({ 0,0,0,0 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0,205,1265,25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 334,168,124,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 334,145,92,45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 374,130,44,45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 402,115,16,45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 503,185,39,45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 458,192,45,45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 580,195,426,45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 703,182,304,45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 933,0,438,5 }, COLLIDER_WALL);
	App->collision->AddCollider({ 951,0,402,20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1031,20,202,16 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1046,36,123,12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1008,198,257,45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1265,210,98,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1325,201,28,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1158,171,90,45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1181,159,56,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1769,218,1772,6 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1786,204,83,20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1869,210,152,15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2107,191,122,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2228,184,159,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2362,0,372,4 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2380,4,24,14 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2404,4,288,35 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2692,4,30,25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2388,202,1153,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2740,184,208,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3462,184,16,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3486,194,55,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3258,0,283,5 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3269,5,259,25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3300,30,16,10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3323,30,121,17 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3528,5,13,21 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3502,194,40,304 }, COLLIDER_WALL); //down
	App->collision->AddCollider({ 3502,540,40,150 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3502,750,40,150 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3502,944,40,336 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3502,1320,40,250 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3768,0,40,498 }, COLLIDER_WALL); //down
	App->collision->AddCollider({ 3768,540,40,150 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3768,750,40,152 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3768,944,40,338 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3768,1322,40,248 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2909,1570,40,194 }, COLLIDER_WALL); //left left
	App->collision->AddCollider({ 2909,1570,630,30 }, COLLIDER_WALL); //left up
	App->collision->AddCollider({ 2909,1764,630,30 }, COLLIDER_WALL); //left down
	App->collision->AddCollider({ 3768,1570,114,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3882,1570,1253,17 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4092,1570,82,66 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4364,1570,31,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4395,1570,146,66 }, COLLIDER_WALL);
	
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 350, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 368, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 386, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 404, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 404, 215);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 700, 215);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 550, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 568, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 586, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 504, 120);


	//mus = App->audio->LoadMusic("assets/stage2/07_Stage_2-Mechanized-Unit-Intro.ogg", 1);
	mus = App->audio->LoadMusic("assets/Stage-2/07_Stage_2-Mechanized-Unit-Loop.ogg");

	App->audio->PlayMusic(mus);
	
	return true;
}

// UnLoad assets
bool ModuleStage2::CleanUp()
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
update_status ModuleStage2::Update()
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

	if ((App->render->camera.x >= 3637 * SCREEN_SIZE && App->render->camera.x <= 3639 * SCREEN_SIZE && App->render->camera.y == 0)
		|| (App->render->camera.x >= 8945 * SCREEN_SIZE && App->render->camera.y >= 279))
	{
		stop_p = true; // stop scrolling in x axes
	}
	else if ((App->render->camera.x >= 3637 * SCREEN_SIZE && App->render->camera.x <= 3639 * SCREEN_SIZE && App->render->camera.y >= 279 * SCREEN_SIZE)
		|| (App->render->camera.x >= 8945 * SCREEN_SIZE && App->render->camera.x <= 8947 * SCREEN_SIZE && App->render->camera.y == 0)) stop_p = false; // enable scroll in x axes

	if ((App->render->camera.x >= 3437 * SCREEN_SIZE && App->render->camera.x <= 3439 * SCREEN_SIZE  && App->render->camera.y <= 279 * SCREEN_SIZE)
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
	} //movement 

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
	if (!App->render->Blit(map_p[0], 0, -607, nullptr, 1.0f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(map_p[1], 1672, -608, nullptr,1.0f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(map_p[2], 3279, -607, nullptr, 1.0f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(map_p[3], 4886, -606, nullptr, 1.0f)) return update_status::UPDATE_ERROR;

	return UPDATE_CONTINUE;
}