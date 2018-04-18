#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneSpace.h"
#include "ModuleEnemies.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{
}

ModuleSceneSpace::~ModuleSceneSpace()
{
}

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

	// Colliders ---
	App->collision->AddCollider({ 0, 204, 3930, 20 }, COLLIDER_WALL);

	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 350, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITESHIP, 381, 100);

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
	App->enemies->Disable();
	App->player->Disable();
	App->player2->Disable();
	App->collision->Disable();
	App->particles->Disable();
	
	App->audio->UnloadMusic(mus);

	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 1;

	App->player->position.x += 1;
	App->player2->position.x += 1;
	App->render->camera.x -= 3;


	// Draw everything --------------------------------------
	App->render->Blit(background1, 0, 87, NULL);
	App->render->Blit(floor, 0, -115, NULL);

	return UPDATE_CONTINUE;
}