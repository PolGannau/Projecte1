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
#include "Enemy_Elevator.h"
#include "Enemy_Elevator2.h"
#include "Enemy_MovementLaser.h"
#include "Enemy_Ship.h"
#include "Enemy_HandShip.h"
#include "Enemy_Multicolor.h"
#include "Enemy_WhiteYellow.h"
#include "Enemy_MiniBoss.h"
#include "Enemy_Small.h"
#include "Enemy_SmallGreen.h"
#include "Enemy_Laser.h"
#include "Enemy_RocketTurret.h"
#include "Enemy_TurretRed.h"
#include "Enemy_ElevatorCanon.h"
#include "Enemy_Boss.h"
#include "Enemy_Boss2.h"

#define MAX_ENEMIES 100


class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
	bool z;
	int num;
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
	bool tocuh = false, dead = false, verticalstructuredead = false, sub_Boss_Dead = false;
	bool touch2 = false, dead2=false;
	bool AddEnemy(ENEMY_TYPES type, int x, int y, bool z = false, int num = 1);
	int timeelevator = 0;
	bool subBoss;
private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
	int lives[MAX_ENEMIES];
};

#endif // __ModuleEnemies_H__