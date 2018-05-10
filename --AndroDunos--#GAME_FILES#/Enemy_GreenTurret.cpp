#include "Application.h"
#include "Enemy_GreenTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_GreenTurret::Enemy_GreenTurret(int x, int y, bool z) : Enemy(x, y)
{
	type = GREENTURRET;
	if (z) {
		lookingleft.PushBack({ 423,59,51,29 });
		lookingleft.PushBack({ 423,59,51,29 });
		lookingleft.PushBack({ 423,59,51,29 });
		lookingleft.PushBack({ 423,59,51,29 });
		lookingleft.PushBack({ 423,125,51,29 });
		lookingleft.PushBack({ 494,95,51,29 });
		lookingleft.PushBack({ 558,127,51,29 });
		lookingleft.PushBack({ 648,63,51,29 });
		lookingleft.PushBack({ 648,129,51,29 });
		lookingleft.PushBack({ 648,63,51,29 });
		lookingleft.PushBack({ 558,127,51,29 });
		lookingleft.PushBack({ 494,95,51,29 });
		lookingleft.PushBack({ 423,125,51,29 });
		lookingleft.speed = 0.15f;
		animation = &lookingleft;
		lefttt = true;
	}
	else {
		lookingright.PushBack({ 974,17,44,29 });
		lookingright.PushBack({ 974,17,44,29 });
		lookingright.PushBack({ 974,17,44,29 });
		lookingright.PushBack({ 974,17,44,29 });
		lookingright.PushBack({ 974,83,46,29 });
		lookingright.PushBack({ 903,53,47,29 });
		lookingright.PushBack({ 839,85,49,29 });
		lookingright.PushBack({ 749,21,49,29 });
		lookingright.PushBack({ 749,87,51,29 });
		lookingright.PushBack({ 749,21,49,29 });
		lookingright.PushBack({ 839,85,49,29 });
		lookingright.PushBack({ 903,53,47,29 });
		lookingright.PushBack({ 974,83,46,29 });
		lookingright.speed = 0.15f;
		animation = &lookingright;
	}
	
	collider = App->collision->AddCollider({ 0, 0, 44, 29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}
void Enemy_GreenTurret::Move()
{
	if (lefttt) {
		if (lookingleft.SeeCurrentFrame() == 8) {
			bullet++;
			if (bullet == 6) {
				App->particles->AddParticle(App->particles->laserenemygreenturret, position.x + 3, position.y + 7.5, COLLIDER_ENEMY_SHOT);
			}
		}
		if (lookingleft.SeeCurrentFrame() == 9) {
			bullet = 0;
		}
		if (hit) {
			hit = false;
			App->particles->AddParticle(App->particles->bullettouchgreenturret, position.x + 5, position.y);
		}
	}
	else {
		if (lookingright.SeeCurrentFrame() == 8) {
			bullet++;
			if (bullet == 6) {
				App->particles->AddParticle(App->particles->laserenemygreenturret2, position.x+40, position.y + 7.5, COLLIDER_ENEMY_SHOT);
			}
		}
		if (lookingright.SeeCurrentFrame() == 9) {
			bullet = 0;
		}
		if (hit) {
			hit = false;
			App->particles->AddParticle(App->particles->bullettouchgreenturret2, position.x - 2, position.y);
		}
	}
}
void Enemy_GreenTurret::OnCollision(Collider* collider) {
	if (lefttt) {
		App->particles->AddParticle(App->particles->GreenTurretExplosion, position.x + 5, position.y);
	}
	else {
		App->particles->AddParticle(App->particles->GreenTurretExplosion2, position.x - 5, position.y);
	}
}





