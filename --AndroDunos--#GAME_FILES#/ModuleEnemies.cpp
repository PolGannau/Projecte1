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
#include "Enemy_TripleTurret.h"
#include "Enemy_Elevator.h"
#include "Enemy_Elevator2.h"
#include "Enemy_MovementLaser.h"
#include "Enemy_Ship.h"
#include "Enemy_HandShip.h"
#include "Enemy_Multicolor.h"
#include "Enemy_Small.h"
#include "ModulePlayer.h"
#include "Enemy_WhiteYellow.h"
#include "Enemy_MiniBoss.h"



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

	sub_Boss_Dead = false;

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
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN - 80 && !ENEMY_TYPES::ELEVATOR && !ENEMY_TYPES::ELEVATOR2)
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

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y,bool z, int num)
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
			queue[i].num = num;
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
			enemies[i] = new Enemy_StraightOnShip(info.x, info.y, info.num);
			break;
		case ENEMY_TYPES::SHIPGREEN:
			enemies[i] = new Enemy_ShipGreen(info.x, info.y, info.z);
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
		case ENEMY_TYPES::TRIPLETURRET:
			enemies[i] = new Enemy_TripleTurret(info.x, info.y);
			break;
		case ENEMY_TYPES::ELEVATOR:
			enemies[i] = new Enemy_Elevator(info.x, info.y);
			break;
		case ENEMY_TYPES::ELEVATOR2:
			enemies[i] = new Enemy_Elevator2(info.x, info.y);
			break;
		case ENEMY_TYPES::MOVEMENTLASER:
			enemies[i] = new Enemy_MovementLaser(info.x, info.y);
			break;
		case ENEMY_TYPES::SHIP:
			enemies[i] = new Enemy_Ship(info.x, info.y);
			break;
		case ENEMY_TYPES::HANDSHIP:
			enemies[i] = new Enemy_HandShip(info.x, info.y);
			break;
		case ENEMY_TYPES::MULTICOLOR:
			enemies[i] = new Enemy_MultiColor(info.x, info.y);
			break;
		case ENEMY_TYPES::SMALL:
			enemies[i] = new Enemy_Small(info.x, info.y);
			break;
		case ENEMY_TYPES::WHITEYELLOW:
			enemies[i] = new Enemy_WhiteYellow(info.x, info.y, info.num);
			break;
		case ENEMY_TYPES::MINIBOSS:
			enemies[i] = new Enemy_MiniBoss(info.x, info.y);
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
				}
				else if (lives[i]>0) {
					enemies[i]->hit = true;
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
				}
				else if (lives[i]>0) {
					enemies[i]->hit = true;
				}
				break;
			case TRIPLETURRET:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case ELEVATOR:
				enemies[i]->OnCollision(c2);
				break;
			case ELEVATOR2:
				enemies[i]->OnCollision(c2);
				break;
			case MOVEMENTLASER:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case SHIP:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case HANDSHIP:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case MULTICOLOR:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case SMALL:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case WHITEYELLOW:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			case MINIBOSS:
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			default:
				break;
			}
		}
	}
}