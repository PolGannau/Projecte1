#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
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

	background1 = App->textures->Load("assets/level-1/background&floor/Background_Tiles_part1.png");
	floor = App->textures->Load("assets/level-1/background&floor/Floor_all.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->powerups->Enable();

	// Colliders ---
	App->collision->AddCollider({ 0, 204, 3930, 20 }, COLLIDER_WALL);

	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 350, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 381, 100);

	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 450, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, 481, 100);

	App->powerups->AddPowerUp(POWERUPS_TYPES::SHIPPOWERUP, 550, 50);
	App->powerups->AddPowerUp(POWERUPS_TYPES::SHIPPOWERUP, 681, 150);

	mus = App->audio->LoadMusic("assets/level-1/04_Stage_1 -The Moon-Loop.ogg");

	App->audio->PlayMusic(mus);

	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background1);
	App->textures->Unload(floor);
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
	// Move camera forward -----------------------------
	App->render->camera.x += 1 * SCREEN_SIZE;

	// Draw everything --------------------------------------
	App->render->Blit(background1, 0, 87, NULL);
	App->render->Blit(floor, 0, -115, NULL);
	App->render->Blit(hud, 0, 240, NULL, 0.0f, false);

	return UPDATE_CONTINUE;
}