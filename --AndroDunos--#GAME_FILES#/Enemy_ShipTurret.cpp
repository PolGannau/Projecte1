#include "Application.h"
#include "Enemy_ShipTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_ShipTurret::Enemy_ShipTurret(int x, int y) : Enemy(x, y)
{
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

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 32, 24}, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_ShipTurret::Move()
{
	position.x -= 1;



}

void Enemy_ShipTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}