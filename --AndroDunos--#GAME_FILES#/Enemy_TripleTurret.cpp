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
	fly.speed = 0.2f;

	idle.PushBack({ 427,0,28,23 });
	animation = &idle;
	collider = App->collision->AddCollider({ 0, 0, 28, 23 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
}

void Enemy_TripleTurret::Move()
{
	++time;
	mov += 0.5f;
	mov3 += 0.34f;
	if (mov == 1.0f) {
		if (mov2 == false) {
			position.x -= 2;
		}
		if (App->player->position.x >= position.x && mov2) {
			animation = &fly;
			position.x += 3;
			anim = false;
			shot = true;
		}
		mov = 0;
	}
	if (mov3 >= 1.0f) {
		if (App->player->position.x < position.x && mov2 && anim) {
			animation = &idle;
			position.x -= 1;
		}
		else if (App->player->position.x < position.x && mov2 && anim == false) {
			animation = &fly;
			position.x -= 1;
		}
	}
		if (time == 600) {
			mov2 = false;
		}
		if (shot) {
			++shott;
		}
		if (shott == 100) {
			App->particles->AddParticle(App->particles->triple, position.x + 7, position.y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->tripled, position.x + 15, position.y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->tripleu, position.x, position.y, COLLIDER_ENEMY_SHOT);
			shott = 0;
		}
		mov3 = 0;

	}


		
	




void Enemy_TripleTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}