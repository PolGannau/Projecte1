#include "Application.h"
#include "Enemy_ShipTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_ShipTurret::Enemy_ShipTurret(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 1,54,32,24 });
	fly.PushBack({ 48, 55, 31, 23 });
	fly.PushBack({ 92, 56, 31, 22 });
	fly.PushBack({ 0, 83, 31, 21 });
	fly.PushBack({ 47,85,31,19 });
	fly.PushBack({ 91,87,31,17 });
	fly.PushBack({ 0,115,32,15 });
	fly.loop = false;
	fly.speed = 0.1f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 23, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_ShipTurret::Move()
{
	position.x -= 1;
}

void Enemy_ShipTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}