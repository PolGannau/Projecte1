#include "Application.h"
#include "Enemy_TripleTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

Enemy_TripleTurret::Enemy_TripleTurret(int x, int y) : Enemy(x, y)
{
	type = TRIPLETURRET;

	fly.PushBack({ 427,0,28,23 });
	fly.PushBack({ 456, 0, 28, 23 });
	fly.PushBack({ 485, 0, 28, 23 });
	fly.speed = 0.1f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 28, 23 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
}

void Enemy_TripleTurret::Move()
{
	position.x -= 1;
	change++;
	/*if (change == 5) {
		fly.Sprite({ 427,0,28,23 });
	}
	else if (change == 10) {
		fly.Sprite({ 456, 0, 28, 23 });
	}
	else if (change == 15) {
		change = 0;
		fly.Sprite({ 485, 0, 28, 23 });
	}*/


}

void Enemy_TripleTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}