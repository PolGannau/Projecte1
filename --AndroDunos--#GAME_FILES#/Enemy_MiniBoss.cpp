#include "Application.h"
#include "Enemy_MiniBoss.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"

#include <math.h>  



Enemy_MiniBoss::Enemy_MiniBoss(int x, int y) : Enemy(x, y)
{
	type = MINIBOSS;

	fly.PushBack({ 0, 470, 30, 19 });


	fly.loop = false;


	fly.speed = 0.1f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 23, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_MiniBoss::Move()
{
	position = original_pos + path.GetCurrentSpeed();

}

void Enemy_MiniBoss::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}