#include "Application.h"
#include "Enemy_ShipGreen.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_ShipGreen::Enemy_ShipGreen(int x, int y) : Enemy(x, y)
{
	type = SHIPGREEN;

	fly.PushBack({ 311, 4, 23, 17 }); // 1
	fly.PushBack({ 340, 2, 23, 20 }); // 2
	fly.PushBack({ 368,0,23,22 }); // 3
	fly.PushBack({ 396,1,23,19 }); // 4
	fly.speed = 0.08f;

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