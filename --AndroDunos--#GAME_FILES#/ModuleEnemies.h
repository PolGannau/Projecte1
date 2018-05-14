#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Enemy_WhiteShip.h"
#include "Enemy_ShipUpDown.h"
#include "Enemy_StraightOnShip.h"
#include "Enemy_ShipGreen.h"
#include "Enemy_GreenTurret.h"
#include "Enemy_ShipTurret.h"
#include "Enemy_WhiteTurret.h"
#include "Enemy_VerticalStructure.h"
#include "Enemy_TripleTurret.h"

#define MAX_ENEMIES 100


class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
	bool z;
	int anim_;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);
	bool tocuh = false, dead = false, verticalstructuredead = false, sub_Boss_Dead = true;
	bool touch2 = false, dead2=false;
	bool AddEnemy(ENEMY_TYPES type, int x, int y, bool z= false);

private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
	int lives[MAX_ENEMIES];
};

#endif // __ModuleEnemies_H__