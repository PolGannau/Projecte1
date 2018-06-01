#include "Application.h"
#include "Enemy_HandShip.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"

#include <math.h>  



Enemy_HandShip::Enemy_HandShip(int x, int y) : Enemy(x, y)
{
	type = HANDSHIP;

	fly.PushBack({ 0, 470, 30, 19 }); 
	fly.PushBack({ 35, 470, 30, 19 });
	fly.PushBack({ 70, 470, 30, 19 });
	fly.PushBack({ 105, 470, 30, 19 });
	fly.PushBack({ 140, 470, 30, 19 });
	fly.PushBack({ 0, 494, 30, 19 });
	fly.PushBack({ 35, 494, 30, 19 });
	fly.PushBack({ 70, 494, 30, 19 });
	fly.PushBack({ 105, 494, 30, 19 });
	fly.PushBack({ 140, 494, 30, 19 });
	fly.PushBack({ 0, 518, 30, 19 });
	fly.PushBack({ 35, 518, 30, 19 });
	fly.PushBack({ 70, 518, 30, 19 });
	fly.PushBack({ 105, 518, 30, 19 });
	fly.PushBack({ 140, 518, 30, 19 });
	fly.PushBack({ 0, 542, 30, 19 });
	fly.PushBack({ 35, 542, 30, 19 });
	fly.PushBack({ 70, 542, 30, 19 });
	fly.PushBack({ 105, 542, 30, 19 }); //aqui ha de disparar
	fly.PushBack({ 105, 542, 30, 19 });
	fly.PushBack({ 140, 542, 30, 19 });
	fly.PushBack({ 0, 565, 30, 19 });
	fly.PushBack({ 35, 565, 30, 19 });
	fly.PushBack({ 70, 565, 30, 19 });
	fly.PushBack({ 105, 565, 30, 19 });
	fly.PushBack({ 140, 565, 30, 19 });

	fly.loop = false;


	fly.speed = 0.1f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 23, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_HandShip::Move()
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
		App->particles->AddParticle(App->particles->followlaser, position.x , position.y + 8, COLLIDER_ENEMY_SHOT);
		now = false;
	}
}

void Enemy_HandShip::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}