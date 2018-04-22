#include "Application.h"
#include "Enemy_ShipUpDown.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"


Enemy_ShipUpDown::Enemy_ShipUpDown(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 65,3,18,12 });
	fly.PushBack({ 84, 3, 18, 12 });
	fly.PushBack({ 104, 3, 18, 13 });
	fly.PushBack({ 124, 1, 18, 17 });
	fly.PushBack({ 144, 0, 18, 20 });
	fly.PushBack({ 166, 0, 19, 22 });
	fly.PushBack({ 65, 22, 18, 20 });
	fly.PushBack({ 87, 23, 18, 17 });
	fly.PushBack({ 109, 24, 18, 17 });
	fly.PushBack({ 132, 26, 19, 13 });
	fly.PushBack({ 157, 27, 18, 12 });

	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 18, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}


void Enemy_ShipUpDown::Move()
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

void Enemy_ShipUpDown::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion2, position.x, position.y);
}