#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneSpace.h"

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

	// Colliders ---
	App->collision->AddCollider({ 0, 208, 3930, 16 }, COLLIDER_WALL);


	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background1);
	App->textures->Unload(floor);
	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 1;

	App->player->position.x += 1;
	App->render->camera.x -= 3;


	// Draw everything --------------------------------------
	App->render->Blit(background1, 0, 87, NULL);
	App->render->Blit(floor, 0, -110, NULL);

	return UPDATE_CONTINUE;
}