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
	App->collision->AddCollider({ 3768,750,40,130 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3768,944,40,338 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3768,1322,40,248 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2909,1570,40,194 }, COLLIDER_WALL); //left left
	App->collision->AddCollider({ 2909,1570,630,30 }, COLLIDER_WALL); //left up
	App->collision->AddCollider({ 2909,1764,630,30 }, COLLIDER_WALL); //left down
	App->collision->AddCollider({ 3768,1570,114,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3882,1570,2295,17 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4092,1570,82,66 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4364,1570,31,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4395,1570,146,66 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5432,1587,128,15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5706,1587,158,15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3772,1764,209,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3981,1732,111,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4091,1780,146,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4240,1716,109,60 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4349,1749,195,60 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4544,1780,403,15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4947,1716,79,70 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5026,1700,111,90 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5303,1765,128,30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5431,1780,247,15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5678,1733,191,60 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5869,1781,303,15 }, COLLIDER_WALL);

	
	/*App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 350, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 368, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 386, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 404, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 404, 215);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 700, 215);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 550, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 568, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 586, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 504, 120);*/

	// well position
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 270, 140, true);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 295, 163, true);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 320, 140, true);

	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 360, 39, true);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 375, 62, true);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPGREEN, 392, 39, true);

	App->powerups->AddPowerUp(POWERUPS_TYPES::SHIPPOWERUP, 400, 100);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 540, 120, false, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 550, 120, false, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 560, 120, false, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 540, 80, false, 3);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 550, 80, false, 3);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 560, 80, false, 3);
	
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEYELLOW, 1400, 220, false, 1);  
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEYELLOW, 1420, 240, false, 3);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEYELLOW, 1440, 260, false, 5);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEYELLOW, 1460, 280, false, 7);

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEYELLOW, 1400, -10, false, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEYELLOW, 1420, -30, false, 4);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEYELLOW, 1440, -50, false, 6);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEYELLOW, 1460, -70, false, 8);

	
	App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSTRUCTURE, 2277, 245, true);
	App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSTRUCTURE, 2453, -145, false);
	App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSTRUCTURE, 2614, -145, false); 
	App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSTRUCTURE, 2757, 245, true);

	App->enemies->AddEnemy(ENEMY_TYPES::ELEVATOR, 3544, -400);
	App->enemies->AddEnemy(ENEMY_TYPES::ELEVATOR2, 3544, 591);

	App->enemies->AddEnemy(ENEMY_TYPES::GREENTURRET, 3504, 501, false);
	App->enemies->AddEnemy(ENEMY_TYPES::GREENTURRET, 3761, 501, true);
	App->enemies->AddEnemy(ENEMY_TYPES::GREENTURRET, 3504, 695, false);
	App->enemies->AddEnemy(ENEMY_TYPES::GREENTURRET, 3761, 695, true);
	App->enemies->AddEnemy(ENEMY_TYPES::GREENTURRET, 3504, 889, false);
	App->enemies->AddEnemy(ENEMY_TYPES::GREENTURRET, 3761, 889, true);
	App->enemies->AddEnemy(ENEMY_TYPES::GREENTURRET, 3504, 1283, false);
	App->enemies->AddEnemy(ENEMY_TYPES::GREENTURRET, 3761, 1283, true);


	


	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 1220, 40, false);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 1125, 47, false);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 1150, 47, false);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 1280, 22, false);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 1332, 20, false);

	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 1205, 130, true);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 1300, 197, true);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITETURRET, 1337, 187, true);

	App->enemies->AddEnemy(ENEMY_TYPES::SHIP, 150, -100);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIP, 155, -100);


	App->enemies->AddEnemy(ENEMY_TYPES::MULTICOLOR, 700, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::MULTICOLOR, 730, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::MULTICOLOR, 760, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::MULTICOLOR, 790, 30);


	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1600, 50, false, 4);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1610, 35, false, 4);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1610, 65, false, 4);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1640, 125, false, 5);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1650, 110, false, 5);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1650, 140, false, 5);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1700, 50, false, 4);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1710, 35, false, 4);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1710, 65, false, 4);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1600, 50, false, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1610, 35, false, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1610, 65, false, 2);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1640, 125, false, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1650, 110, false, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1650, 140, false, 2);

	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1700, 50, false, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1710, 35, false, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::STRAIGHTONSHIP, 1710, 65, false, 2);


	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1800, 100, false, 3);
	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1815, 100, false, 3);
	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1830, 100, false, 3);
	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1845, 100, false, 3);

	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1855, 60, false, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1870, 60, false, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1885, 60, false, 1);
	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1900, 60, false, 1);

	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 536, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 536, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 536, 100);

	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 1366, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 1366, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 1366, 100);

	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 1750, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 1750, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 1750, 100);

	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 2989, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 2989, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::HANDSHIP, 2989, 100);




	//App->enemies->AddEnemy(ENEMY_TYPES::SHIP, )

	//App->enemies->AddEnemy(ENEMY_TYPES::SHIP)
	
	/*App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1100, 250, false, 2);  //Nau verda
	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1101, 260, false, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1102, 270, false, 2);
	App->enemies->AddEnemy(ENEMY_TYPES::SMALL, 1103, 280, false, 2);*/



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

	if (App->render->camera.x >= 3502 * SCREEN_SIZE && App->render->camera.x <= 3806 * SCREEN_SIZE && App->render->camera.y >= 0 * SCREEN_SIZE && App->render->camera.y < 1571 * SCREEN_SIZE)
	{
		stop_p = true;
	}
	else
	{
		stop_p = false;

	}
	if (App->render->camera.y >= 1571 * SCREEN_SIZE && App->enemies->sub_Boss_Dead == false)
	{
		left_move = true;
	}
	else left_move = false;

	if (stop_p == false && left_move == false)
	{
		App->render->camera.x += 1 * SCREEN_SIZE; //speed in x axes
		App->player->position.x += 1;
		App->render->view.x += 1;
		if (App->player2->IsEnabled() == true)
		{
			App->player2->position.x += 1;
		}
	}

	if (left_move == true && App->enemies->subBoss)
	{
		App->render->camera.x -= 1 * SCREEN_SIZE; //speed in x axes
		App->player->position.x -= 1;
		App->render->view.x -= 1;
		if (App->player2->IsEnabled() == true)
		{
			App->player2->position.x -= 1;
		}
	if (App->render->camera.x <= 2907 * SCREEN_SIZE)
		{
			App->enemies->sub_Boss_Dead = true;
		
		}
	}

	if (stop_p == true && App->render->camera.x >= 3502 * SCREEN_SIZE && App->render->camera.x <= 3806 * SCREEN_SIZE && App->render->camera.y >= 0 * SCREEN_SIZE && App->render->camera.y < 1571 * SCREEN_SIZE && App->enemies->timeelevator>=560)
	{
		App->render->camera.y += 1 * SCREEN_SIZE; // speed in y axes
		App->player->position.y += 1;
		App->render->view.y += 1;
		if (App->player2->IsEnabled() == true)
		{
			App->player2->position.y += 1;
		}
	}

	//movement 

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