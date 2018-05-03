#include "Application.h"
#include "Enemy_ShipGreen.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_ShipGreen::Enemy_ShipGreen(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 368,0,23,22 });
	fly.PushBack({ 340, 2, 23, 20 });
	fly.PushBack({ 311, 4, 23, 17 });
	fly.PushBack({ 340, 2, 23, 20 });
	fly.PushBack({ 396,1,23,19 });
	fly.speed = 0.1f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 23, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_ShipGreen::Move()
{
	position.x -= 1;
}

void Enemy_ShipGreen::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}