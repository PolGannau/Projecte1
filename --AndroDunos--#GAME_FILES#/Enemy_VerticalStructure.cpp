#include "Application.h"
#include "Enemy_VerticalStructure.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_VerticalStructure::Enemy_VerticalStructure(int x, int y, bool z) : Enemy(x, y)
{
	type = VERTICALSTRUCTURE;

	if (z) {
		fly.PushBack({ 0,184,48,136 });
		fly.PushBack({ 61,184,48,136 });
		fly.PushBack({ 132,184,48,136 });
		fly.PushBack({ 193,184,48,136 });
		fly.speed = 0.05f;
		animation = &fly;
		up = true;
	}
	else {
		fly2.PushBack({ 283,189,48,136 });
		fly2.PushBack({ 344,189,48,136 });
		fly2.PushBack({ 415,189,48,136 });
		fly2.PushBack({ 476,189,48,136 });
		fly2.speed = 0.05f;
		fly2.speed = 0.05f;
		animation = &fly2;
	}
	 
	
	collider = App->collision->AddCollider({ 0, 0, 48, 136 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
}

void Enemy_VerticalStructure::Move()
{
	if (up) {
		if (stop == false) {
			position.y -= 1;
		}

		if (position.y == 90) {
			stop = true;
		}
		if (stop) {
			position.y = position.y;
		}
		if (hit && stop==false) {
			hit = false;
			App->particles->AddParticle(App->particles->Structuretouch, position.x , position.y);
		}
		if (stop && hit) {
			hit = false;
			App->particles->AddParticle(App->particles->Structuretouch1, position.x, position.y);
		}
	}
	else {
		if (stop == false) {
			position.y += 1;
		}

		if (position.y == 0) {
			stop = true;
		}
		if (stop) {
			position.y = position.y;
		}
		if (hit && stop == false) {
			hit = false;
			App->particles->AddParticle(App->particles->Structuretouch2, position.x, position.y);
		}
		if (stop && hit) {
			hit = false;
			App->particles->AddParticle(App->particles->Structuretouch21, position.x, position.y);
		}
	}
}

void Enemy_VerticalStructure::OnCollision(Collider* collider) {
	if (up) {
		App->particles->AddParticle(App->particles->Structuredead, position.x, position.y + 10);
	}
	else {
		App->particles->AddParticle(App->particles->Structuredead2, position.x, position.y);
	}
}