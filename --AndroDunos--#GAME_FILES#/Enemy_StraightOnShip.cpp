#include "Application.h"
#include "Enemy_StraightOnShip.h"
#include "ModuleCollision.h"

Enemy_StraightOnShip::Enemy_StraightOnShip(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 187,1,29,13 });
	fly.PushBack({ 217, 0, 29, 16 });
	fly.PushBack({ 247, 1, 29, 17 });
	fly.PushBack({ 217, 0, 29, 16 });
	fly.PushBack({ 277, 1, 29, 14 });

	fly.speed = 0.05f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 29, 16 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_StraightOnShip::Move()
{
	position.x -= 1;

}