#include "Application.h"
#include "Enemy_ShipTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_ShipTurret::Enemy_ShipTurret(int x, int y, bool z) : Enemy(x, y)
{
	type = SHIPTURRET;

	fly.PushBack({ 1,54,32,24 });
	fly.PushBack({ 48, 54, 31, 24 });
	fly.PushBack({ 92, 54, 31, 24 });
	fly.PushBack({ 0, 80, 31, 24 });
	fly.PushBack({ 47,80,31,24 });
	fly.PushBack({ 91,80,31,24 });
	fly.PushBack({ 0,106,32,24 });
	fly.PushBack({ 0,106,32,24 });
	fly.PushBack({ 0,106,32,24 });
	fly.PushBack({ 91,80,31,24 });
	fly.PushBack({ 47,80,31,24 });
	fly.PushBack({ 0, 80, 31, 24 });
	fly.PushBack({ 92, 54, 31, 24 });
	fly.PushBack({ 48, 54, 31, 24 });
	fly.PushBack({ 1,54,32,24 });
	fly.speed = 0.1f;
	fly.loop = false;
	animation = &fly;
	this->z = z;
	collider = App->collision->AddCollider({ 0, 0, 32, 24}, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_ShipTurret::Move()
{
	if (z) {
		++time;
		if (time == 60) {
			App->enemies->AddEnemy(ENEMY_TYPES::SMALLGREEN, position.x + 8, position.y,false,1);
		}
		if (time == 70) {
			App->enemies->AddEnemy(ENEMY_TYPES::SMALLGREEN, position.x + 8, position.y,false,2);
		}
		if (time == 80) {
			App->enemies->AddEnemy(ENEMY_TYPES::SMALLGREEN, position.x + 8, position.y,false,3);
		}
		if (time == 90) {
			App->enemies->AddEnemy(ENEMY_TYPES::SMALLGREEN, position.x + 8, position.y,false,4);
		}
	}


}

void Enemy_ShipTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}