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

	fly.speed = 0.08f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 23, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_HandShip::Move()
{
	position.x -= 1;

}

void Enemy_HandShip::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}