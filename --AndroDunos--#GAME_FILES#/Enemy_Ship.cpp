#include "Application.h"
#include "Enemy_Ship.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"

#include <math.h>  

Enemy_Ship::Enemy_Ship(int x, int y) : Enemy(x, y)
{
	type = SHIP;


	fly.PushBack({ 1130,20,22,14 });
	fly.PushBack({ 1160,21,22,12 });
	fly.PushBack({ 1190,21,22,14 });
	fly.PushBack({ 1220,20,22,17 });
	fly.PushBack({ 1250,17,22,22 });
	fly.PushBack({ 1280,20,22,17 });
	fly.PushBack({ 1310,22,22,14 });
	fly.PushBack({ 1340,22,22,14 });
	fly.PushBack({ 1370,20,22,14 });
	fly.PushBack({ 1400,18,22,17 });
	fly.PushBack({ 1430,17,22,22 });
	fly.PushBack({ 1460,18,22,17 });


	fly.speed = 0.2f;

	animation = &fly;

	path.PushBack({ 1.2f, 1.2f }, 70);
	path.PushBack({ 1.2f, 0.5f }, 28);
	path.PushBack({ 1.2f, 0.0f }, 10);
	path.PushBack({ 1.2f,-0.5f }, 28);
	path.PushBack({ 1.2f,-1.2f }, 500);
	collider = App->collision->AddCollider({ 0, 0, 35, 25 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}
void Enemy_Ship::Move()
{
	position = original_pos + path.GetCurrentSpeed();

	if (fly.SeeCurrentFrame() == 19 && now) {
		x = App->player->position.x - position.x;
		y = App->player->position.y - position.y;
		m = sqrt((x*x) + (y*y));
		x = x / m;
		y = y / m;
		App->particles->followlaser.speed.x = x * 1.8f;
		App->particles->followlaser.speed.y = y * 1.8f;
		App->particles->AddParticle(App->particles->followlaser, position.x, position.y + 8, COLLIDER_ENEMY_SHOT);
		now = false;
	}
}
void Enemy_Ship::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}
