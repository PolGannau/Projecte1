#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "Enemy_ShipUpDown.h"
#include "Enemy_WhiteShip.h"
#include "Enemy_StraightOnShip.h"
#include "Enemy_ShipGreen.h"
#include "Enemy_GreenTurret.h"
#include "Enemy_ShipTurret.h"
#include "Enemy_WhiteTurret.h"
#include "Enemy_VerticalStructure.h"
#include "ModulePlayer.h"


#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("assets/enemies/enemies.png");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y,bool z)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			queue[i].z = z;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::WHITESHIP:
			enemies[i] = new Enemy_WhiteShip(info.x, info.y);
			break;
		case ENEMY_TYPES::SHIPUPDOWN:
			enemies[i] = new Enemy_ShipUpDown(info.x, info.y);
			break;
		case ENEMY_TYPES::STRAIGHTONSHIP:
			enemies[i] = new Enemy_StraightOnShip(info.x, info.y);
			break;
		case ENEMY_TYPES::SHIPGREEN:
			enemies[i] = new Enemy_ShipGreen(info.x, info.y);
			break;
		case ENEMY_TYPES::GREENTURRET:
			enemies[i] = new Enemy_GreenTurret(info.x, info.y,info.z);
			lives[i] = 5;
			break;
		case ENEMY_TYPES::SHIPTURRET:
			enemies[i] = new Enemy_ShipTurret(info.x, info.y);
			break;
		case ENEMY_TYPES::WHITETURRET:
			enemies[i] = new Enemy_WhiteTurret(info.x, info.y);
			break;
		case ENEMY_TYPES::VERTICALSTRUCTURE:
			enemies[i] = new Enemy_VerticalStructure(info.x, info.y, info.z);
			lives[i] = 15;
			break;
		}
		

	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			switch (enemies[i]->type)
			{
			case NO_TYPE:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case GREENTURRET:
				lives[i]--;
				if (lives[i] == 0) {
					enemies[i]->OnCollision(c2);
					delete enemies[i];
					enemies[i] = nullptr;
					App->enemies->dead = true;
				}
				else if (lives[i]>0) {
					App->enemies->tocuh = true;
				}
				break;
			case WHITESHIP:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case SHIPUPDOWN:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case STRAIGHTONSHIP:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case SHIPGREEN:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case SHIPTURRET:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case WHITETURRET:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case VERTICALSTRUCTURE:
				lives[i]--;
				if (lives[i] == 0) {
					enemies[i]->OnCollision(c2);
					delete enemies[i];
					enemies[i] = nullptr;
					App->enemies->dead2 = true;
				}
				else if (lives[i]>0) {
					App->enemies->touch2 = true;
				}
				break;
			default:
				break;
			}
		}
	}
}