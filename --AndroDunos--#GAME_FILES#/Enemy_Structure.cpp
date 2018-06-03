#include "Application.h"
#include "Enemy_Structure.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

Enemy_Structure::Enemy_Structure(int x, int y) : Enemy(x, y)
{
	type = STRUCTURE;

	fly.PushBack({ 427,0,28,23 });
	fly.PushBack({ 456, 0, 28, 23 });
	fly.PushBack({ 485, 0, 28, 23 });
	fly.speed = 0.2f;

	idle.PushBack({ 427,0,28,23 });
	animation = &idle;
	collider = App->collision->AddCollider({ 0, 0, 28, 23 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
}

void Enemy_Structure::Move()
{

	if (App->player->position.x < position.x) {
		animation = &idle;
		position.x -= 1;

	}
	if (App->player->position.x >= position.x) {
		animation = &fly;
		position.x += 2.0f;
	}



}

void Enemy_Structure::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}