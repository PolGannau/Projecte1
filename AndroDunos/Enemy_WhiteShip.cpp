#include "Application.h"
#include "Enemy_WhiteShip.h"
#include "ModuleCollision.h"

Enemy_WhiteShip::Enemy_WhiteShip(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 1,0,31,27 });
	fly.PushBack({ 32, 0, 31, 27 });

	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 31, 27 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_WhiteShip::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}

	position.y = int(float(original_y) + (25.0f * sinf(wave)));
	position.x -= 1;
}