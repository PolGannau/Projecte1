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

	fly.PushBack({ 965, 290, 79, 176 });



	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 23, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_MiniBoss::Move()
{
	

}

void Enemy_MiniBoss::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}