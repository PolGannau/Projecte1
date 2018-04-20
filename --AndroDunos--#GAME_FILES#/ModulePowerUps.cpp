#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePowerUps.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "PowerUp.h"
#include "ShipPowerUp.h"
#include "PowerUpRed.h"


#define SPAWN_MARGIN 50

ModulePowerUps::ModulePowerUps()
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
		powerups[i] = nullptr;
}

// Destructor
ModulePowerUps::~ModulePowerUps()
{
}

bool ModulePowerUps::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("assets/powerups.png");

	return true;
}

update_status ModulePowerUps::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (queue[i].type != POWERUPS_TYPES::NON_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnPowerUp(queue[i]);
				queue[i].type = POWERUPS_TYPES::NON_TYPE;
				LOG("Spawning powerup at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModulePowerUps::Update()
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
		if (powerups[i] != nullptr) powerups[i]->Move();

	for (uint i = 0; i < MAX_POWERUPS; ++i)
		if (powerups[i] != nullptr) powerups[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModulePowerUps::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerups[i] != nullptr)
		{
			if (powerups[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning powerup at %d", powerups[i]->position.x * SCREEN_SIZE);
				delete powerups[i];
				powerups[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePowerUps::CleanUp()
{
	LOG("Freeing all powerups");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerups[i] != nullptr)
		{
			delete powerups[i];
			powerups[i] = nullptr;
		}
	}

	return true;
}

bool ModulePowerUps::AddPowerUp(POWERUPS_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (queue[i].type == POWERUPS_TYPES::NON_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModulePowerUps::SpawnPowerUp(const PowerUpInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; powerups[i] != nullptr && i < MAX_POWERUPS; ++i);

	if (i != MAX_POWERUPS)
	{
		switch (info.type)
		{
		case POWERUPS_TYPES::SHIPPOWERUP:
			powerups[i] = new ShipPowerUp(info.x, info.y);
			break;
		case POWERUPS_TYPES::POWERUPRED:
			powerups[i] = new PowerUpRed(info.x, info.y);
			break;

		}
	}
}

void ModulePowerUps::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerups[i] != nullptr && powerups[i]->GetCollider() == c1)
		{
			powerups[i]->OnCollision(c2);
			delete powerups[i];
			powerups[i] = nullptr;
			break;
		}
	}
}