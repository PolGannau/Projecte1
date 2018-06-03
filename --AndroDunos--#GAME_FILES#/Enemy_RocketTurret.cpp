#include "Application.h"
#include "Enemy_RocketTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_RocketTurret::Enemy_RocketTurret(int x, int y) : Enemy(x, y)
{
	type = ROCKETTURRET;

	fly.PushBack({ 309,88,16,12 });


	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 16, 12 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_RocketTurret::Move()
{
	++time;
	if (time == 50) {
		App->particles->AddParticle(App->particles->Rocket, position.x + 2, position.y - 17);
	}
}

void Enemy_RocketTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}