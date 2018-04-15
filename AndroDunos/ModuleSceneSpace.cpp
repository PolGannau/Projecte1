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

	graphics = App->textures->Load("assets/background/Background_Tiles_part1.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();

	// Colliders ---
	App->collision->AddCollider({ 0, 224, 3930, 16 }, COLLIDER_WALL);


	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(graphics);
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
	App->render->Blit(graphics, 0, 0, NULL);

	return UPDATE_CONTINUE;
}