#include "Application.h"
#include "Enemy_ShipGreen.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"

#include <math.h>  



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

	shot++;
	if (shot == 60) {
		x = App->player->position.x - position.x;
		y = App->player->position.y - position.y;
		m = sqrt((x*x) + (y*y));
		x = x / m;
		y = y / m;
		App->particles->followlaser.speed.x = x * 1.8f;
		App->particles->followlaser.speed.y = y * 1.8f;
		App->particles->AddParticle(App->particles->followlaser, position.x + 8, position.y + 15, COLLIDER_ENEMY_SHOT);
	}
}

void Enemy_ShipGreen::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}