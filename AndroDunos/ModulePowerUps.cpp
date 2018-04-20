#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleSceneIntro.h"
#include "ModuleSceneSpace.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModulePowerUps.h"



// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePowerUps::ModulePowerUps()
{
	// idle animation (just the ship)
	

	// move upwards


	// Move down

}

ModulePowerUps::~ModulePowerUps()
{}

// Load assets
bool ModulePowerUps::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("assets/ship/ships.png");

	position.x = 30;
	position.y = 60;

	// TODO 2: Add a collider to the player


	
	return true;
}

// Unload assets
bool ModulePowerUps::CleanUp()
{
	LOG("Unloading powerupship");
	
	return true;
}

// Update: draw background
update_status ModulePowerUps::Update()
{
	
	return UPDATE_CONTINUE;
}

// TODO 4: Detect collision with a wall. If so, go back to intro screen.

void ModulePowerUps::OnCollision(Collider* c1, Collider* c2)
{
	
}