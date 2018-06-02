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


	fly.PushBack({ 1087,3,35,22 });
	fly.PushBack({ 1127,6,35,19 });
	fly.PushBack({ 1170,5,35,20 });
	fly.PushBack({ 1213,3,34,27 });
	fly.PushBack({ 1249,0,33,35 });
	fly.PushBack({ 1288,3,35,27 });
	fly.PushBack({ 1329,6,35,23 });
	fly.PushBack({ 1370,10,35,19 });
	fly.PushBack({ 1410,5,34,22 });
	fly.PushBack({ 1447,2,35,27 });
	fly.PushBack({ 1485,0,35,35 });
	fly.PushBack({ 1526,5,35,27 });


	fly.speed = 0.2f;

	animation = &fly;

	path.PushBack({ 1.2f, 1.2f }, 50);
	path.PushBack({ 1.2f, 0.5f }, 20);
	path.PushBack({ 1.2f, 0.0f }, 5);
	path.PushBack({ 1.2f,-0.5f }, 20);
	path.PushBack({ 1.2f,-1.2f }, 500);
	collider = App->collision->AddCollider({ 0, 0, 35, 25 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
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
