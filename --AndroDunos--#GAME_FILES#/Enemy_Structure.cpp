#include "Application.h"
#include "Enemy_Structure.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

Enemy_Structure::Enemy_Structure(int x, int y, bool z) : Enemy(x, y)
{
	type = STRUCTURE;
	if (z) {
		fly.PushBack({ 457,398,48,136 });
		animation = &fly;
		up = z;
	}
	else {
		fly.PushBack({ 517,398,48,136 });
		animation = &fly;
	}

	collider = App->collision->AddCollider({ 0, 0, 48, 136 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
}

void Enemy_Structure::Move()
{

	



}

void Enemy_Structure::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}